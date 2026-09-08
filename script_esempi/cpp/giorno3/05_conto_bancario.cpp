#include <iostream>
#include <string>

class ContoBancario {
private:
    std::string titolare;
    double saldo;

public:
    ContoBancario(std::string nome, double iniziale)
        : titolare(nome), saldo(iniziale) {}

    void deposita(double importo) {
        if (importo > 0) {
            saldo += importo;
        }
    }

    bool preleva(double importo) {
        if (importo > 0 && importo <= saldo) {
            saldo -= importo;
            return true;
        }
        return false;    // fondi insufficienti
    }

    void stampaSaldo() {
        std::cout << titolare << ": " << saldo << " EUR\n";
    }
};

int main() {
    ContoBancario c("Giulia", 100.0);
    c.deposita(50);

    if (!c.preleva(200)) {
        std::cout << "Prelievo rifiutato: fondi insufficienti\n";
    }
    c.preleva(30);
    c.stampaSaldo();

    return 0;
}
