#include <iostream>
#include <string>

class Veicolo {
protected:
    std::string marca;
public:
    Veicolo(std::string m) : marca(m) {}
    virtual std::string descrizione() { return marca + ": veicolo generico"; }
    virtual ~Veicolo() {}
};

class Auto : public Veicolo {
public:
    Auto(std::string m) : Veicolo(m) {}
    std::string descrizione() override { return marca + ": auto a quattro ruote"; }
};

class Moto : public Veicolo {
public:
    Moto(std::string m) : Veicolo(m) {}
    std::string descrizione() override { return marca + ": moto a due ruote"; }
};

int main() {
    Veicolo* veicoli[] = { new Auto("Fiat"), new Moto("Ducati") };

    for (Veicolo* v : veicoli) {
        std::cout << v->descrizione() << "\n";
    }

    for (Veicolo* v : veicoli) delete v;
    return 0;
}
