#include <stdio.h>

int main(void) {
    int voto;

    printf("Inserisci il voto (0-30): ");
    scanf("%d", &voto);

    if (voto >= 18 && voto <= 30) {
        printf("Promosso!\n");
    } else if(voto < 18 && voto >= 0) {
        printf("Insufficiente.\n");
    }else {
        printf("Voto non valido.\n");
    }

    return 0;
}
