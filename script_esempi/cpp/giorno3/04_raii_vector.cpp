#include <iostream>
#include <vector>

int main() {
    std::cout << "Inizio\n";
    {
        std::vector<int> dati(5, 0);    // alloca spazio per 5 interi
        for (int i = 0; i < 5; i++) {
            dati[i] = i * i;
        }

        std::cout << "Contenuto: ";
        for (int v : dati) {
            std::cout << v << ' ';
        }
        std::cout << '\n';
    }    // qui il distruttore di 'dati' libera la memoria automaticamente
    std::cout << "Fine (nessun free richiesto)\n";

    return 0;
}
