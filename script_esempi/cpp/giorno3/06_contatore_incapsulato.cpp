#include <iostream>

class Contatore {
private:
    int valore;

public:
    Contatore() : valore(0) {}

    void incrementa() {
        valore++;
    }

    void decrementa() {
        if (valore > 0) {    // il valore non deve mai scendere sotto zero
            valore--;
        }
    }

    int getValore() {
        return valore;
    }
};

int main() {
    Contatore c;

    c.incrementa();
    c.incrementa();
    c.incrementa();
    c.decrementa();
    c.decrementa();
    c.decrementa();
    c.decrementa();    // ignorato: il valore resta a 0

    std::cout << "Valore finale: " << c.getValore() << "\n";

    return 0;
}
