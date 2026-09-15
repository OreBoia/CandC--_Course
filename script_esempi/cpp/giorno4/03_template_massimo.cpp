#include <iostream>

template <typename T>
T massimo(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    std::cout << massimo(3, 7) << "\n";        // int
    std::cout << massimo(2.5, 1.2) << "\n";    // double
    std::cout << massimo('a', 'z') << "\n";    // char
    return 0;
}
