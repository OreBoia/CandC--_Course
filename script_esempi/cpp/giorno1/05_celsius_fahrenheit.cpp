// Libreria per input/output con std::cin e std::cout.
#include <iostream>

// Funzione principale del programma.
int main() {
    // Temperatura in Celsius da leggere in input.
    double celsius;

    // Chiede il valore in Celsius.
    std::cout << "Inserisci i gradi Celsius: ";
    // Legge il valore inserito.
    std::cin >> celsius;

    // Conversione da Celsius a Fahrenheit.
    double fahrenheit = celsius * 9.0 / 5.0 + 32.0;
    // Stampa il risultato della conversione.
    std::cout << celsius << " C corrispondono a " << fahrenheit << " F\n";

    // Uscita corretta del programma.
    return 0;
}
