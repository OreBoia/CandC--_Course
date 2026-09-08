// Libreria standard per input/output testuale.
#include <stdio.h>

// Punto di ingresso del programma.
int main(void) {
    // Temperatura in gradi Celsius inserita dall'utente.
    double celsius;

    // Chiede il valore in Celsius.
    printf("Inserisci i gradi Celsius: ");
    // %lf legge un valore double.
    scanf("%lf", &celsius);

    // Formula di conversione da Celsius a Fahrenheit.
    double fahrenheit = celsius * 9.0 / 5.0 + 32.0;
    // Stampa entrambi i valori con 2 decimali.
    printf("%.2f C corrispondono a %.2f F\n", celsius, fahrenheit);

    // Uscita corretta del programma.
    return 0;
}
