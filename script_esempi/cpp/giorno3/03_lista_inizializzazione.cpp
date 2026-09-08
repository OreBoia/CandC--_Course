#include <iostream>

class Punto {
private:
    int x, y;

public:
    Punto(int px, int py) : x(px), y(py) {}    // lista di inizializzazione

    void stampa() {
        std::cout << "(" << x << ", " << y << ")\n";
    }
};

int main() {
    Punto origine(0, 0);
    Punto p(3, 4);

    origine.stampa();
    p.stampa();

    return 0;
}
