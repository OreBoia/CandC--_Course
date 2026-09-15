#include <iostream>
#include <string>

class Persona 
{
    private:                       // accessibili solo dall'interno della classe
        std::string nome;
        int eta;

    public:                        // interfaccia visibile dall'esterno
        Persona(std::string n, int e) {
            nome = n;
            eta = e;
        }

        void presentati() {
            std::cout << "Mi chiamo " << nome << " e ho " << eta << " anni.\n";
        }

        int getEta() {
            return eta;
        }

        void setEta(int nuovaEta){
            eta = nuovaEta;
        }
};

int main() {
    Persona p("Maria", 30);
    p.presentati();
    std::cout << "Eta: " << p.getEta() << "\n";
    p.setEta(31);
    std::cout << "Eta: " << p.getEta() << "\n";
    // p.eta = 99;   // errore di compilazione: 'eta' e' private

    return 0;
}
