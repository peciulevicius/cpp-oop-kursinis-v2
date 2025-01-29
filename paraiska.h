

#ifndef PARAISKA_H
#define PARAISKA_H
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Paraiska {
public:
    // Konstruktorius
    Paraiska(string vardas, int sklypo, float plt);

    // Metodai
    void rodytiInfo();                    // Paraiškos informacijos rodymas
    void tvirtinti();                     // Paraiškos patvirtinimas
    void atmesti();
    void iseitiIFaila(const string& failoPavadinimas);  // Išsaugojimas į failą
    static vector<Paraiska> nuskaitytiIsFailo(const string& failoPavadinimas); // Nuskaityti iš failo
    float plotas;
    bool patvirtinta;
    string ukininkoVardas;
    int sklypoNr;
    std::string statusas; // "neivertinta", "patvirtinta", "atmesta"
};

#endif