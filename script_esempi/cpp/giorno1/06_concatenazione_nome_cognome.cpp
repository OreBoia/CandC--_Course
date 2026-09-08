// Libreria per input/output testuale.
#include <iostream>
// Libreria per usare std::string e metodi associati.
#include <string>

// Funzione principale del programma.
int main() {
    // Variabile per il nome.
    std::string nome;
    // Variabile per il cognome.
    std::string cognome;

    // Richiede il nome.
    std::cout << "Inserisci il nome: ";
    // Legge una parola (senza spazi).
    std::cin >> nome;

    // Richiede il cognome.
    std::cout << "Inserisci il cognome: ";
    // Legge una parola (senza spazi).
    std::cin >> cognome;

    // Concatena cognome, spazio e nome in un'unica stringa.
    std::string completo = cognome + " " + nome;
    // Stampa la stringa nel formato richiesto.
    std::cout << "Formato Cognome Nome: " << completo << '\n';
    // length() restituisce il numero totale di caratteri della stringa.
    std::cout << "Lunghezza totale: " << completo.length() << '\n';

    // Terminazione corretta del programma.
    return 0;
}
