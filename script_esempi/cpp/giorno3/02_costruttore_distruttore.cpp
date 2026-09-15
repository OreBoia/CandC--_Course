#include <iostream>

class Risorsa {
    public:
        Risorsa()  { std::cout << "Risorsa acquisita\n"; }
        ~Risorsa() { std::cout << "Risorsa rilasciata\n"; }
};

int main() {
    std::cout << "Inizio\n";
    {
        Risorsa r;    // qui parte il costruttore
        std::cout << "Uso la risorsa\n";
    }                 // uscendo dal blocco parte il distruttore
    std::cout << "Fine\n";

    return 0;
}
