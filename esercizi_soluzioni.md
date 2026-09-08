# Soluzioni degli esercizi

Raccolta delle soluzioni commentate di tutti gli esercizi del corso, organizzate per
giorno e linguaggio. Le soluzioni sono pensate come **riferimento per il formatore**:
spesso esiste più di un modo corretto di risolvere lo stesso problema.

> Suggerimento: distribuire le soluzioni **dopo** che gli studenti hanno provato da
> soli. L'errore e il tentativo sono parte dell'apprendimento.

---

## G1-C — Giorno 1, C

**G1-C-1 — Saluto personalizzato**

```c
#include <stdio.h>
int main(void) {
    char nome[] = "Mario";
    printf("Ciao, %s!\n", nome);
    return 0;
}
```

**G1-C-2 — Calcolatrice rettangolo**

```c
#include <stdio.h>
int main(void) {
    int base, altezza;
    printf("Base: ");    scanf("%d", &base);
    printf("Altezza: "); scanf("%d", &altezza);
    printf("Perimetro: %d\n", 2 * (base + altezza));
    printf("Area: %d\n", base * altezza);
    return 0;
}
```

**G1-C-3 — Conversione temperature**

```c
#include <stdio.h>
int main(void) {
    double c;
    printf("Gradi Celsius: ");
    scanf("%lf", &c);                 // %lf per leggere un double
    double f = c * 9.0 / 5.0 + 32;    // 9.0/5.0 evita la divisione intera
    printf("Fahrenheit: %.2f\n", f);
    return 0;
}
```

**G1-C-4 — Media di tre numeri**

```c
#include <stdio.h>
int main(void) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    printf("Media: %.2f\n", (a + b + c) / 3.0);   // /3.0 forza il double
    return 0;
}
```

**G1-C-5 — Scambio di valori**

```c
#include <stdio.h>
int main(void) {
    int a = 5, b = 9;
    printf("Prima: a=%d b=%d\n", a, b);
    int tmp = a; a = b; b = tmp;
    printf("Dopo:  a=%d b=%d\n", a, b);
    return 0;
}
```

---

## G1-C++ — Giorno 1, C++

**G1-CPP-1 — Presentazione**

```cpp
#include <iostream>
#include <string>
int main() {
    std::string nome; int eta;
    std::cout << "Nome: "; std::cin >> nome;
    std::cout << "Eta: ";  std::cin >> eta;
    std::cout << "Ciao " << nome << ", hai " << eta << " anni.\n";
}
```

**G1-CPP-2 — Concatenazione stringhe**

```cpp
#include <iostream>
#include <string>
int main() {
    std::string nome, cognome;
    std::cin >> nome >> cognome;
    std::string completo = cognome + " " + nome;
    std::cout << completo << " (" << completo.length() << " caratteri)\n";
}
```

**G1-CPP-3 — Calcolatrice interattiva**

```cpp
#include <iostream>
int main() {
    double a, b;
    std::cin >> a >> b;
    std::cout << "Somma: "      << a + b << "\n";
    std::cout << "Differenza: " << a - b << "\n";
    std::cout << "Prodotto: "   << a * b << "\n";
    if (b != 0) std::cout << "Quoziente: " << a / b << "\n";
    else        std::cout << "Divisione per zero!\n";
}
```

**G1-CPP-4 — Celsius → Fahrenheit in C++**

```cpp
#include <iostream>
int main() {
    double c;
    std::cout << "Celsius: "; std::cin >> c;
    std::cout << "Fahrenheit: " << c * 9.0 / 5.0 + 32 << "\n";
}
```

**G1-CPP-5 — Riga intera**

```cpp
#include <iostream>
#include <string>
int main() {
    std::string frase;
    std::getline(std::cin, frase);
    std::cout << "[" << frase.length() << "] " << frase << "\n";
}
```

---

## G2-C — Giorno 2, C

**G2-C-1 — Pari o dispari**

```c
#include <stdio.h>
int main(void) {
    int n; scanf("%d", &n);
    printf(n % 2 == 0 ? "Pari\n" : "Dispari\n");
}
```

**G2-C-2 — Tabellina**

```c
#include <stdio.h>
int main(void) {
    int n; scanf("%d", &n);
    for (int i = 1; i <= 10; i++)
        printf("%d x %d = %d\n", n, i, n * i);
}
```

**G2-C-3 — Funzione massimo**

```c
#include <stdio.h>
int massimo(int a, int b) { return (a > b) ? a : b; }
int main(void) {
    printf("%d\n", massimo(8, 3));
}
```

**G2-C-4 — Somma di un array**

```c
#include <stdio.h>
int somma_array(int v[], int n) {
    int s = 0;
    for (int i = 0; i < n; i++) s += v[i];
    return s;
}
int main(void) {
    int dati[6] = {1, 2, 3, 4, 5, 6};
    printf("%d\n", somma_array(dati, 6));   // 21
}
```

**G2-C-5 — Conta vocali**

```c
#include <stdio.h>
#include <string.h>
int main(void) {
    char parola[100]; scanf("%99s", parola);
    int conteggio = 0;
    for (int i = 0; parola[i] != '\0'; i++) {
        char c = parola[i];
        if (c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||
            c=='A'||c=='E'||c=='I'||c=='O'||c=='U') conteggio++;
    }
    printf("Vocali: %d\n", conteggio);
}
```

**G2-C-6 — Numero primo**

```c
#include <stdio.h>
int e_primo(int n) {
    if (n < 2) return 0;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return 0;
    return 1;
}
int main(void) {
    for (int i = 2; i <= 50; i++)
        if (e_primo(i)) printf("%d ", i);
    printf("\n");
}
```

---

## G2-C++ — Giorno 2, C++

**G2-CPP-1 — Overloading**

```cpp
#include <iostream>
int area(int lato)            { return lato * lato; }
int area(int base, int altezza) { return base * altezza; }
int main() {
    std::cout << area(4) << "\n";       // quadrato: 16
    std::cout << area(3, 5) << "\n";    // rettangolo: 15
}
```

**G2-CPP-2 — Scambio con riferimenti**

```cpp
#include <iostream>
void scambia(int& a, int& b) { int t = a; a = b; b = t; }
int main() {
    int x = 1, y = 2;
    scambia(x, y);
    std::cout << x << " " << y << "\n";   // 2 1
}
```

**G2-CPP-3 — Gestione lista**

```cpp
#include <iostream>
#include <vector>
#include <string>
int main() {
    std::vector<std::string> nomi;
    nomi.push_back("Anna");
    nomi.push_back("Marco");
    nomi.push_back("Sara");
    for (const std::string& n : nomi) std::cout << n << "\n";
}
```

**G2-CPP-4 — Massimo del vector**

```cpp
#include <iostream>
#include <vector>
int massimo(const std::vector<int>& v) {
    int m = v[0];
    for (int x : v) if (x > m) m = x;
    return m;
}
int main() {
    std::cout << massimo({3, 9, 2, 7}) << "\n";   // 9
}
```

**G2-CPP-5 — Stringa al contrario**

```cpp
#include <iostream>
#include <string>
int main() {
    std::string s; std::cin >> s;
    for (int i = (int)s.length() - 1; i >= 0; i--)
        std::cout << s[i];
    std::cout << "\n";
}
```

**G2-CPP-6 — Filtro pari**

```cpp
#include <iostream>
#include <vector>
int main() {
    std::vector<int> v = {1,2,3,4,5,6,7,8};
    std::vector<int> pari;
    for (int x : v) if (x % 2 == 0) pari.push_back(x);
    for (int x : pari) std::cout << x << " ";   // 2 4 6 8
    std::cout << "\n";
}
```

---

## G3-C — Giorno 3, C

**G3-C-1 — Scambio con puntatori**

```c
#include <stdio.h>
void scambia(int *a, int *b) { int t = *a; *a = *b; *b = t; }
int main(void) {
    int x = 1, y = 2;
    scambia(&x, &y);
    printf("%d %d\n", x, y);   // 2 1
}
```

**G3-C-2 — Min e max via puntatori**

```c
#include <stdio.h>
void min_max(int v[], int n, int *min, int *max) {
    *min = *max = v[0];
    for (int i = 1; i < n; i++) {
        if (v[i] < *min) *min = v[i];
        if (v[i] > *max) *max = v[i];
    }
}
int main(void) {
    int dati[] = {4, 1, 9, 3, 7};
    int mn, mx;
    min_max(dati, 5, &mn, &mx);
    printf("min=%d max=%d\n", mn, mx);
}
```

**G3-C-3 — Array dinamico**

```c
#include <stdio.h>
#include <stdlib.h>
int main(void) {
    int n; scanf("%d", &n);
    int *a = malloc(n * sizeof(int));
    if (!a) return 1;
    int somma = 0;
    for (int i = 0; i < n; i++) { scanf("%d", &a[i]); somma += a[i]; }
    printf("Somma: %d\n", somma);
    free(a);
}
```

**G3-C-4 — Struct rettangolo**

```c
#include <stdio.h>
struct Rettangolo { double base, altezza; };
double area(struct Rettangolo r) { return r.base * r.altezza; }
int main(void) {
    struct Rettangolo r = {4.0, 2.5};
    printf("Area: %.2f\n", area(r));
}
```

**G3-C-5 — Rubrica**

```c
#include <stdio.h>
#include <string.h>
struct Persona { char nome[50]; int eta; };
int main(void) {
    struct Persona rubrica[3] = {
        {"Anna", 30}, {"Luca", 25}, {"Sara", 40}
    };
    for (int i = 0; i < 3; i++)
        printf("%s, %d anni\n", rubrica[i].nome, rubrica[i].eta);
}
```

**G3-C-6 — Inversione array in-place**

```c
#include <stdio.h>
void inverti(int *v, int n) {
    int *inizio = v, *fine = v + n - 1;
    while (inizio < fine) {
        int t = *inizio; *inizio = *fine; *fine = t;
        inizio++; fine--;
    }
}
int main(void) {
    int a[] = {1, 2, 3, 4, 5};
    inverti(a, 5);
    for (int i = 0; i < 5; i++) printf("%d ", a[i]);  // 5 4 3 2 1
    printf("\n");
}
```

---

## G3-C++ — Giorno 3, C++

**G3-CPP-1 — Classe Rettangolo**

```cpp
#include <iostream>
class Rettangolo {
    double base, altezza;
public:
    Rettangolo(double b, double a) : base(b), altezza(a) {}
    double area()      { return base * altezza; }
    double perimetro() { return 2 * (base + altezza); }
};
int main() {
    Rettangolo r(4, 3);
    std::cout << r.area() << " " << r.perimetro() << "\n";  // 12 14
}
```

**G3-CPP-2 — Da struct a classe**

```cpp
#include <iostream>
#include <string>
class Persona {
    std::string nome; int eta;
public:
    Persona(std::string n, int e) : nome(n), eta(e) {}
    void presentati() { std::cout << nome << ", " << eta << " anni\n"; }
    int getEta() { return eta; }
};
int main() {
    Persona p("Luca", 28);
    p.presentati();
}
```

**G3-CPP-3 — Costruttore e distruttore**

```cpp
#include <iostream>
class Cronometro {
public:
    Cronometro()  { std::cout << "Avviato\n"; }
    ~Cronometro() { std::cout << "Fermato\n"; }
};
int main() {
    Cronometro c;
    std::cout << "In esecuzione...\n";
}   // qui scatta il distruttore
```

**G3-CPP-4 — Contatore incapsulato**

```cpp
#include <iostream>
class Contatore {
    int valore_;
public:
    Contatore() : valore_(0) {}
    void incrementa() { valore_++; }
    void decrementa() { if (valore_ > 0) valore_--; }
    int valore()      { return valore_; }
};
int main() {
    Contatore c;
    c.incrementa(); c.incrementa(); c.decrementa();
    std::cout << c.valore() << "\n";   // 1
}
```

**G3-CPP-5 — Conto bancario esteso**

```cpp
#include <iostream>
#include <string>
#include <vector>
class ContoBancario {
    std::string titolare; double saldo;
    std::vector<std::string> storico;
public:
    ContoBancario(std::string n, double s) : titolare(n), saldo(s) {}
    void deposita(double i) { saldo += i; storico.push_back("Deposito"); }
    void preleva(double i)  {
        if (i <= saldo) { saldo -= i; storico.push_back("Prelievo"); }
    }
    void stampaStorico() {
        for (const auto& op : storico) std::cout << op << "\n";
    }
};
int main() {
    ContoBancario c("Giulia", 100);
    c.deposita(50); c.preleva(30);
    c.stampaStorico();
}
```

**G3-CPP-6 — Frazione**

```cpp
#include <iostream>
class Frazione {
    int num, den;
public:
    Frazione(int n, int d) : num(n), den(d) {}
    Frazione somma(const Frazione& a) {
        return Frazione(num * a.den + a.num * den, den * a.den);
    }
    void stampa() { std::cout << num << "/" << den << "\n"; }
};
int main() {
    Frazione a(1, 2), b(1, 3);
    a.somma(b).stampa();   // 5/6
}
```

---

## G4-C — Giorno 4, C

**G4-C-1 — Scrivi e rileggi**

```c
#include <stdio.h>
int main(void) {
    FILE *f = fopen("numeri.txt", "w");
    for (int i = 0; i < 5; i++) {
        int x; scanf("%d", &x);
        fprintf(f, "%d\n", x);
    }
    fclose(f);

    f = fopen("numeri.txt", "r");
    int x, somma = 0;
    while (fscanf(f, "%d", &x) == 1) somma += x;
    fclose(f);
    printf("Somma: %d\n", somma);
}
```

**G4-C-2 — Conta righe**

```c
#include <stdio.h>
int main(void) {
    FILE *f = fopen("numeri.txt", "r");
    if (!f) return 1;
    int righe = 0, c;
    while ((c = fgetc(f)) != EOF)
        if (c == '\n') righe++;
    fclose(f);
    printf("Righe: %d\n", righe);
}
```

**G4-C-3 — Macro MAX**

```c
#include <stdio.h>
#define MAX(a, b) ((a) > (b) ? (a) : (b))
int main(void) {
    printf("%d\n", MAX(3, 7));        // 7
    printf("%d\n", MAX(2 + 1, 2));    // 3 (le parentesi salvano il risultato)
}
```

**G4-C-4 — Progetto multi-file**

`geometria.h`

```c
#ifndef GEOMETRIA_H
#define GEOMETRIA_H
double area_cerchio(double r);
double area_quadrato(double l);
#endif
```

`geometria.c`

```c
#include "geometria.h"
double area_cerchio(double r) { return 3.14159 * r * r; }
double area_quadrato(double l) { return l * l; }
```

`main.c`

```c
#include <stdio.h>
#include "geometria.h"
int main(void) {
    printf("%.2f\n", area_cerchio(2));
    printf("%.2f\n", area_quadrato(3));
}
```

Compilazione: `gcc main.c geometria.c -o programma`

**G4-C-5 — Mini rubrica su file (traccia)**
Struttura suggerita: ciclo con menu (`switch`), opzione 1 = `fopen` in `"a"` e
`fprintf` dell'articolo; opzione 2 = `fopen` in `"r"` e `fgets` riga per riga;
opzione 3 = `remove("spesa.txt")` per azzerare; opzione 4 = uscita. È un esercizio
integrativo: la soluzione esatta dipende dalle scelte dello studente.

---

## G4-C++ — Giorno 4, C++

**G4-CPP-1 — Mappa parole**

```cpp
#include <iostream>
#include <map>
#include <string>
int main() {
    std::map<std::string, int> conteggio;
    std::string parola;
    while (std::cin >> parola) conteggio[parola]++;
    for (const auto& p : conteggio)
        std::cout << p.first << ": " << p.second << "\n";
}
```

**G4-CPP-2 — Ordina e cerca**

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
int main() {
    std::vector<int> v = {5, 2, 8, 1, 9};
    std::sort(v.begin(), v.end());
    int target; std::cin >> target;
    if (std::find(v.begin(), v.end(), target) != v.end())
        std::cout << "Trovato\n";
    else
        std::cout << "Non trovato\n";
}
```

**G4-CPP-3 — Template minimo**

```cpp
#include <iostream>
template <typename T>
T minimo(T a, T b) { return (a < b) ? a : b; }
int main() {
    std::cout << minimo(3, 7) << "\n";
    std::cout << minimo(2.5, 1.1) << "\n";
    std::cout << minimo('z', 'a') << "\n";
}
```

**G4-CPP-4 — Gerarchia di forme**

```cpp
#include <iostream>
class Forma {
public:
    virtual double area() = 0;
    virtual ~Forma() {}
};
class Triangolo : public Forma {
    double base, altezza;
public:
    Triangolo(double b, double h) : base(b), altezza(h) {}
    double area() override { return base * altezza / 2; }
};
class Rettangolo : public Forma {
    double base, altezza;
public:
    Rettangolo(double b, double h) : base(b), altezza(h) {}
    double area() override { return base * altezza; }
};
int main() {
    Forma* forme[] = { new Triangolo(4, 3), new Rettangolo(4, 3) };
    for (Forma* f : forme) std::cout << f->area() << "\n";  // 6  12
    for (Forma* f : forme) delete f;
}
```

**G4-CPP-5 — Veicoli**

```cpp
#include <iostream>
#include <string>
class Veicolo {
public:
    virtual std::string descrizione() { return "Un veicolo"; }
    virtual ~Veicolo() {}
};
class Auto : public Veicolo {
public:
    std::string descrizione() override { return "Un'auto a 4 ruote"; }
};
class Moto : public Veicolo {
public:
    std::string descrizione() override { return "Una moto a 2 ruote"; }
};
int main() {
    Veicolo* v[] = { new Auto(), new Moto() };
    for (Veicolo* x : v) std::cout << x->descrizione() << "\n";
    for (Veicolo* x : v) delete x;
}
```

**G4-CPP-6 — Objective-C (traccia concettuale)**

```objc
@interface Persona : NSObject
@property NSString *nome;
@property int eta;
- (void)descrivi;
@end

@implementation Persona
- (void)descrivi {
    NSLog(@"%@, %d anni", self.nome, self.eta);
}
@end
```

Punto della discussione: la chiamata `[p descrivi]` (sintassi a messaggi di
Objective-C) corrisponde concettualmente a `p.descrivi()` in C++. Cambia la sintassi,
non l'idea di "chiedere a un oggetto di fare qualcosa".
