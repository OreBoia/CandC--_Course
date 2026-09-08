#include <stdio.h>
#include <string.h>

int conta_vocali(const char parola[]) {
    int vocali = 0;

    for (size_t i = 0; i < strlen(parola); i++) {
        char c = parola[i];

        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            vocali++;
        }
    }

    return vocali;
}

int main(void) {
    char parola[50];

    printf("Inserisci una parola: ");
    scanf("%49s", parola);

    printf("Lunghezza: %zu\n", strlen(parola));
    printf("Numero di vocali: %d\n", conta_vocali(parola));
    return 0;
}
