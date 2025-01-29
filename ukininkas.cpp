#include "ukininkas.h"
#include "paraiska.h"
#include <iostream>
#include <fstream> // Reikia failo nuskaitymui
#include <string>

using namespace std;

void Ukininkas::prisijungti() {
    string slaptažodis;
    cout << "Įveskite ūkininko slaptažodį: ";
    cin >> slaptažodis;

    if (slaptažodis == "1234") {  // Pavyzdinis slaptažodis
        cout << "Sėkmingai prisijungėte!\n";
        char pasirinkimas;
        cout << "Pasirinkite veiksmą: (p - pildyti paraišką, s - peržiūrėti paraiškas): ";
        cin >> pasirinkimas;

        if (pasirinkimas == 'p') {
            pildytiParaiska();
        }
        else if (pasirinkimas == 's') {
            perziuretiParaiskas();
        }
        else {
            cout << "Neteisingas pasirinkimas!\n";
        }
    }
    else {
        cout << "Neteisingas slaptažodis!\n";
    }
}

void Ukininkas::pildytiParaiska() {
    cout << "Įveskite asmens kodą (11 sk.): ";
    cin >> asmensKodas;
    cout << "Įveskite vardą: ";
    cin >> vardas;
    cout << "Įveskite pavardę: ";
    cin >> pavarde;
    cout << "Įveskite sklypo numerį (5 skaičiai): ";
    cin >> sklypoNr;
    cout << "Įveskite sklypo plotą (hektarais, pvz.: 0.5): ";
    cin >> plotas;

    // Sukuriame paraišką su surinktais duomenimis
    Paraiska paraiska(vardas, sklypoNr, plotas);

    // Išsaugome paraišką faile "paraiskos.txt"
    paraiska.iseitiIFaila("paraiskos.txt");

    cout << "Paraiška sėkmingai užpildyta ir išsaugota faile!\n";
}

void Ukininkas::perziuretiParaiskas() {
    cout << "Rodomos visos jūsų paraiškos...\n";

    ifstream failas("paraiskos.txt");  // Atidarome failą skaitymui
    if (!failas) {
        cout << "Nepavyko atidaryti failo!\n";
        return;
    }

    string line;
    while (getline(failas, line)) {  // Nuskaityti kiekvieną eilutę iš failo
        cout << line << endl;  // Atspausdinti paraiškos duomenis
    }

    failas.close();  // Uždaryti failą
}
