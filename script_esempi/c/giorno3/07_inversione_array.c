#include <stdio.h>

void inverti(int *array, int n) {
    int inizio = 0;
    int fine = n - 1;

    while (inizio < fine) {
        int temp = array[inizio];
        array[inizio] = array[fine];
        array[fine] = temp;
        inizio++;
        fine--;
    }
}

int main(void) {
    int numeri[6] = {1, 2, 3, 4, 5, 6};
    int n = 6;

    printf("Prima:  ");
    for (int i = 0; i < n; i++) {
        printf("%d ", numeri[i]);
    }
    printf("\n");

    inverti(numeri, n);

    printf("Dopo:   ");
    for (int i = 0; i < n; i++) {
        printf("%d ", numeri[i]);
    }
    printf("\n");

    return 0;
}
