#include <stdio.h>
#include <string.h>

#define FILE_SPESA "spesa.txt"

void aggiungi_articolo(void) {
    char articolo[100];
    printf("Articolo da aggiungere: ");
    scanf(" %99[^\n]", articolo);

    FILE *f = fopen(FILE_SPESA, "a");   // append: aggiunge senza cancellare
    if (f == NULL) {
        printf("Impossibile aprire il file.\n");
        return;
    }
    fprintf(f, "%s\n", articolo);
    fclose(f);
    printf("Aggiunto: %s\n", articolo);
}

void mostra_lista(void) {
    FILE *f = fopen(FILE_SPESA, "r");
    if (f == NULL) {
        printf("La lista e' vuota.\n");
        return;
    }

    printf("--- Lista della spesa ---\n");
    char riga[100];
    while (fgets(riga, sizeof(riga), f) != NULL) {
        printf("- %s", riga);
    }
    fclose(f);
}

int main(void) {
    int scelta;

    do {
        printf("\n1) Aggiungi articolo\n2) Mostra lista\n3) Esci\nScelta: ");
        scanf("%d", &scelta);

        switch (scelta) {
            case 1: aggiungi_articolo(); break;
            case 2: mostra_lista();      break;
            case 3: printf("Arrivederci!\n"); break;
            default: printf("Scelta non valida.\n");
        }
    } while (scelta != 3);

    return 0;
}
