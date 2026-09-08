# Corso di C e C++ per Principianti

Corso introduttivo della durata di **16 ore distribuite su 4 giorni**. Ogni giornata
prevede **2 ore di C** e **2 ore di C++**, così da costruire le competenze in parallelo
e rendere immediatamente visibili somiglianze e differenze tra i due linguaggi.

## Obiettivi del corso

1. **Obiettivo teorico** — comprendere cosa sono il C e il C++, la loro storia, il
   modello di compilazione, le differenze sostanziali tra i due e i rispettivi casi
   d'uso reali.
2. **Obiettivo pratico** — saper scrivere, compilare ed eseguire i programmi
   fondamentali in entrambi i linguaggi, fino alle basi della programmazione a
   oggetti in C++ e a un'introduzione di base a **Objective-C** e **Objective-C++**.

Ogni sezione contiene spiegazioni teoriche, esempi commentati e una serie di
**esercizi** da assegnare agli studenti. Le soluzioni sono raccolte in un file a parte.

## Programma sintetico

| Giorno | Modulo C (2h) | Modulo C++ (2h) |
|--------|---------------|-----------------|
| **1** | Fondamenti: tipi, variabili, I/O | Fondamenti: iostream, namespace, tipi |
| **2** | Controllo di flusso, funzioni, array, stringhe | Funzioni avanzate, `std::string`, `std::vector` |
| **3** | Puntatori, gestione memoria, struct | Programmazione a oggetti, classi, RAII |
| **4** | File I/O, preprocessore, progetti multi-file | STL, template, ereditarietà, Objective-C/C++ |

## Indice dei file

- `README.md` — questo file (panoramica, programma, setup)
- **Giorno 1**
  - `giorno1_c_fondamenti.md`
  - `giorno1_cpp_fondamenti.md`
- **Giorno 2**
  - `giorno2_c_controllo_funzioni.md`
  - `giorno2_cpp_funzioni_container.md`
- **Giorno 3**
  - `giorno3_c_puntatori_memoria.md`
  - `giorno3_cpp_oop.md`
- **Giorno 4**
  - `giorno4_c_file_progetti.md`
  - `giorno4_cpp_stl_objc.md`
- **Teoria trasversale**
  - `teoria_differenze_casi_uso.md` — differenze C vs C++ e casi d'uso
- **Esercizi**
  - `esercizi_soluzioni.md` — soluzioni commentate di tutti gli esercizi

> Consiglio didattico: leggere `teoria_differenze_casi_uso.md` a cavallo tra il
> Giorno 2 e il Giorno 3, quando gli studenti hanno già visto abbastanza codice
> per apprezzare il confronto.

## Setup dell'ambiente di sviluppo

Per seguire il corso servono un **compilatore** e un **editor di testo**.

### Compilatore

- **Linux**: `sudo apt install build-essential` (installa `gcc` e `g++`).
- **macOS**: installare gli strumenti da riga di comando con `xcode-select --install`
  (forniscono `clang`/`clang++`, necessari anche per Objective-C).
- **Windows**: installare [MSYS2](https://www.msys2.org/) e poi
  `pacman -S mingw-w64-ucrt-x86_64-gcc`, oppure usare WSL con la procedura Linux.

### Verifica dell'installazione

```bash
gcc --version      # compilatore C
g++ --version      # compilatore C++
```

### Editor consigliati

- **Visual Studio Code** con l'estensione *C/C++* di Microsoft (ottimo per principianti).
- In alternativa un IDE completo come **CLion** o **Code::Blocks**.

### Comandi base di compilazione usati nel corso

```bash
# Compilare un programma C
gcc programma.c -o programma
./programma

# Compilare un programma C++
g++ programma.cpp -o programma
./programma

# Opzioni didattiche consigliate (più avvisi = meno errori nascosti)
gcc -Wall -Wextra -std=c11   programma.c   -o programma
g++ -Wall -Wextra -std=c++17 programma.cpp -o programma
```

> `-Wall -Wextra` attivano gli avvisi del compilatore: per chi impara sono
> preziosi, perché segnalano errori logici che non bloccano la compilazione.

## Note per il formatore

- Alternare sempre teoria breve → demo dal vivo → esercizio guidato → esercizio autonomo.
- Far compilare codice agli studenti fin dal primo minuto: la sintassi si impara digitandola.
- Gli errori di compilazione sono materiale didattico: mostrarli e leggerli insieme.
- I moduli Objective-C / Objective-C++ del Giorno 4 sono **introduttivi**: servono a
  dare contesto storico e tecnologico, non a formare sviluppatori Apple.
