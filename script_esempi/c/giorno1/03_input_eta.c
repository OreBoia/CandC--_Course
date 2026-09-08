// Libreria standard per usare printf e scanf.
#include <stdio.h>

// Punto di ingresso del programma.
int main(void) {
    // Variabile che conterra l'eta inserita dall'utente.
    int anni;

    // Messaggio mostrato prima della lettura dell'input.
    printf("Quanti anni hai? ");
    // Legge un intero da tastiera e lo salva in anni (serve &anni per passare l'indirizzo).
    scanf("%d", &anni);

    // Esegue un calcolo semplice e mostra il risultato.
    printf("Tra 10 anni avrai %d anni.\n", anni + 10);
    // Fine corretta del programma.
    return 0;
}
