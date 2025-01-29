#include "sistema.h"
#include "ukininkas.h"
#include "vertintojas.h"

void paleistiSistema() {
    char pasirinkimas;
    cout << "Sveiki atvykę į ūkininkų paraiškų sistemą!" << endl;
    cout << "Pasirinkite savo rolę: (u - ūkininkas, v - vertintojas): ";
    cin >> pasirinkimas;

    Sistema* vartotojas = nullptr;

    if (pasirinkimas == 'u') {
        vartotojas = new Ukininkas();
    }
    else if (pasirinkimas == 'v') {
        vartotojas = new Vertintojas();
    }
    else {
        cout << "Neteisingas pasirinkimas! Programa baigiama." << endl;
        return;
    }

    vartotojas->prisijungti();
    delete vartotojas;
}