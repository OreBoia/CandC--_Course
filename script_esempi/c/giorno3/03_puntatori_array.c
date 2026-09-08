#include <stdio.h>

int main(void) {
    int numeri[3] = {10, 20, 30};
    int *p = numeri;    // p punta a numeri[0]

    printf("*p:       %d\n", *p);
    printf("*(p+1):   %d\n", *(p + 1));
    printf("*(p+2):   %d\n", *(p + 2));
    printf("numeri[2]: %d\n", numeri[2]);

    printf("Con il ciclo: ");
    for (int i = 0; i < 3; i++) {
        printf("%d ", *(numeri + i));
    }
    printf("\n");

    return 0;
}
