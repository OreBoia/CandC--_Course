# Giorno 4 — Modulo C++ (2h): STL, template, ereditarietà e cenni di Objective-C / Objective-C++

## Obiettivi della sezione

- Conoscere la **STL** (container e algoritmi pronti all'uso).
- Capire l'idea dei **template** (programmazione generica).
- Vedere **ereditarietà** e **polimorfismo** in pratica.
- Introdurre **Objective-C** e **Objective-C++** a livello di base.

---

## 1. La Standard Template Library (STL)

La STL è la libreria standard del C++: offre strutture dati e algoritmi
già pronti, efficienti e testati. I tre pilastri sono **container**, **iteratori**
e **algoritmi**.

### Container più comuni

| Container | A cosa serve |
|-----------|--------------|
| `std::vector` | array dinamico (già visto al Giorno 2) |
| `std::string` | stringhe (già visto al Giorno 1) |
| `std::map` | coppie chiave→valore |
| `std::set` | insieme di elementi unici |

### Esempio: `std::map`

```cpp
#include <iostream>
#include <map>
#include <string>

int main() {
    std::map<std::string, int> eta;
    eta["Anna"] = 30;
    eta["Marco"] = 25;

    std::cout << "Anna ha " << eta["Anna"] << " anni\n";

    for (const auto& coppia : eta) {
        std::cout << coppia.first << " -> " << coppia.second << "\n";
    }
    return 0;
}
```

### Algoritmi della STL

```cpp
#include <iostream>
#include <vector>
#include <algorithm>   // sort, find, max_element...

int main() {
    std::vector<int> v = {5, 2, 8, 1, 9};

    std::sort(v.begin(), v.end());                  // ordina
    auto maxIt = std::max_element(v.begin(), v.end());

    std::cout << "Massimo: " << *maxIt << "\n";
    for (int x : v) std::cout << x << " ";          // 1 2 5 8 9
    std::cout << "\n";
    return 0;
}
```

> Concetto da trasmettere: in C++ raramente si reinventa la ruota. Ordinamento,
> ricerca, somma, conteggio esistono già nella STL ed è quasi sempre meglio usarli.

---

## 2. Template: la programmazione generica

Un **template** permette di scrivere codice che funziona con qualsiasi tipo, senza
duplicarlo. È il meccanismo su cui è costruita tutta la STL.

```cpp
#include <iostream>

template <typename T>
T massimo(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    std::cout << massimo(3, 7) << "\n";          // int
    std::cout << massimo(2.5, 1.2) << "\n";      // double
    std::cout << massimo('a', 'z') << "\n";      // char
    return 0;
}
```

Una sola funzione `massimo` funziona per interi, decimali e caratteri. In C
avremmo dovuto scrivere tre funzioni diverse (o usare macro fragili).

---

## 3. Ereditarietà e polimorfismo

### Ereditarietà

Una classe può **derivare** da un'altra, ereditandone attributi e metodi.

```cpp
#include <iostream>
#include <string>

class Animale {
protected:                         // accessibile alle classi derivate
    std::string nome;
public:
    Animale(std::string n) : nome(n) {}
    void dormi() { std::cout << nome << " dorme.\n"; }
};

class Cane : public Animale {      // Cane "è un" Animale
public:
    Cane(std::string n) : Animale(n) {}
    void abbaia() { std::cout << nome << " abbaia: Bau!\n"; }
};

int main() {
    Cane c("Fido");
    c.dormi();      // metodo ereditato da Animale
    c.abbaia();     // metodo proprio di Cane
    return 0;
}
```

### Polimorfismo con metodi virtuali

Il **polimorfismo** permette di trattare oggetti diversi attraverso un'interfaccia
comune. La parola chiave è `virtual`.

```cpp
#include <iostream>

class Forma {
public:
    virtual double area() = 0;     // metodo virtuale puro → classe astratta
    virtual ~Forma() {}            // distruttore virtuale (buona pratica)
};

class Cerchio : public Forma {
    double raggio;
public:
    Cerchio(double r) : raggio(r) {}
    double area() override { return 3.14159 * raggio * raggio; }
};

class Quadrato : public Forma {
    double lato;
public:
    Quadrato(double l) : lato(l) {}
    double area() override { return lato * lato; }
};

int main() {
    Forma* forme[] = { new Cerchio(2.0), new Quadrato(3.0) };

    for (Forma* f : forme) {
        std::cout << "Area: " << f->area() << "\n";   // chiama la versione giusta!
    }

    for (Forma* f : forme) delete f;   // libero la memoria
    return 0;
}
```

> Stesso comando (`f->area()`), comportamenti diversi a seconda dell'oggetto reale:
> questo è il polimorfismo. È uno dei motivi per cui il C++ è così potente nella
> modellazione di sistemi complessi.

---

## 4. Cenni di Objective-C (solo la base)

> **Contesto da dare agli studenti**: Objective-C è un linguaggio creato negli anni
> '80, diventato il linguaggio principale di Apple (macOS, iOS) fino all'arrivo di
> **Swift** nel 2014. Oggi è in gran parte legacy, ma resta utile conoscerlo per
> capire codebase esistenti. Richiede un compilatore Apple/`clang` e funziona
> tipicamente su macOS.

Objective-C è un **superset del C**: ogni programma C valido è anche Objective-C
valido. Aggiunge la programmazione a oggetti con un modello particolare basato sui
**messaggi**.

```objc
#import <Foundation/Foundation.h>

// Definizione di una classe
@interface Persona : NSObject
@property NSString *nome;
- (void)saluta;            // dichiarazione di metodo
@end

@implementation Persona
- (void)saluta {
    NSLog(@"Ciao, sono %@", self.nome);
}
@end

int main() {
    @autoreleasepool {
        Persona *p = [[Persona alloc] init];   // creazione oggetto
        p.nome = @"Maria";
        [p saluta];                            // INVIO di un messaggio
    }
    return 0;
}
```

**Elementi tipici di Objective-C da far notare:**

- `#import` invece di `#include` (evita inclusioni multiple automaticamente).
- Le stringhe letterali si scrivono `@"testo"` (oggetti `NSString`).
- I metodi si chiamano con la **sintassi a messaggi** tra parentesi quadre:
  `[oggetto metodo]`, anziché `oggetto.metodo()`.
- `@interface` / `@implementation` separano dichiarazione e definizione della classe.

Compilazione (su macOS):

```bash
clang -framework Foundation persona.m -o persona
```

---

## 5. Cenni di Objective-C++ (solo la base)

**Objective-C++** non è un linguaggio nuovo: è una **modalità** che permette di
**mescolare Objective-C e C++ nello stesso file** (estensione `.mm`). Serve quando
si vuole usare codice C++ esistente (ad esempio una libreria) all'interno di
un'app Apple scritta in Objective-C.

```objc
// file: misto.mm
#import <Foundation/Foundation.h>
#include <vector>      // C++ standard library!

int main() {
    @autoreleasepool {
        // codice C++
        std::vector<int> numeri = {1, 2, 3};

        // codice Objective-C, nello stesso file
        for (int n : numeri) {
            NSLog(@"Numero: %d", n);
        }
    }
    return 0;
}
```

**In sintesi:**

- `.m` → Objective-C puro.
- `.mm` → Objective-C++ (Objective-C + C++ insieme).
- Si usa principalmente come "ponte" tra librerie C++ e codice Apple esistente.

> Messaggio per gli studenti: non serve padroneggiare Objective-C/Objective-C++ per
> programmare in C o C++. Conoscerli serve a capire *dove* si collocano nel
> panorama e a non spaventarsi davanti a codice Apple legacy.

---

## Esercizi — Giorno 4, C++

> Soluzioni in `esercizi_soluzioni.md` (sezione *G4-C++*).

**Esercizio G4-CPP-1 — Mappa parole**
Leggi una serie di parole e usa una `std::map<std::string,int>` per contare quante
volte appare ciascuna.

**Esercizio G4-CPP-2 — Ordina e cerca**
Crea un `std::vector<int>`, ordinalo con `std::sort` e verifica con `std::find` se
un numero inserito dall'utente è presente.

**Esercizio G4-CPP-3 — Template minimo**
Scrivi una funzione template `minimo(T a, T b)` e provala con `int`, `double` e
`char`.

**Esercizio G4-CPP-4 — Gerarchia di forme**
Crea una classe base astratta `Forma` con metodo virtuale `area()` e due classi
derivate `Triangolo` e `Rettangolo`. Calcola le aree tramite puntatori alla base.

**Esercizio G4-CPP-5 — Veicoli**
Crea una classe `Veicolo` con metodo `descrizione()` e due derivate `Auto` e `Moto`
che lo ridefiniscono (`override`).

**Esercizio G4-CPP-6 (sfida / discussione) — Objective-C**
*(Concettuale, da svolgere solo se si dispone di un Mac.)* Riscrivi la classe
`Persona` dell'esempio Objective-C aggiungendo un attributo `eta` e un metodo che
stampi nome ed età. In alternativa, discutete in aula le differenze tra la sintassi
a messaggi `[p saluta]` e la chiamata a metodo C++ `p.saluta()`.
