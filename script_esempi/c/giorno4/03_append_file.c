#include <stdio.h>

int main(void) {
    FILE *f = fopen("log.txt", "a");    // "a" = append, aggiunge in coda
    if (f == NULL) {
        printf("Impossibile aprire il file.\n");
        return 1;
    }

    fprintf(f, "Nuova voce di log\n");
    fclose(f);

    printf("Voce aggiunta a log.txt (esegui piu' volte per vedere le righe accumularsi).\n");
    return 0;
}
