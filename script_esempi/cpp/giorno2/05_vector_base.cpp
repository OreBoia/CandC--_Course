#include <iostream>
#include <vector>

int main() {
    std::vector<int> numeri = {10, 20, 30};

    numeri.push_back(40);
    numeri.push_back(50);

    std::cout << "Dimensione: " << numeri.size() << '\n';

    std::cout << "Ciclo con indice: ";
    for (size_t i = 0; i < numeri.size(); i++) {
        std::cout << numeri[i] << ' ';
    }
    std::cout << '\n';

    std::cout << "Ciclo range-based: ";
    for (int valore : numeri) {
        std::cout << valore << ' ';
    }
    std::cout << '\n';

    return 0;
}
