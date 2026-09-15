#include <stdio.h>

#define PI 3.14159
#define QUADRATO(x) ((x) * (x))   // le parentesi attorno a x sono fondamentali

int main(void) {
    printf("PI = %f\n", PI);
    printf("QUADRATO(5) = %d\n", QUADRATO(5));

    int a = 2, b = 3;
    printf("QUADRATO(a + b) = %d\n", QUADRATO(a + b));   // senza parentesi darebbe 8, non 25

    return 0;
}
