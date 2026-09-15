#include <iostream>
#include <string>

class Animale {
protected:                         // accessibile alle classi derivate
    std::string nome;
public:
    Animale(std::string n) : nome(n) {}
    void dormi() { std::cout << nome << " dorme.\n"; }
};

class Cane : public Animale {      // Cane "e' un" Animale
public:
    Cane(std::string n) : Animale(n) {}
    void abbaia() { std::cout << nome << " abbaia: Bau!\n"; }
};

int main() {
    Cane c("Fido");
    c.dormi();      // metodo ereditato da Animale
    c.abbaia();     // metodo proprio di Cane
    return 0;
}
