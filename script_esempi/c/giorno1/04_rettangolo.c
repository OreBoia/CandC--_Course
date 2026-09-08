// Libreria standard per input/output su console.
#include <stdio.h>

// Funzione principale eseguita all'avvio.
int main(void) {
    // Base del rettangolo (numero intero).
    int base;
    // Altezza del rettangolo (numero intero).
    int altezza;

    // Richiede la base all'utente.
    printf("Inserisci la base: ");
    // Legge la base inserita.
    scanf("%d", &base);

    // Richiede l'altezza all'utente.
    printf("Inserisci l'altezza: ");
    // Legge l'altezza inserita.
    scanf("%d", &altezza);

    // Formula del perimetro del rettangolo: 2 * (base + altezza).
    int perimetro = 2 * (base + altezza);
    // Formula dell'area del rettangolo: base * altezza.
    int area = base * altezza;

    // Mostra il perimetro calcolato.
    printf("Perimetro: %d\n", perimetro);
    // Mostra l'area calcolata.
    printf("Area: %d\n", area);

    // Fine corretta del programma.
    return 0;
}
