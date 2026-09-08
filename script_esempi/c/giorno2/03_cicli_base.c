#include <stdio.h>

int main(void) {
    int scelta;

    printf("Conteggio con for: ");
    for (int i = 1; i <= 5; i++) {
        printf("%d ", i);
    }
    printf("\n");

    printf("Conto alla rovescia con while: ");
    int n = 5;
    while (n > 0) {
        printf("%d ", n);
        n--;
    }
    printf("\n");

    do {
        printf("Inserisci un numero positivo: ");
        scanf("%d", &scelta);
    } while (scelta <= 0);

    printf("Hai inserito: %d\n", scelta);
    return 0;
}
