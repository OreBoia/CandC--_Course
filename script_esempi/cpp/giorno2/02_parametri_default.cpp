#include <iostream>
#include <string>

void saluta(std::string nome = "ospite") {
    std::cout << "Ciao, " << nome << "!\n";
}

int main() {
    saluta();
    saluta("Anna");
    return 0;
}
