# Giorno 2 — Modulo C++ (2h): Funzioni avanzate, `std::string` e `std::vector`

## Obiettivi della sezione

- Sfruttare le funzionalità del C++ sulle funzioni: **overloading**, **parametri di
  default**, **passaggio per riferimento**.
- Usare `std::string` in modo completo.
- Introdurre il primo container della STL: `std::vector`.

> Le strutture di controllo (`if`, `for`, `while`, `switch`) in C++ sono identiche
> al C: si dà per acquisito il modulo `giorno2_c_controllo_funzioni.md` e ci si
> concentra sulle novità.

---

## 1. Funzioni in C++: cosa cambia rispetto al C

### Overloading (sovraccarico)

In C++ più funzioni possono avere lo **stesso nome** se differiscono per numero o
tipo di parametri. In C questo è impossibile.

```cpp
#include <iostream>

int somma(int a, int b)        { return a + b; }
double somma(double a, double b) { return a + b; }

int main() {
    std::cout << somma(3, 4) << "\n";       // chiama la versione int
    std::cout << somma(2.5, 1.5) << "\n";   // chiama la versione double
}
```

### Parametri di default

```cpp
#include <iostream>

void saluta(std::string nome = "ospite") {
    std::cout << "Ciao, " << nome << "!\n";
}

int main() {
    saluta();          // Ciao, ospite!
    saluta("Anna");    // Ciao, Anna!
}
```

### Passaggio per riferimento (`&`)

In C, per far modificare una variabile a una funzione servono i puntatori. In C++
esistono i **riferimenti**, più semplici e sicuri.

```cpp
#include <iostream>

void raddoppia(int& x) {   // & = riferimento: NON una copia
    x = x * 2;
}

int main() {
    int n = 5;
    raddoppia(n);
    std::cout << n << "\n";   // 10  →  l'originale è stato modificato!
}
```

> Differenza chiave: `int x` riceve una copia, `int& x` lavora direttamente sulla
> variabile del chiamante. Questo confronto va fatto esplicito in aula perché
> anticipa il tema "riferimenti vs puntatori" del Giorno 3.

---

## 2. `std::string` in profondità

```cpp
#include <iostream>
#include <string>

int main() {
    std::string s = "Programmazione";

    std::cout << s.length() << "\n";        // 14
    std::cout << s.substr(0, 5) << "\n";    // "Progr"
    std::cout << s[0] << "\n";              // 'P'

    s += " C++";                            // concatenazione semplice
    std::cout << s << "\n";

    if (s.find("C++") != std::string::npos) {
        std::cout << "Contiene C++\n";
    }
    return 0;
}
```

Metodi utili: `length()/size()`, `substr()`, `find()`, `append()`, `empty()`,
`at()`. Tutta la memoria è gestita dall'oggetto: nessun `'\0'` da gestire a mano,
nessun rischio di sforare l'array.

---

## 3. `std::vector`: l'array che cresce

Il `std::vector` è un array **dinamico**: può crescere e restringersi a runtime e
conosce sempre la propria dimensione.

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> numeri = {10, 20, 30};

    numeri.push_back(40);          // aggiunge in coda
    numeri.push_back(50);

    std::cout << "Dimensione: " << numeri.size() << "\n";

    // Ciclo classico con indice
    for (size_t i = 0; i < numeri.size(); i++) {
        std::cout << numeri[i] << " ";
    }
    std::cout << "\n";

    // Ciclo "range-based" (moderno e leggibile)
    for (int valore : numeri) {
        std::cout << valore << " ";
    }
    std::cout << "\n";
    return 0;
}
```

**Vantaggi rispetto all'array C:**

| Array C | `std::vector` |
|---------|---------------|
| dimensione fissa | dimensione dinamica |
| nessun controllo sui limiti | `.at()` controlla i limiti |
| non conosce la propria lunghezza | `.size()` |
| memoria a carico del programmatore | gestita automaticamente |

> Il **ciclo range-based** (`for (int v : numeri)`) è una comodità del C++ che il C
> non possiede: vale la pena mostrarlo affiancato al ciclo con indice.

---

## 4. Mettere insieme i pezzi

```cpp
#include <iostream>
#include <vector>
#include <string>

// passaggio per riferimento costante: efficiente e sicuro (non copia, non modifica)
double media(const std::vector<double>& valori) {
    double somma = 0;
    for (double v : valori) somma += v;
    return valori.empty() ? 0 : somma / valori.size();
}

int main() {
    std::vector<double> voti = {28, 30, 25, 27};
    std::cout << "Media: " << media(voti) << "\n";
    return 0;
}
```

> `const std::vector<double>&` è un pattern fondamentale del C++: passa il vector
> **per riferimento** (niente copia, veloce) ma **costante** (la funzione non può
> modificarlo). Da sottolineare in aula.

---

## Esercizi — Giorno 2, C++

> Soluzioni in `esercizi_soluzioni.md` (sezione *G2-C++*).

**Esercizio G2-CPP-1 — Overloading**
Scrivi due funzioni `area` sovraccaricate: una per il quadrato (un parametro) e una
per il rettangolo (due parametri).

**Esercizio G2-CPP-2 — Scambio con riferimenti**
Scrivi una funzione `void scambia(int& a, int& b)` che scambia due valori usando i
riferimenti. Confrontala con la versione C a puntatori (anticipo Giorno 3).

**Esercizio G2-CPP-3 — Gestione lista**
Crea un `std::vector<std::string>` di nomi, aggiungine alcuni con `push_back` e
stampali con un ciclo range-based.

**Esercizio G2-CPP-4 — Massimo del vector**
Scrivi una funzione che riceva un `const std::vector<int>&` e restituisca il valore
massimo.

**Esercizio G2-CPP-5 — Manipolazione stringhe**
Leggi una parola e stampala al contrario (suggerimento: scorri la `std::string`
dall'ultimo carattere al primo).

**Esercizio G2-CPP-6 (sfida) — Filtro pari**
Dato un `std::vector<int>`, costruisci un nuovo vector contenente solo i numeri pari
e stampalo.
