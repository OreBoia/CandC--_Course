#include <iostream>

void scambia(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 10;
    int y = 20;

    std::cout << "Prima dello scambio: x = " << x << ", y = " << y << '\n';
    scambia(x, y);
    std::cout << "Dopo lo scambio: x = " << x << ", y = " << y << '\n';
    return 0;
}
