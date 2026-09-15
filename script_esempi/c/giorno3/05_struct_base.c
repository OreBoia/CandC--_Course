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

    struct Persona p2;
    strcpy(p2.nome, "Pippo");
    p2.eta= 34;
    p2.altezza = 1.76;

    printf("%s, %d anni, %.2f m\n", p2.nome, p2.eta, p2.altezza);
    
    printf("%s, %d anni, %.2f m\n", p.nome, p.eta, p.altezza);

    return 0;
}
