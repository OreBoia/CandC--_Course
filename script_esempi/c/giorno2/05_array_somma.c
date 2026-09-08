#include <stdio.h>

int somma_array(const int numeri[], int dimensione) {
    int somma = 0;

    for (int i = 0; i < dimensione; i++) {
        somma += numeri[i];
    }

    return somma;
}

int main(void) {
    int numeri[6] = {10, 20, 30, 40, 50, 60};

    for (int i = 0; i < 6; i++) {
        printf("numeri[%d] = %d\n", i, numeri[i]);
    }

    printf("Somma totale: %d\n", somma_array(numeri, 6));
    return 0;
}
