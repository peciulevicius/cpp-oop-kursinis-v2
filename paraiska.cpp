// paraiska.cpp
#include "paraiska.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

// Konstruktorius
Paraiska::Paraiska(string vardas, int sklypo, float plt)
    : ukininkoVardas(vardas), sklypoNr(sklypo), plotas(plt), patvirtinta(false) {}

// Paraiškos informacijos rodymas
void Paraiska::rodytiInfo() {
    cout << "Ūkininko vardas: " << ukininkoVardas << endl;
    cout << "Sklypo numeris: " << sklypoNr << endl;
    cout << "Sklypo plotas: " << plotas << " ha" << endl;
    cout << "Paraiška " << (patvirtinta ? "patvirtinta" : "nepatvirtinta") << endl;
}

// Paraiškos patvirtinimas
void Paraiska::tvirtinti() {
    patvirtinta = true;
    statusas = "patvirtinta";
    cout << "Paraiška patvirtinta." << endl;
}

void Paraiska::atmesti() {
    statusas = "atmesta";
    cout << "Paraiška atmesta." << endl;
}

// Išsaugojimas į failą
void Paraiska::iseitiIFaila(const string& failoPavadinimas) {
    vector<Paraiska> paraiskos = nuskaitytiIsFailo(failoPavadinimas);
    ofstream out(failoPavadinimas, ios::trunc); // Open the file in truncate mode to overwrite it
    if (out.is_open()) {

        out << ukininkoVardas << "; " << sklypoNr << "; " << plotas << "; " << statusas << endl;
        out.close();
    } else {
        cout << "Nepavyko atidaryti failo." << endl;
    }
}
// Nuskaityti iš failo
vector<Paraiska> Paraiska::nuskaitytiIsFailo(const string& failoPavadinimas) {
    ifstream in(failoPavadinimas);
    vector<Paraiska> paraiskos;
    string eilute;

    // Nuskaityti eilutes iš failo
    while (getline(in, eilute)) {
        stringstream ss(eilute);
        string vardas;
        int sklypoNr;
        float plotas;
        string statusas;

        // Išskaidome eilutę pagal ';' ženklą
        getline(ss, vardas, ';');
        ss >> sklypoNr;
        ss.ignore(1, ';');  // Ignoruoti tarpus po sklypoNr
        ss >> plotas;
        ss.ignore(1, ';');
        getline(ss, statusas, ';');

        Paraiska paraiska(vardas, sklypoNr, plotas);
        paraiska.statusas = statusas;
        paraiskos.push_back(paraiska);
//        // Sukuriame paraišką ir pridedame ją į vektorių
        paraiskos.push_back(Paraiska(vardas, sklypoNr, plotas));
//        paraiskos.back().patvirtinta = patvirtintaBool;
    }


    in.close();
    return paraiskos;
}
