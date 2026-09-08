# Teoria trasversale: differenze tra C e C++ e casi d'uso

Questo modulo teorico raccoglie e sistematizza il confronto tra i due linguaggi.
Va affrontato quando gli studenti hanno già visto abbastanza codice (idealmente tra
il Giorno 2 e il Giorno 3) per riconoscere gli esempi citati.

---

## 1. Una storia condivisa

- **C** (1972, Dennis Ritchie): nato per scrivere UNIX. Linguaggio procedurale,
  minimale, vicino all'hardware.
- **C++** (1983, Bjarne Stroustrup): nato come *"C con le classi"*, aggiunge la
  programmazione a oggetti e l'astrazione **senza rinunciare alle prestazioni**.

Il C++ è stato progettato per essere **largamente compatibile** con il C: gran
parte del codice C valido compila anche come C++. Per questo li si insegna bene in
parallelo.

---

## 2. Le differenze fondamentali

### a) Paradigma di programmazione

| | C | C++ |
|---|---|-----|
| Paradigma | procedurale | multi-paradigma (procedurale, OOP, generico) |
| Unità base | funzioni | funzioni **e** classi/oggetti |

Il C ragiona per *funzioni che manipolano dati*; il C++ permette anche di ragionare
per *oggetti che incapsulano dati e comportamenti*.

### b) Gestione della memoria

| | C | C++ |
|---|---|-----|
| Allocazione | `malloc` / `free` (manuale) | `new`/`delete`, ma soprattutto RAII |
| Sicurezza | a carico del programmatore | container e smart pointer la automatizzano |

In C il programmatore è responsabile di ogni allocazione e rilascio. In C++ moderno
si delega quasi tutto a `std::vector`, `std::string` e smart pointer (`std::unique_ptr`,
`std::shared_ptr`), che applicano il principio **RAII** (vedi `giorno3_cpp_oop.md`).

### c) Stringhe e collezioni

| Operazione | C | C++ |
|------------|---|-----|
| Stringa | `char[]` + `<string.h>` | `std::string` |
| Array dinamico | `malloc` + gestione manuale | `std::vector` |
| Coppie chiave-valore | da implementare a mano | `std::map` |

### d) Sicurezza dei tipi

Il C++ è più **rigoroso** sui tipi: molte conversioni che il C accetta
silenziosamente in C++ richiedono un cast esplicito o danno errore di compilazione.
Per il principiante questo significa scoprire i bug *prima*, in fase di compilazione,
anziché a runtime.

### e) Funzionalità esclusive del C++

- **Classi** e i quattro pilastri della OOP (incapsulamento, astrazione,
  ereditarietà, polimorfismo).
- **Overloading** di funzioni e operatori.
- **Riferimenti** (`int&`) accanto ai puntatori.
- **Template** (programmazione generica).
- **Namespace** (`std::`).
- **Gestione delle eccezioni** (`try`/`catch`).
- La **STL** (Standard Template Library).

### f) Input/output

| | C | C++ |
|---|---|-----|
| Output | `printf("%d", x);` | `std::cout << x;` |
| Input | `scanf("%d", &x);` | `std::cin >> x;` |
| Sicurezza | nessun controllo di tipo a runtime | controllo di tipo a compile-time |

---

## 3. Tabella riepilogativa

| Aspetto | C | C++ |
|---------|---|-----|
| Anno | 1972 | 1983 |
| Paradigma | procedurale | multi-paradigma + OOP |
| Memoria | manuale (`malloc`/`free`) | RAII, container, smart pointer |
| Stringhe | `char[]` | `std::string` |
| Collezioni | array statici | STL (`vector`, `map`, `set`...) |
| Generici | macro (fragili) | template |
| Eccezioni | assenti | `try`/`catch` |
| Curva di apprendimento | più ripida sui dettagli (puntatori, memoria) | più ampia (molte funzionalità) |
| Dimensione tipica eseguibili | minima | leggermente maggiore |
| Compatibilità | — | quasi tutto il C valido è C++ |

---

## 4. Quando usare il C

Il C resta la scelta migliore quando servono **controllo, semplicità e minimo
ingombro**:

- **Sistemi operativi e kernel** (Linux, gran parte di UNIX).
- **Sistemi embedded e microcontrollori** (memoria limitata, controllo diretto).
- **Driver e firmware**.
- **Librerie a basso livello** richiamabili da molti altri linguaggi (Python, Rust,
  Java espongono spesso interfacce C).
- Contesti dove serve un linguaggio **piccolo, prevedibile e universalmente
  portabile**.

**Punti di forza**: semplicità del linguaggio, controllo totale sulla memoria,
massima portabilità, eseguibili compatti.

---

## 5. Quando usare il C++

Il C++ brilla quando il software è **grande e complesso** ma le **prestazioni**
restano critiche:

- **Videogiochi e motori grafici** (Unreal Engine).
- **Applicazioni desktop ad alte prestazioni** e software professionale.
- **Sistemi finanziari** e *trading* ad alta frequenza.
- **Software scientifico e di simulazione**.
- **Browser web** (parti di Chrome, Firefox).
- **Sistemi che richiedono OOP** e astrazioni ma non possono permettersi un garbage
  collector.

**Punti di forza**: astrazione senza penalità di prestazioni, OOP, STL ricca,
gestione automatica delle risorse (RAII), forte sicurezza dei tipi.

---

## 6. Come scegliere: una regola pratica

- Serve il **massimo controllo** su hardware e memoria, con un linguaggio minimale?
  → **C**.
- Si costruisce un **sistema complesso** che beneficia di OOP, container e astrazioni,
  mantenendo prestazioni elevate? → **C++**.
- Si lavora su una **codebase esistente**? → si usa il linguaggio già in uso.

> Concetto da lasciare agli studenti: non c'è un linguaggio "migliore" in assoluto.
> C e C++ risolvono problemi diversi e spesso **coesistono** nello stesso progetto.
> Imparare entrambi rende programmatori più consapevoli e versatili.

---

## 7. Spunti di discussione per l'aula

1. Perché un sistema operativo come Linux è scritto prevalentemente in C e non in C++?
2. Perché un motore di gioco moderno preferisce il C++?
3. In che senso il C++ "paga zero" per le astrazioni che il C non offre? (zero-cost
   abstractions)
4. Quali rischi della gestione manuale della memoria in C vengono eliminati dal RAII
   in C++?
