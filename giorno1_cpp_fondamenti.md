# Giorno 1 — Modulo C++ (2h): Fondamenti del linguaggio C++

## Obiettivi della sezione

- Capire cos'è il C++ e in che rapporto sta con il C.
- Scrivere il primo programma C++ con `iostream`.
- Usare `std::string`, l'input/output con `cin`/`cout` e i namespace.

> Prerequisito: aver visto il modulo C del Giorno 1. Molti concetti vengono
> richiamati per evidenziare somiglianze e differenze.

---

## 1. Cos'è il C++ (teoria)

Il **C++** è stato creato da **Bjarne Stroustrup** nei primi anni '80, inizialmente
come *"C con le classi"*. Nasce per aggiungere al C la **programmazione a oggetti** e
costrutti di più alto livello, **mantenendo le prestazioni** e la compatibilità con
gran parte del codice C.

Caratteristiche principali:

- **Multi-paradigma**: procedurale, a oggetti, generico (template), funzionale.
- **Compilato e ad alte prestazioni**, come il C.
- **Type-safe**: controlli più rigorosi sui tipi rispetto al C.
- **Ricca libreria standard (STL)**: container, algoritmi, stringhe già pronti.

In sintesi: *quasi tutto il codice C valido è anche C++ valido*, ma il C++ offre
strumenti che rendono il codice più sicuro ed espressivo. Le differenze approfondite
sono nel file `teoria_differenze_casi_uso.md`.

---

## 2. Il primo programma C++

```cpp
#include <iostream>   // input/output in stile C++

int main() {
    std::cout << "Ciao, mondo!" << std::endl;
    return 0;
}
```

Compilazione:

```bash
g++ -Wall -Wextra -std=c++17 hello.cpp -o hello
./hello
```

**Confronto diretto con il C:**

| C | C++ |
|---|-----|
| `#include <stdio.h>` | `#include <iostream>` |
| `printf("...\n");` | `std::cout << "..." << std::endl;` |
| stringhe di formato (`%d`) | operatore `<<`, nessun formato da ricordare |

L'operatore `<<` "spinge" i dati verso lo stream di output. Si possono concatenare
più valori:

```cpp
int eta = 30;
std::cout << "Eta: " << eta << " anni" << std::endl;
```

---

## 3. I namespace e `std`

In C++ la libreria standard vive nel **namespace `std`**. Per questo scriviamo
`std::cout`, `std::string`, ecc. Un namespace è un "contenitore di nomi" che evita
collisioni tra librerie diverse.

Si può evitare di ripetere `std::` con:

```cpp
#include <iostream>
using namespace std;   // sconsigliato nei progetti grandi

int main() {
    cout << "Senza std::" << endl;
    return 0;
}
```

> **Buona pratica**: nei file di intestazione e nei progetti reali si evita
> `using namespace std;` perché può causare ambiguità. Per i primi esempi didattici
> è accettabile, ma è bene abituare gli studenti a scrivere `std::`.

---

## 4. Variabili e tipi

I tipi fondamentali sono gli stessi del C (`int`, `double`, `char`, `bool`), ma il
C++ aggiunge strumenti più comodi.

```cpp
#include <iostream>
#include <string>

int main() {
    int eta = 30;
    double altezza = 1.75;
    bool studente = true;
    std::string nome = "Maria";   // tipo stringa nativo, niente array di char!

    std::cout << nome << ", " << eta << " anni\n";
    return 0;
}
```

`std::string` è una delle prime grandi comodità rispetto al C: gestisce la memoria
automaticamente, si concatena con `+` e conosce la propria lunghezza.

```cpp
std::string saluto = "Ciao, " + nome + "!";
std::cout << saluto << " (lunghezza: " << saluto.length() << ")\n";
```

---

## 5. Input dell'utente con `cin`

```cpp
#include <iostream>
#include <string>

int main() {
    std::string nome;
    int eta;

    std::cout << "Come ti chiami? ";
    std::cin >> nome;            // legge una parola
    std::cout << "Quanti anni hai? ";
    std::cin >> eta;

    std::cout << "Ciao " << nome << ", tra 10 anni avrai "
              << eta + 10 << " anni.\n";
    return 0;
}
```

> `std::cin >> nome;` si ferma al primo spazio. Per leggere un'intera riga
> (nome e cognome) si usa `std::getline(std::cin, nome);`. È un buon spunto di
> discussione in aula.

---

## 6. Sicurezza dei tipi: una differenza già visibile

In C si poteva scrivere codice ambiguo che il compilatore accettava silenziosamente.
Il C++ è più severo e questo *aiuta* il principiante a trovare gli errori prima.

```cpp
// In C++ è errore di compilazione assegnare un puntatore a un tipo incompatibile
// senza cast esplicito. Questo rigore previene molti bug.
```

---

## Esercizi — Giorno 1, C++

> Le soluzioni si trovano in `esercizi_soluzioni.md` (sezione *G1-C++*).

**Esercizio G1-CPP-1 — Presentazione**
Chiedi all'utente nome ed età con `cin` e stampa una frase di presentazione
completa usando `cout`.

**Esercizio G1-CPP-2 — Concatenazione stringhe**
Chiedi nome e cognome separatamente e costruisci una `std::string` "Cognome Nome"
stampando anche la lunghezza totale.

**Esercizio G1-CPP-3 — Calcolatrice interattiva**
Leggi due numeri `double` e stampa somma, differenza, prodotto e quoziente, ognuno
su una riga.

**Esercizio G1-CPP-4 — Riscrivere in C++**
Prendi la soluzione dell'esercizio G1-C-3 (Celsius → Fahrenheit) e riscrivila in
C++ usando `cin`/`cout`. Discuti in aula quali parti sono cambiate.

**Esercizio G1-CPP-5 (sfida) — Riga intera**
Usa `std::getline` per leggere una frase completa inserita dall'utente e stampala
preceduta dal numero di caratteri che contiene.
