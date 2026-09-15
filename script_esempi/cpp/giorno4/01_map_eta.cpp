#include <iostream>
#include <map>
#include <string>

int main() {
    std::map<std::string, int> eta;
    eta["Anna"] = 30;
    eta["Marco"] = 25;

    std::cout << "Anna ha " << eta["Anna"] << " anni\n";

    for (const auto& coppia : eta) {
        std::cout << coppia.first << " -> " << coppia.second << "\n";
    }
    return 0;
}
