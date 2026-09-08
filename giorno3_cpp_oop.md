# Giorno 3 — Modulo C++ (2h): Programmazione a oggetti, classi e RAII

## Obiettivi della sezione

- Capire i principi della **programmazione orientata agli oggetti (OOP)**.
- Definire **classi** con attributi e metodi.
- Usare **costruttori**, **distruttori** e i livelli di accesso.
- Comprendere il principio **RAII**, cuore della gestione della memoria in C++.

> Collegamento: il Giorno 3 di C ha introdotto le `struct` e la gestione manuale
> della memoria. Qui vediamo come il C++ trasforma quei concetti in qualcosa di
> più sicuro e organizzato.

---

## 1. Dalla struct alla classe (teoria)

La programmazione a oggetti organizza il software intorno a **oggetti**, che
uniscono **dati** (attributi) e **comportamenti** (metodi). I quattro pilastri:

1. **Incapsulamento** — nascondere i dettagli interni ed esporre un'interfaccia.
2. **Astrazione** — ragionare per concetti ("un'auto") anziché per dettagli.
3. **Ereditarietà** — creare nuove classi a partire da classi esistenti (Giorno 4).
4. **Polimorfismo** — uno stesso comando, comportamenti diversi (Giorno 4).

Una **classe** è il progetto; un **oggetto** è un esemplare concreto costruito da
quel progetto.

---

## 2. La prima classe

```cpp
#include <iostream>
#include <string>

class Persona {
private:                       // accessibili solo dall'interno della classe
    std::string nome;
    int eta;

public:                        // interfaccia visibile dall'esterno
    // Costruttore: chiamato alla creazione dell'oggetto
    Persona(std::string n, int e) {
        nome = n;
        eta = e;
    }

    // Metodo
    void presentati() {
        std::cout << "Mi chiamo " << nome << " e ho " << eta << " anni.\n";
    }

    // Getter (incapsulamento: accesso controllato ai dati)
    int getEta() {
        return eta;
    }
};

int main() {
    Persona p("Maria", 30);    // costruisco un oggetto
    p.presentati();
    std::cout << "Eta: " << p.getEta() << "\n";
    // p.eta = 99;  // ERRORE: 'eta' e' private
    return 0;
}
```

**Differenze chiave rispetto alla struct C:**

| `struct` (C) | `class` (C++) |
|--------------|---------------|
| solo dati | dati + metodi |
| tutto pubblico | `private`/`public`/`protected` |
| nessun costruttore | costruttori e distruttori |
| nessun incapsulamento | incapsulamento integrato |

> Nota: in C++ anche `struct` può avere metodi; l'unica differenza tecnica con
> `class` è che `struct` ha i membri `public` di default. Per didattica si usa
> `class` per gli oggetti e `struct` per i semplici contenitori di dati.

---

## 3. Costruttori e distruttori

- **Costruttore**: inizializza l'oggetto alla sua creazione.
- **Distruttore** (`~NomeClasse`): viene chiamato automaticamente quando l'oggetto
  viene distrutto (es. esce dallo scope). È il posto giusto per liberare risorse.

```cpp
#include <iostream>

class Risorsa {
public:
    Risorsa()  { std::cout << "Risorsa acquisita\n"; }   // costruttore
    ~Risorsa() { std::cout << "Risorsa rilasciata\n"; }  // distruttore
};

int main() {
    std::cout << "Inizio\n";
    {
        Risorsa r;                 // qui parte il costruttore
        std::cout << "Uso la risorsa\n";
    }                              // qui, uscendo dal blocco, parte il distruttore
    std::cout << "Fine\n";
    return 0;
}
```

Output:

```
Inizio
Risorsa acquisita
Uso la risorsa
Risorsa rilasciata
Fine
```

### Lista di inizializzazione (forma idiomatica)

Nel costruttore visto finora i membri vengono valorizzati nel **corpo**, con un
assegnamento:

```cpp
class Punto {
private:
    int x, y;
public:
    Punto(int px, int py) {
        x = px;   // ASSEGNAMENTO: x e y esistono già (con valore indeterminato),
        y = py;   // poi vengono sovrascritti
    }
};
```

La **lista di inizializzazione** valorizza i membri PRIMA che il corpo del
costruttore venga eseguito, con una sintassi dedicata dopo i due punti:

```cpp
class Punto {
private:
    int x, y;
public:
    Punto(int px, int py) : x(px), y(py) {}   // INIZIALIZZAZIONE diretta
    void stampa() { std::cout << "(" << x << ", " << y << ")\n"; }
};
```

Per `int` la differenza è invisibile a runtime, ma è comunque la forma da
insegnare come abitudine, per tre motivi.

**1. Efficienza con i membri-oggetto.** Se un membro è un oggetto (`std::string`,
`std::vector`, un'altra classe...), assegnarlo nel corpo significa costruirlo
due volte: prima con il costruttore di default, poi sovrascritto con
`operator=`. La lista di inizializzazione lo costruisce una volta sola, subito
con il valore giusto.

```cpp
class Esempio {
    std::string testo;
public:
    // Meno efficiente: std::string() di default, poi operator=(t)
    Esempio(std::string t) { testo = t; }

    // Efficiente: costruito direttamente col valore giusto
    Esempio(std::string t) : testo(t) {}
};
```

**2. È l'unico modo possibile per alcuni membri.** Un membro `const`, un
membro **riferimento**, oppure un oggetto la cui classe non ha un costruttore
di default, non possono essere assegnati nel corpo: devono ricevere il loro
valore nell'istante in cui vengono creati.

```cpp
class Configurazione {
private:
    const int id;      // const: si inizializza, non si può più assegnare
    int& contatore;     // riferimento: deve essere legato subito a qualcosa

public:
    Configurazione(int i, int& c) : id(i), contatore(c) {}
    // Configurazione(int i, int& c) { id = i; contatore = c; }  // ERRORE: non compila
};
```

**3. Attenzione all'ordine: conta la dichiarazione, non la lista.** I membri
vengono inizializzati sempre nell'**ordine in cui compaiono nella classe**,
indipendentemente dall'ordine scritto nella lista. Se la lista non rispetta
quell'ordine, il compilatore avvisa (warning attivo già con `-Wall`) — ed è un
avviso da prendere sul serio:

```cpp
class Rischio {
    int b;   // dichiarato per primo
    int a;   // dichiarato per secondo

public:
    // Sembra "prima a, poi b copiato da a", ma essendo b dichiarato prima di a,
    // viene inizializzato PRIMA: b(a) legge un 'a' non ancora esistente.
    Rischio(int val) : a(val), b(a) {}
    // g++ -Wall segnala: "Rischio::a" is used uninitialized
    // Risultato osservato: a=10, b=<valore indeterminato/spazzatura>
};
```

> **Regola pratica da dare in aula**: usare sempre la lista di inizializzazione
> ed elencare i membri nello **stesso ordine** in cui sono dichiarati nella
> classe. Se il compilatore avvisa con `-Wreorder`, è quasi sempre un bug reale,
> non un falso allarme.

---

## 4. RAII: il principio fondamentale del C++

**RAII** = *Resource Acquisition Is Initialization*. L'idea: legare la vita di una
risorsa (memoria, file, connessione) alla vita di un oggetto. La risorsa viene
acquisita nel **costruttore** e rilasciata nel **distruttore**, automaticamente.

Confronto diretto con il C del Giorno 3:

```c
/* In C, gestione manuale: facile dimenticare free() */
int *dati = malloc(100 * sizeof(int));
/* ... uso ... */
free(dati);   // se dimentico questa riga → memory leak
```

```cpp
// In C++, std::vector applica RAII: la memoria si libera DA SOLA
{
    std::vector<int> dati(100);
    // ... uso ...
}   // qui il distruttore di 'dati' libera tutto automaticamente
```

> Messaggio centrale per gli studenti: in C++ moderno **non si scrive quasi mai
> `new`/`delete` a mano**. Si usano i container della STL e gli *smart pointer*,
> che applicano RAII al posto nostro. Questo elimina intere categorie di bug
> presenti nel C.

---

## 5. Mini-esempio completo: un conto bancario

```cpp
#include <iostream>
#include <string>

class ContoBancario {
private:
    std::string titolare;
    double saldo;

public:
    ContoBancario(std::string nome, double iniziale)
        : titolare(nome), saldo(iniziale) {}

    void deposita(double importo) {
        if (importo > 0) saldo += importo;
    }

    bool preleva(double importo) {
        if (importo > 0 && importo <= saldo) {
            saldo -= importo;
            return true;
        }
        return false;   // fondi insufficienti
    }

    void stampaSaldo() {
        std::cout << titolare << ": " << saldo << " EUR\n";
    }
};

int main() {
    ContoBancario c("Giulia", 100.0);
    c.deposita(50);
    c.preleva(30);
    c.stampaSaldo();      // Giulia: 120 EUR
    return 0;
}
```

L'incapsulamento garantisce che il `saldo` possa cambiare **solo** attraverso
`deposita` e `preleva`: non si può assegnare un valore arbitrario dall'esterno.

---

## Esercizi — Giorno 3, C++

> Soluzioni in `esercizi_soluzioni.md` (sezione *G3-C++*).

**Esercizio G3-CPP-1 — Classe Rettangolo**
Crea una classe `Rettangolo` con attributi privati `base` e `altezza`, un costruttore
e i metodi `area()` e `perimetro()`.

**Esercizio G3-CPP-2 — Da struct a classe**
Riprendi la struct `Persona` del modulo C (G3-C-4/5) e trasformala in una classe C++
con costruttore, metodo `presentati()` e getter.

**Esercizio G3-CPP-3 — Costruttore e distruttore**
Crea una classe `Cronometro` che stampi un messaggio nel costruttore e uno nel
distruttore, per osservare quando vengono chiamati.

**Esercizio G3-CPP-4 — Contatore incapsulato**
Crea una classe `Contatore` con un valore privato e i metodi `incrementa()`,
`decrementa()` e `valore()`. Il valore non deve mai scendere sotto zero.

**Esercizio G3-CPP-5 — Conto bancario esteso**
Estendi `ContoBancario` con uno storico delle operazioni (`std::vector<std::string>`)
e un metodo che lo stampi.

**Esercizio G3-CPP-6 (sfida) — Frazione**
Crea una classe `Frazione` (numeratore/denominatore) con un metodo `somma()` che
restituisca la somma di due frazioni e un metodo `stampa()` che la mostri come
`a/b`.
