#include <iostream>

class Frazione {
private:
    int numeratore;
    int denominatore;

public:
    Frazione(int n, int d) : numeratore(n), denominatore(d) {}

    Frazione somma(Frazione altra) {
        int n = numeratore * altra.denominatore + altra.numeratore * denominatore;
        int d = denominatore * altra.denominatore;
        return Frazione(n, d);
    }

    void stampa() {
        std::cout << numeratore << "/" << denominatore << "\n";
    }
};

int main() {
    Frazione a(1, 2);
    Frazione b(1, 3);

    Frazione risultato = a.somma(b);
    risultato.stampa();    // 5/6

    return 0;
}
