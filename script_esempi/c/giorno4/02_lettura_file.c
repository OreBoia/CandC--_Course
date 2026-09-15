#include <stdio.h>

int main(void) {
    FILE *f = fopen("dati.txt", "r");   // "r" = read
    if (f == NULL) {
        printf("File non trovato. Esegui prima 01_scrittura_file.\n");
        return 1;
    }

    char riga[256];
    while (fgets(riga, sizeof(riga), f) != NULL) {
        printf("%s", riga);    // stampa ogni riga (fgets include il '\n')
    }

    fclose(f);
    return 0;
}
