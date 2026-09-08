// Libreria standard per input/output con stream.
#include <iostream>

// Punto di ingresso del programma.
int main() {
    // Due numeri in virgola mobile per i calcoli.
    double a;
    double b;

    // Richiede due numeri all'utente.
    std::cout << "Inserisci due numeri: ";
    // Legge i due valori da tastiera.
    std::cin >> a >> b;

    // Operazioni aritmetiche di base.
    std::cout << "Somma: " << a + b << '\n';
    std::cout << "Differenza: " << a - b << '\n';
    std::cout << "Prodotto: " << a * b << '\n';

    // Controllo per evitare la divisione per zero.
    if (b != 0) {
        // Esegue la divisione solo se il divisore e valido.
        std::cout << "Quoziente: " << a / b << '\n';
    } else {
        // Messaggio mostrato quando b e zero.
        std::cout << "Quoziente: impossibile (divisione per zero)\n";
    }

    // Fine corretta del programma.
    return 0;
}
