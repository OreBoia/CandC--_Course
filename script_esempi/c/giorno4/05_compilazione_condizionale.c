#include <stdio.h>

#define DEBUG 1

int main(void) {
#if DEBUG
    printf("Modalita' debug attiva\n");
#endif

    printf("Programma in esecuzione.\n");

    // Cambia DEBUG a 0 e ricompila: la riga di debug sparisce dall'eseguibile,
    // non viene semplicemente "saltata" a runtime.
    return 0;
}
