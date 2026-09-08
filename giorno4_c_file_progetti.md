# Giorno 4 — Modulo C (2h): File I/O, preprocessore e progetti multi-file

## Obiettivi della sezione

- Leggere e scrivere su **file** in C.
- Usare il **preprocessore** (`#define`, `#include`, macro).
- Organizzare un progetto su **più file** (header `.h` e sorgenti `.c`).
- Ricapitolare il percorso C con un piccolo progetto.

---

## 1. Lavorare con i file

In C i file si gestiscono con `FILE*` e le funzioni di `<stdio.h>`.

### Scrittura su file

```c
#include <stdio.h>

int main(void) {
    FILE *f = fopen("dati.txt", "w");   // "w" = write (sovrascrive)
    if (f == NULL) {
        printf("Impossibile aprire il file.\n");
        return 1;
    }

    fprintf(f, "Riga 1\n");
    fprintf(f, "Numero: %d\n", 42);

    fclose(f);                          // SEMPRE chiudere il file
    return 0;
}
```

### Lettura da file

```c
#include <stdio.h>

int main(void) {
    FILE *f = fopen("dati.txt", "r");   // "r" = read
    if (f == NULL) {
        printf("File non trovato.\n");
        return 1;
    }

    char riga[256];
    while (fgets(riga, sizeof(riga), f) != NULL) {
        printf("%s", riga);             // stampa ogni riga
    }

    fclose(f);
    return 0;
}
```

**Modalità di apertura principali:**

| Modalità | Significato |
|----------|-------------|
| `"r"` | lettura (il file deve esistere) |
| `"w"` | scrittura (crea/sovrascrive) |
| `"a"` | append (aggiunge in coda) |
| `"r+"` | lettura e scrittura |

> Come per `malloc`/`free`, ogni `fopen` richiede un `fclose`. È lo stesso principio
> di gestione delle risorse: in C++ moderno questo è automatizzato dagli stream
> (`std::ofstream`), che applicano RAII.

---

## 2. Il preprocessore

Il **preprocessore** elabora il codice *prima* della compilazione vera e propria.
Le sue direttive iniziano con `#`.

### `#define` — costanti e macro

```c
#include <stdio.h>

#define PI 3.14159
#define QUADRATO(x) ((x) * (x))   // macro con argomento

int main(void) {
    printf("%f\n", PI);
    printf("%d\n", QUADRATO(5));   // diventa ((5) * (5)) = 25
    return 0;
}
```

> Le parentesi nelle macro sono fondamentali: senza di esse `QUADRATO(2+3)`
> diventerebbe `2+3*2+3` = 11 invece di 25. Ottimo esempio per spiegare perché in
> C++ si preferiscono `const` e funzioni `inline` alle macro.

### Compilazione condizionale

```c
#define DEBUG 1

#if DEBUG
    printf("Modalita' debug attiva\n");
#endif
```

### Include guard

Per evitare che un header venga incluso più volte:

```c
#ifndef MIO_HEADER_H
#define MIO_HEADER_H
/* contenuto dell'header */
#endif
```

---

## 3. Progetti su più file

Un programma reale è diviso in più file. Schema tipico:

**`calcolatrice.h`** — l'interfaccia (cosa fa)

```c
#ifndef CALCOLATRICE_H
#define CALCOLATRICE_H

int somma(int a, int b);
int sottrai(int a, int b);

#endif
```

**`calcolatrice.c`** — l'implementazione (come lo fa)

```c
#include "calcolatrice.h"

int somma(int a, int b)   { return a + b; }
int sottrai(int a, int b) { return a - b; }
```

**`main.c`** — il programma principale

```c
#include <stdio.h>
#include "calcolatrice.h"

int main(void) {
    printf("%d\n", somma(10, 5));
    printf("%d\n", sottrai(10, 5));
    return 0;
}
```

Compilazione di tutti i sorgenti insieme:

```bash
gcc -Wall main.c calcolatrice.c -o programma
./programma
```

> **Concetto chiave**: l'header dichiara *cosa esiste*, il `.c` definisce *come
> funziona*. Questa separazione interfaccia/implementazione è alla base
> dell'organizzazione del software in C e C++.

---

## 4. Progetto di ricapitolazione (C)

**Gestore di una lista della spesa su file.** Il programma deve:

1. Mostrare un menu (1 = aggiungi articolo, 2 = mostra lista, 3 = esci).
2. Salvare gli articoli in `spesa.txt` (modalità append).
3. Leggere e stampare il file quando richiesto.

Concetti coinvolti: cicli, `switch`, stringhe, file I/O, funzioni. È un ottimo
esercizio integrativo da svolgere guidati in aula.

---

## Esercizi — Giorno 4, C

> Soluzioni in `esercizi_soluzioni.md` (sezione *G4-C*).

**Esercizio G4-C-1 — Scrivi e rileggi**
Scrivi su un file cinque numeri inseriti dall'utente, poi riapri il file e
stampane la somma.

**Esercizio G4-C-2 — Conta righe**
Dato un file di testo, scrivi un programma che conti quante righe contiene.

**Esercizio G4-C-3 — Macro**
Definisci una macro `MAX(a, b)` che restituisca il maggiore tra due valori e usala
in alcuni esempi (attenzione alle parentesi!).

**Esercizio G4-C-4 — Progetto multi-file**
Crea un modulo `geometria.h` / `geometria.c` con funzioni `area_cerchio` e
`area_quadrato`, e un `main.c` che le usi.

**Esercizio G4-C-5 (sfida) — Mini rubrica su file**
Realizza il progetto di ricapitolazione (lista della spesa) ampliandolo con la
possibilità di cancellare il file e ricominciare.
