# Script di esempio per la classe

Questa cartella contiene esempi pronti da mostrare in aula, organizzati per linguaggio:

- `c/` -> esempi base in C
- `c/giorno2/` -> esempi su controllo di flusso, funzioni, array e stringhe in C
- `c/giorno3/` -> esempi su puntatori, memoria dinamica e struct in C
- `c/giorno4/` -> esempi su file I/O, preprocessore e progetti multi-file in C
- `cpp/` -> esempi base in C++
- `cpp/giorno2/` -> esempi su funzioni avanzate, stringhe e vector in C++
- `cpp/giorno3/` -> esempi su classi, costruttori/distruttori e RAII in C++
- `cpp/giorno4/` -> esempi su STL, template, ereditarieta'/polimorfismo e cenno a Objective-C in C++

## Compilazione rapida

### C

```bash
gcc -Wall -Wextra nome_file.c -o nome_file
./nome_file
```

### C++

```bash
g++ -Wall -Wextra -std=c++17 nome_file.cpp -o nome_file
./nome_file
```

### Progetto multi-file (`c/giorno4/06_progetto_multifile/`)

```bash
gcc -Wall -Wextra main.c calcolatrice.c -o calcolatrice
./calcolatrice
```

### Nota su Objective-C (`cpp/giorno4/07_objc_persona.m`)

Richiede un compilatore Apple/clang con framework Foundation (tipicamente solo su
macOS): incluso come materiale di lettura, non compilabile su Linux/Windows.
