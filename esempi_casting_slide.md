# Esempi semplici di casting e conversione (C e C++)

## C

### 1) Conversione implicita int -> double

```c
int a = 5;
double x = a;
```

Spiegazione: conversione implicita da intero a decimale, senza perdita di informazione.

### 2) Casting esplicito per divisione reale

```c
int a = 5, b = 2;
double q = (double)a / b;
```

Spiegazione: casting esplicito per ottenere divisione reale (2.5) invece di divisione intera.

### 3) Casting da double a int

```c
double prezzo = 9.99;
int p = (int)prezzo;
```

Spiegazione: casting da decimale a intero, la parte dopo la virgola viene scartata.

### 4) Conversione char -> int (ASCII)

```c
char c = 'A';
int codice = (int)c;
```

Spiegazione: conversione del carattere nel suo codice numerico ASCII.

## C++

### 1) Conversione implicita int -> double

```cpp
int a = 5;
double x = a;
```

Spiegazione: conversione implicita da int a double.

### 2) Cast esplicito consigliato in C++

```cpp
int a = 5, b = 2;
double q = static_cast<double>(a) / b;
```

Spiegazione: cast esplicito in stile C++, più leggibile e consigliato.

### 3) Cast da double a int

```cpp
double prezzo = 9.99;
int p = static_cast<int>(prezzo);
```

Spiegazione: conversione esplicita con perdita della parte decimale.

### 4) Conversione char -> int

```cpp
char c = 'A';
int codice = static_cast<int>(c);
```

Spiegazione: conversione esplicita da char a valore numerico del carattere.
