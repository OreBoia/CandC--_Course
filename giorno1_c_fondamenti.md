# Giorno 1 — Modulo C (2h): Fondamenti del linguaggio C

## Obiettivi della sezione

- Capire cos'è il C, perché esiste e dove si usa ancora oggi.
- Comprendere il ciclo *scrivi → compila → esegui*.
- Scrivere il primo programma e gestire variabili, tipi di dato e input/output.

---

## 1. Cos'è il C (teoria)

Il **C** è un linguaggio di programmazione creato da **Dennis Ritchie** ai Bell Labs
tra il 1969 e il 1973, nato per riscrivere il sistema operativo **UNIX**. È un
linguaggio:

- **Compilato**: il codice sorgente viene tradotto in linguaggio macchina prima
  dell'esecuzione.
- **Procedurale**: il programma è organizzato in funzioni che operano su dati.
- **Di basso livello (relativamente)**: permette di lavorare vicino all'hardware
  (memoria, puntatori), pur restando leggibile.
- **Portabile**: lo stesso codice può essere compilato su sistemi diversi.

Ancora oggi il C è il linguaggio di sistemi operativi, microcontrollori, driver,
firmware e di gran parte delle librerie su cui si basano linguaggi più moderni.

### Il ciclo di compilazione

```
codice sorgente (.c)
        │  preprocessore  → espande #include e #define
        ▼
codice preprocessato
        │  compilatore    → traduce in assembly/oggetto (.o)
        ▼
file oggetto
        │  linker         → collega le librerie
        ▼
eseguibile (programma)
```

Per il principiante questi passaggi sono nascosti dietro un solo comando (`gcc`),
ma è importante sapere che esistono: molti errori appartengono a fasi diverse.

---

## 2. Il primo programma

```c
#include <stdio.h>   // libreria standard di input/output

int main(void) {
    printf("Ciao, mondo!\n");   // \n manda a capo
    return 0;                   // 0 = il programma è terminato senza errori
}
```

Compilazione ed esecuzione:

```bash
gcc -Wall -Wextra hello.c -o hello
./hello
```

**Elementi chiave da spiegare:**

- `#include <stdio.h>` rende disponibili funzioni come `printf` e `scanf`.
- `int main(void)` è il punto di ingresso: ogni programma C parte da qui.
- Le istruzioni terminano con `;`.
- `return 0;` comunica al sistema operativo l'esito dell'esecuzione.

---

## 3. Variabili e tipi di dato

Una **variabile** è uno spazio in memoria con un nome e un tipo. In C il tipo va
sempre dichiarato.

| Tipo | Descrizione | Esempio |
|------|-------------|---------|
| `int` | numero intero | `int eta = 30;` |
| `float` | numero decimale (precisione singola) | `float prezzo = 9.99f;` |
| `double` | numero decimale (precisione doppia) | `double pi = 3.14159;` |
| `char` | un singolo carattere | `char lettera = 'A';` |
| `_Bool` (o `bool` con `<stdbool.h>`) | vero/falso | `bool attivo = true;` |

```c
#include <stdio.h>

int main(void) {
    int eta = 30;
    double altezza = 1.75;
    char iniziale = 'M';

    printf("Eta: %d\n", eta);
    printf("Altezza: %.2f\n", altezza);
    printf("Iniziale: %c\n", iniziale);
    return 0;
}
```

### Gli specificatori di formato di `printf`

| Specificatore | Tipo |
|---------------|------|
| `%d` | int |
| `%f` | float/double |
| `%.2f` | double con 2 decimali |
| `%c` | char |
| `%s` | stringa |

---

## 4. Input dell'utente con `scanf`

```c
#include <stdio.h>

int main(void) {
    int anni;
    printf("Quanti anni hai? ");
    scanf("%d", &anni);   // & = "indirizzo di"; scanf scrive QUI
    printf("Tra 10 anni avrai %d anni.\n", anni + 10);
    return 0;
}
```

> Il simbolo `&` davanti alla variabile è fondamentale: indica *dove* salvare il
> valore letto. È un primo assaggio del concetto di **puntatore** (Giorno 3).

---

## 5. Operatori essenziali

```c
int a = 7, b = 2;
printf("%d\n", a + b);   // 9  somma
printf("%d\n", a - b);   // 5  differenza
printf("%d\n", a * b);   // 14 prodotto
printf("%d\n", a / b);   // 3  divisione INTERA (attenzione!)
printf("%d\n", a % b);   // 1  resto (modulo)
```

> **Trappola classica per principianti**: `a / b` tra due `int` produce un `int`.
> Per ottenere `3.5` almeno uno dei due deve essere `double`: `(double)a / b`.

---

## Esercizi — Giorno 1, C

> Le soluzioni si trovano in `esercizi_soluzioni.md` (sezione *G1-C*).

**Esercizio G1-C-1 — Saluto personalizzato**
Scrivi un programma che dichiari una variabile con il tuo nome (usa `char nome[]`)
e stampi `Ciao, <nome>!`.

**Esercizio G1-C-2 — Calcolatrice rettangolo**
Chiedi all'utente base e altezza di un rettangolo (numeri interi) e stampa
perimetro e area.

**Esercizio G1-C-3 — Conversione temperature**
Chiedi una temperatura in gradi Celsius (`double`) e stampa il valore in
Fahrenheit usando la formula `F = C * 9 / 5 + 32`. Fai attenzione alla divisione
intera.

**Esercizio G1-C-4 — Media di tre numeri**
Leggi tre numeri interi e stampa la loro media con due cifre decimali.

**Esercizio G1-C-5 (sfida) — Scambio di valori**
Date due variabili `a` e `b`, scambia i loro valori usando una terza variabile
temporanea e stampa il risultato prima e dopo lo scambio.
