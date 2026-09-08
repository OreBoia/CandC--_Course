# Giorno 2 — Modulo C (2h): Controllo di flusso, funzioni, array e stringhe

## Obiettivi della sezione

- Prendere decisioni con `if`/`else` e `switch`.
- Ripetere istruzioni con i cicli `for`, `while`, `do-while`.
- Organizzare il codice in **funzioni**.
- Usare **array** e **stringhe in stile C** (array di `char`).

---

## 1. Strutture condizionali

```c
#include <stdio.h>

int main(void) {
    int voto;
    printf("Inserisci il voto (0-30): ");
    scanf("%d", &voto);

    if (voto >= 18) {
        printf("Promosso!\n");
    } else {
        printf("Insufficiente.\n");
    }
    return 0;
}
```

Operatori di confronto: `==`, `!=`, `<`, `>`, `<=`, `>=`.
Operatori logici: `&&` (and), `||` (or), `!` (not).

> **Trappola classica**: `=` è assegnamento, `==` è confronto. `if (x = 5)` è un
> errore logico frequente. Compilare con `-Wall` aiuta a individuarlo.

### `switch`

```c
switch (giorno) {
    case 1: printf("Lunedi\n");   break;
    case 2: printf("Martedi\n");  break;
    default: printf("Altro giorno\n");
}
```

Il `break` è obbligatorio per non "cadere" nel caso successivo (*fall-through*).

---

## 2. Cicli

```c
// for: quando conosciamo il numero di iterazioni
for (int i = 1; i <= 5; i++) {
    printf("%d ", i);          // 1 2 3 4 5
}

// while: quando la condizione comanda
int n = 10;
while (n > 0) {
    printf("%d ", n);
    n--;
}

// do-while: esegue almeno una volta
int scelta;
do {
    printf("Inserisci un numero positivo: ");
    scanf("%d", &scelta);
} while (scelta <= 0);
```

---

## 3. Funzioni

Una **funzione** raggruppa istruzioni riutilizzabili. Ha un tipo di ritorno,
un nome e dei parametri.

```c
#include <stdio.h>

// dichiarazione + definizione
int somma(int a, int b) {
    return a + b;
}

double area_cerchio(double raggio) {
    return 3.14159 * raggio * raggio;
}

void saluta(void) {            // void = non restituisce nulla
    printf("Benvenuto!\n");
}

int main(void) {
    saluta();
    printf("Somma: %d\n", somma(3, 4));
    printf("Area: %.2f\n", area_cerchio(2.0));
    return 0;
}
```

**Concetti da spiegare:**

- I parametri in C sono passati **per valore**: la funzione riceve una *copia*.
  Modificarli dentro la funzione non cambia le variabili del chiamante.
- Per modificare l'originale servono i **puntatori** (Giorno 3).
- I **prototipi** (dichiarazioni in cima al file o in un header) permettono di usare
  una funzione prima della sua definizione.

---

## 4. Array

Un **array** è una sequenza di elementi dello stesso tipo, in memoria contigua.

```c
#include <stdio.h>

int main(void) {
    int numeri[5] = {10, 20, 30, 40, 50};

    for (int i = 0; i < 5; i++) {
        printf("numeri[%d] = %d\n", i, numeri[i]);
    }
    return 0;
}
```

**Punti chiave:**

- Gli indici partono da **0**: il primo elemento è `numeri[0]`.
- La dimensione è **fissa** e va conosciuta in anticipo.
- Il C **non controlla** se si esce dai limiti (`numeri[10]` non dà errore di
  compilazione ma è comportamento indefinito): è una grande fonte di bug.

---

## 5. Stringhe in stile C

In C una stringa è un **array di `char` terminato dal carattere nullo `'\0'`**.

```c
#include <stdio.h>
#include <string.h>   // funzioni per stringhe

int main(void) {
    char nome[20] = "Mario";

    printf("Lunghezza: %zu\n", strlen(nome));   // 5

    char saluto[40] = "Ciao, ";
    strcat(saluto, nome);                       // concatena
    printf("%s\n", saluto);                     // Ciao, Mario
    return 0;
}
```

Funzioni utili di `<string.h>`: `strlen` (lunghezza), `strcpy` (copia),
`strcat` (concatena), `strcmp` (confronta).

> **Confronto anticipato col C++**: tutto questo in C++ si fa con `std::string`,
> che gestisce lunghezza e memoria automaticamente. È uno degli esempi più chiari
> del valore aggiunto del C++ (vedi `giorno2_cpp_funzioni_container.md`).

---

## Esercizi — Giorno 2, C

> Soluzioni in `esercizi_soluzioni.md` (sezione *G2-C*).

**Esercizio G2-C-1 — Pari o dispari**
Leggi un numero e stampa se è pari o dispari (usa l'operatore `%`).

**Esercizio G2-C-2 — Tabellina**
Chiedi un numero `n` e stampa la sua tabellina da 1 a 10 usando un ciclo `for`.

**Esercizio G2-C-3 — Funzione massimo**
Scrivi una funzione `int massimo(int a, int b)` che restituisce il maggiore tra
due numeri e usala nel `main`.

**Esercizio G2-C-4 — Somma di un array**
Dato un array di 6 interi, scrivi una funzione che ne calcoli e restituisca la somma.

**Esercizio G2-C-5 — Conta vocali**
Leggi una parola (array di `char`) e conta quante vocali contiene.

**Esercizio G2-C-6 (sfida) — Numero primo**
Scrivi una funzione `int e_primo(int n)` che restituisce 1 se `n` è primo, 0
altrimenti, e stampa tutti i numeri primi da 2 a 50.
