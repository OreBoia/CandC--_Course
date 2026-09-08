#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    printf("Quanti numeri? ");
    scanf("%d", &n);

    int *array = malloc(n * sizeof(int));
    if (array == NULL) {    // controllo SEMPRE l'esito di malloc
        printf("Memoria insufficiente.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        array[i] = i * i;
    }

    printf("Array generato: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    free(array);    // libero la memoria: obbligatorio
    return 0;
}
