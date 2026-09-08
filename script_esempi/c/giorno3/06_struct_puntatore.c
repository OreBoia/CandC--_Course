#include <stdio.h>

struct Rettangolo {
    double base;
    double altezza;
};

double area(struct Rettangolo *r) {
    return r->base * r->altezza;    // r->base equivale a (*r).base
}

int main(void) {
    struct Rettangolo rett;
    rett.base = 4.0;
    rett.altezza = 2.5;

    struct Rettangolo *ptr = &rett;
    printf("Base:    %.2f\n", ptr->base);
    printf("Altezza: %.2f\n", ptr->altezza);
    printf("Area:    %.2f\n", area(ptr));

    return 0;
}
