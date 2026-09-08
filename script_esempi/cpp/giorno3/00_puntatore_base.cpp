#include <iostream>

void raddoppia(int& n){
    n = n * 2;
}

int main(){
    int valore = 7;
    int& puntatore = valore;
    raddoppia(valore);
    std::cout << valore;
    return 0;
}