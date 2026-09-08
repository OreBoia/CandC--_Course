#include <iostream>
#include <vector>

std::vector<int> filtra_pari(const std::vector<int>& numeri) {
    std::vector<int> pari;

    for (int numero : numeri) {
        if (numero % 2 == 0) {
            pari.push_back(numero);
        }
    }

    return pari;
}

int main() {
    std::vector<int> numeri = {1, 2, 3, 4, 5, 6, 7, 8};
    std::vector<int> pari = filtra_pari(numeri);

    std::cout << "Numeri pari: ";
    for (int numero : pari) {
        std::cout << numero << ' ';
    }
    std::cout << '\n';

    return 0;
}
