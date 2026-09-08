#include <iostream>
#include <vector>

double media(const std::vector<double>& valori) {
    if (valori.empty()) {
        return 0;
    }

    double somma = 0;

    for (double valore : valori) {
        somma += valore;
    }

    return somma / valori.size();
}

int main() {
    std::vector<double> voti = {28, 30, 25, 27};

    std::cout << "Media: " << media(voti) << '\n';
    return 0;
}
