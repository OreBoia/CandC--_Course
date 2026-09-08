// Libreria per input/output tramite stream (std::cout, std::cin).
#include <iostream>

// Funzione principale da cui parte il programma.
int main() {
    // std::cout invia testo all'output standard; std::endl va a capo e forza il flush del buffer.
    std::cout << "Ciao, mondo!" << std::endl;
    // Restituisce 0: programma terminato con successo.
    return 0;
}
