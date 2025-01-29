#include "vertintojas.h"
#include <iostream>
#include <vector>
#include "paraiska.h"
#include <fstream>  // Reikalinga failo nuskaitymui

using namespace std;

void Vertintojas::prisijungti() {
    cout << "Vertintojas prisijungė prie sistemos." << endl;

    // Čia galime pridėti papildomą funkcionalumą, jei vertintojas nori atlikti tam tikrus veiksmus po prisijungimo.
    char pasirinkimas;
    cout << "Pasirinkite veiksmą: (v - vertinti paraiškas, a - peržiūrėti aktyvias paraiškas): ";
    cin >> pasirinkimas;

    if (pasirinkimas == 'v') {
        vertintiParaiska();
    }
    else if (pasirinkimas == 'a') {
        perziuretiAktyvias();
    }
    else {
        cout << "Neteisingas pasirinkimas!\n";
    }
}

// Paraiškų vertinimas
void Vertintojas::vertintiParaiska() {
    cout << "Vertinimas prasideda..." << endl;

    // Nuskaityti paraiškas iš failo
    vector<Paraiska> paraiskos = Paraiska::nuskaitytiIsFailo("paraiskos.txt");

    // Jei nėra paraiškų, pranešame vartotojui
    if (paraiskos.empty()) {
        cout << "Nėra paraiškų vertinimui.\n";
        return;
    }

    // Rodome informaciją apie paraiškas
    for (size_t i = 0; i < paraiskos.size(); ++i) {
        cout << i + 1 << ". ";
        paraiskos[i].rodytiInfo();
    }

    // Pasirinkti paraišką vertinimui
    int pasirinkimas;
    cout << "Pasirinkite paraiškos numerį vertinimui: ";
    cin >> pasirinkimas;

    if (pasirinkimas < 1 || pasirinkimas > paraiskos.size()) {
        cout << "Neteisingas pasirinkimas!\n";
        return;
    }

    // Vertiname pasirinktą paraišką
    Paraiska& pasirinktaParaiska = paraiskos[pasirinkimas - 1];
    char veiksmas;
    cout << "Pasirinkite veiksmą: (t - tvirtinti, a - atmesti): ";
    cin >> veiksmas;

    if (veiksmas == 't') {
        pasirinktaParaiska.tvirtinti();
        cout << "Paraiška patvirtinta!\n";
    } else if (veiksmas == 'a') {
        pasirinktaParaiska.atmesti();
        cout << "Paraiška atmesta.\n";
    } else {
        cout << "Neteisingas pasirinkimas!\n";
        return;
    }

    // Įrašome pakeitimus į failą
    pasirinktaParaiska.iseitiIFaila("paraiskos.txt");
}

void Vertintojas::perziuretiAktyvias() {
    cout << "Peržiūrimos aktyvios paraiškos..." << endl;

    // Nuskaityti paraiškas iš failo
    vector<Paraiska> paraiskos = Paraiska::nuskaitytiIsFailo("paraiskos.txt");

    if (paraiskos.empty()) {
        cout << "Nėra aktyvių paraiškų.\n";
        return;
    }

    // Rodome tik aktyvias paraiškas
    for (auto& paraiska : paraiskos) {
        if (!paraiska.patvirtinta) {
            paraiska.rodytiInfo();
        }
    }
}
