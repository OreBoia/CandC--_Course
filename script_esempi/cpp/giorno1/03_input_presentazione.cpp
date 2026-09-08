// Libreria per input/output con std::cin e std::cout.
#include <iostream>
// Libreria per utilizzare std::string.
#include <string>

// Funzione principale del programma.
int main() {
    // Variabile stringa per il nome.
    std::string nome;
    // Variabile intera per l'eta.
    int eta;

    // Chiede il nome all'utente.
    std::cout << "Come ti chiami? ";
    // Legge una parola (si ferma al primo spazio).
    std::cin >> nome;

    // Chiede l'eta all'utente.
    std::cout << "Quanti anni hai? ";
    // Legge un numero intero.
    std::cin >> eta;

    // Stampa un messaggio di presentazione con un piccolo calcolo.
    std::cout << "Ciao " << nome << ", tra 10 anni avrai " << eta + 10 << " anni.\n";
    // Uscita corretta del programma.
    return 0;
}
