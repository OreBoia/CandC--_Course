#include <stdio.h>

int main(void) {
    FILE *f = fopen("dati.txt", "w");   // "w" = write (sovrascrive)
    if (f == NULL) {
        printf("Impossibile aprire il file.\n");
        return 1;
    }

    fprintf(f, "Riga 1\n");
    fprintf(f, "Numero: %d\n", 42);

    fclose(f);    // SEMPRE chiudere il file
    printf("File scritto correttamente.\n");
    return 0;
}
