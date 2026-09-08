// Libreria standard per input/output testuale.
#include <stdio.h>

// Funzione principale del programma.
int main(void) {
    // Variabile intera: contiene l'eta.
    int eta = 30;
    // Variabile in virgola mobile doppia precisione: contiene l'altezza.
    double altezza = 1.75;
    // Variabile carattere: contiene una singola lettera.
    char iniziale = 'M';

    // %d stampa un intero.
    printf("Eta: %d\n", eta);
    // %.2f stampa un numero decimale con 2 cifre dopo la virgola.
    printf("Altezza: %.2f\n", altezza);
    // %c stampa un singolo carattere.
    printf("Iniziale: %c\n", iniziale);

    // Terminazione corretta del programma.
    return 0;
}
