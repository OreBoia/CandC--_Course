// Libreria per input/output su console.
#include <iostream>
// Libreria per il tipo std::string.
#include <string>

// Punto di ingresso del programma.
int main() {
    // Stringa che conterra l'intera frase inserita.
    std::string frase;

    // Richiede una frase completa all'utente.
    std::cout << "Scrivi una frase completa: ";
    // getline legge tutta la riga, inclusi gli spazi.
    std::getline(std::cin, frase);

    // Mostra quanti caratteri contiene la frase.
    std::cout << "Hai scritto " << frase.length() << " caratteri.\n";
    // Stampa la frase inserita.
    std::cout << "Frase: " << frase << '\n';

    // Fine corretta del programma.
    return 0;
}
