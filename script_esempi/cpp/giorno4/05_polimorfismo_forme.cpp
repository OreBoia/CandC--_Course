#include <iostream>

class Forma {
public:
    virtual double area() = 0;     // metodo virtuale puro -> classe astratta
    virtual ~Forma() {}            // distruttore virtuale (buona pratica)
};

class Cerchio : public Forma {
    double raggio;
public:
    Cerchio(double r) : raggio(r) {}
    double area() override { return 3.14159 * raggio * raggio; }
};

class Quadrato : public Forma {
    double lato;
public:
    Quadrato(double l) : lato(l) {}
    double area() override { return lato * lato; }
};

int main() {
    Forma* forme[] = { new Cerchio(2.0), new Quadrato(3.0) };

    for (Forma* f : forme) {
        std::cout << "Area: " << f->area() << "\n";   // chiama la versione giusta!
    }

    for (Forma* f : forme) delete f;   // libero la memoria
    return 0;
}
