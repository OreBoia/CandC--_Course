#include <stdio.h>

int somma(int a, int b) {
    return a + b;
}

double area_cerchio(double raggio) {
    return 3.14159 * raggio * raggio;
}

void saluta(void) {
    printf("Benvenuto!\n");
}

int main(void) {
    saluta();
    printf("Somma: %d\n", somma(3, 4));
    printf("Area del cerchio: %.2f\n", area_cerchio(2.0));
    return 0;
}
