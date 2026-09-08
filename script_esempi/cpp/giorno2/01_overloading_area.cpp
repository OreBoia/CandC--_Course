#include <iostream>

double area(double lato) {
    return lato * lato;
}

double area(double base, double altezza) {
    return base * altezza;
}

int main() {
    std::cout << "Area quadrato lato 4: " << area(4.0) << '\n';
    std::cout << "Area rettangolo 4x6: " << area(4.0, 6.0) << '\n';
    return 0;
}
