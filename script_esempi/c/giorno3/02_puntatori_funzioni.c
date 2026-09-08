#include <stdio.h>

void raddoppia(int *n) {   // riceve l'indirizzo
    *n = *n * 2;            // modifica l'originale
}

int main(void) {
    int valore = 7;

    printf("Prima: %d\n", valore);
    raddoppia(&valore);
    printf("Dopo:  %d\n", valore);

    return 0;
}
