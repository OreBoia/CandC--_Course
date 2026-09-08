// Libreria standard per funzioni di input/output.
#include <stdio.h>

// Funzione principale del programma.
int main(void) {
    // Tre variabili intere da leggere in input.
    int a;
    int b;
    int c;

    // Richiede tre numeri interi separati da spazio.
    printf("Inserisci tre numeri interi: ");
    // Legge i tre valori e li salva nelle rispettive variabili.
    scanf("%d %d %d", &a, &b, &c);

    // Divisione per 3.0 per ottenere una media in virgola mobile.
    double media = (a + b + c) / 3.0;
    // Stampa la media con due cifre decimali.
    printf("Media: %.2f\n", media);

    // Terminazione corretta.
    return 0;
}
