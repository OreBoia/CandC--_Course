// Libreria per input/output con stream.
#include <iostream>
// Libreria per il tipo std::string.
#include <string>

// Punto di ingresso del programma.
int main() {
    // Variabile intera.
    int eta = 30;
    // Variabile in virgola mobile a doppia precisione.
    double altezza = 1.75;
    // Variabile booleana (vero/falso).
    bool studente = true;
    // Stringa testuale.
    std::string nome = "Maria";

    // Operatore << concatena i dati nello stream di output.
    std::cout << "Nome: " << nome << '\n';
    std::cout << "Eta: " << eta << '\n';
    std::cout << "Altezza: " << altezza << '\n';
    // std::boolalpha fa stampare true/false invece di 1/0.
    std::cout << "Studente: " << std::boolalpha << studente << '\n';

    // Fine corretta del programma.
    return 0;
}
