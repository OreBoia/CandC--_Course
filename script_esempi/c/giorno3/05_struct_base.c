#include <stdio.h>
#include <string.h>

struct Persona {
    char nome[50];
    int eta;
    double altezza;
};

int main(void) {
    struct Persona p;
    strcpy(p.nome, "Luca");
    p.eta = 28;
    p.altezza = 1.80;

    printf("%s, %d anni, %.2f m\n", p.nome, p.eta, p.altezza);

    return 0;
}
