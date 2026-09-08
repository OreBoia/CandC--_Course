#include <stdio.h>

int main(void) {
    int x = 42;
    int *p = &x;    // p contiene l'indirizzo di x

    printf("Valore di x:    %d\n", x);
    printf("Indirizzo di x: %p\n", (void*)&x);
    printf("Valore di p:    %p\n", (void*)p);
    printf("Valore puntato: %d\n", *p);

    *p = 100;       // modifico x attraverso il puntatore
    printf("Ora x vale:     %d\n", x);

    return 0;
}
