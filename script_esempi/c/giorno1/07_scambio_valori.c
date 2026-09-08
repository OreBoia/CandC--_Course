// Libreria standard per input/output su console.
#include <stdio.h>

// Punto di ingresso del programma.
int main(void) {
    // Due variabili da scambiare.
    int a;
    int b;

    // Legge il primo valore.
    printf("Inserisci il valore di a: ");
    scanf("%d", &a);

    // Legge il secondo valore.
    printf("Inserisci il valore di b: ");
    scanf("%d", &b);

    // Mostra i valori prima dello scambio.
    printf("Prima dello scambio -> a = %d, b = %d\n", a, b);

    // Variabile temporanea usata per non perdere il valore originale di a.
    int temp = a;
    // Copia b in a.
    a = b;
    // Copia il vecchio valore di a (salvato in temp) dentro b.
    b = temp;

    // Mostra i valori dopo lo scambio.
    printf("Dopo lo scambio  -> a = %d, b = %d\n", a, b);

    // Fine corretta del programma.
    return 0;
}
