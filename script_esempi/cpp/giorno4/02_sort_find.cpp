#include <iostream>
#include <vector>
#include <algorithm>   // sort, find, max_element...

int main() {
    std::vector<int> v = {5, 2, 8, 1, 9};

    std::sort(v.begin(), v.end());                  // ordina
    auto maxIt = std::max_element(v.begin(), v.end());

    std::cout << "Massimo: " << *maxIt << "\n";
    for (int x : v) std::cout << x << " ";          // 1 2 5 8 9
    std::cout << "\n";

    int cercato = 8;
    auto trovato = std::find(v.begin(), v.end(), cercato);
    if (trovato != v.end()) {
        std::cout << cercato << " trovato nel vector.\n";
    } else {
        std::cout << cercato << " non presente.\n";
    }
    return 0;
}
