u# Giorno 3 — Modulo C (2h): Puntatori, gestione della memoria e struct

## Obiettivi della sezione

- Capire cosa sono i **puntatori** e perché sono centrali in C.
- Gestire la **memoria dinamica** con `malloc` e `free`.
- Definire tipi compositi con le **struct**.

> Questo è il modulo concettualmente più impegnativo del corso C. Procedere lenti,
> con molti disegni della memoria alla lavagna.

---

## 1. I puntatori (teoria)

Ogni variabile vive a un **indirizzo** in memoria. Un **puntatore** è una variabile
che contiene un indirizzo, cioè "punta" a un'altra variabile.

```c
#include <stdio.h>

int main(void) {
    int x = 42;
    int *p = &x;     // p contiene l'indirizzo di x

    printf("Valore di x:        %d\n", x);    // 42
    printf("Indirizzo di x:     %p\n", (void*)&x);
    printf("Valore di p:        %p\n", (void*)p);   // = indirizzo di x
    printf("Valore puntato:     %d\n", *p);   // 42  (dereferenziazione)

    *p = 100;        // modifico x ATTRAVERSO il puntatore
    printf("Ora x vale:         %d\n", x);    // 100
    return 0;
}
```

**Due simboli da non confondere:**

- `&x` → "indirizzo di x".
- `*p` → "valore puntato da p" (dereferenziazione).

### A cosa servono i puntatori

1. Permettere a una funzione di **modificare** le variabili del chiamante.
2. Gestire la **memoria dinamica**.
3. Lavorare in modo efficiente con array e strutture grandi (senza copiarle).

```c
#include <stdio.h>

void raddoppia(int *n) {   // riceve l'indirizzo
    *n = *n * 2;           // modifica l'originale
}

int main(void) {
    int valore = 7;
    raddoppia(&valore);    // passo l'indirizzo
    printf("%d\n", valore);   // 14
    return 0;
}
```

> Questo è esattamente ciò che in C++ si fa con i **riferimenti** (`int& n`), in modo
> più leggibile. Vale la pena affiancare i due codici.

---

## 2. Puntatori e array

In C il nome di un array è di fatto l'indirizzo del suo primo elemento.

```c
int numeri[3] = {10, 20, 30};
int *p = numeri;         // p punta a numeri[0]

printf("%d\n", *p);      // 10
printf("%d\n", *(p+1));  // 20  (aritmetica dei puntatori)
printf("%d\n", numeri[2]);   // 30
```

`numeri[i]` è equivalente a `*(numeri + i)`: un concetto che chiarisce molti
comportamenti del linguaggio.

---

## 3. Gestione della memoria dinamica

Finora la memoria era allocata automaticamente (stack). Per quantità decise a
runtime serve la **memoria dinamica** (heap), con `malloc` e `free` da `<stdlib.h>`.

```c
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    printf("Quanti numeri? ");
    scanf("%d", &n);

    // alloca spazio per n interi
    int *array = malloc(n * sizeof(int));
    if (array == NULL) {          // controllo SEMPRE l'esito
        printf("Memoria insufficiente.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        array[i] = i * i;
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    free(array);    // libero la memoria: OBBLIGATORIO
    return 0;
}
```

**Regole d'oro:**

- A ogni `malloc` deve corrispondere un `free`.
- Dimenticare `free` causa un **memory leak**.
- Usare memoria dopo `free` (*use-after-free*) o due `free` sullo stesso puntatore
  sono bug gravi.

> **Confronto col C++**: questa gestione manuale è proprio ciò che il C++ automatizza
> con `std::vector` e con il principio **RAII** (vedi `giorno3_cpp_oop.md`). È il
> momento perfetto per far percepire il valore di quelle astrazioni.

---

## 4. Le struct

Una **struct** raggruppa variabili di tipo diverso sotto un unico nome: è il modo
del C di rappresentare un "oggetto" di dati.

```c
#include <stdio.h>
#include <string.h>

struct Persona {
    char nome[50];
    int eta;
    double altezza;
};

int main(void) {
    struct Persona p;
    strcpy(p.nome, "Luca");
    p.eta = 28;
    p.altezza = 1.80;

    printf("%s, %d anni, %.2f m\n", p.nome, p.eta, p.altezza);
    return 0;
}
```

Si accede ai campi con il punto `.`. Se si lavora con un *puntatore* a struct si usa
la freccia `->`:

```c
struct Persona *ptr = &p;
printf("%s\n", ptr->nome);   // equivale a (*ptr).nome
```

> La struct è il precursore della **classe** del C++: stessi dati, ma senza le
> funzioni (metodi) e senza l'incapsulamento. Il ponte verso l'OOP parte da qui.

---

## Esercizi — Giorno 3, C

> Soluzioni in `esercizi_soluzioni.md` (sezione *G3-C*).

**Esercizio G3-C-1 — Scambio con puntatori**
Scrivi `void scambia(int *a, int *b)` che scambia due valori tramite puntatori.

**Esercizio G3-C-2 — Min e max via puntatori**
Scrivi una funzione che, dato un array e la sua dimensione, restituisca minimo e
massimo scrivendoli in due variabili passate per puntatore.

**Esercizio G3-C-3 — Array dinamico**
Chiedi all'utente quanti numeri vuole inserire, alloca l'array con `malloc`, leggi i
valori, stampa la somma e ricordati di fare `free`.

**Esercizio G3-C-4 — Struct rettangolo**
Definisci una struct `Rettangolo` con `base` e `altezza`. Scrivi una funzione che
riceva la struct e restituisca l'area.

**Esercizio G3-C-5 — Rubrica**
Crea un array di 3 struct `Persona`, riempilo e stampa tutti i contatti.

**Esercizio G3-C-6 (sfida) — Inversione array in-place**
Scrivi una funzione che inverta l'ordine degli elementi di un array usando solo i
puntatori e una variabile temporanea (senza creare un secondo array).
