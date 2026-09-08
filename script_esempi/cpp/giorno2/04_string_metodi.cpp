#include <iostream>
#include <string>

int main() {
    std::string testo = "Programmazione";

    std::cout << "Stringa iniziale: " << testo << '\n';
    std::cout << "Lunghezza: " << testo.length() << '\n';
    std::cout << "Prime 5 lettere: " << testo.substr(0, 5) << '\n';
    std::cout << "Primo carattere: " << testo[0] << '\n';

    testo += " C++";
    std::cout << "Dopo concatenazione: " << testo << '\n';

    if (testo.find("C++") != std::string::npos) {
        std::cout << "La stringa contiene C++\n";
    }

    return 0;
}
