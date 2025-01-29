#include "ukininkas.h"
#include "vertintojas.h"

int main() {
    char pasirinkimas;
    cout << "Sveiki! Pasirinkite vartotojo tipą: (u - ūkininkas, v - vertintojas): ";
    cin >> pasirinkimas;

    Sistema* vartotojas = nullptr;
    if (pasirinkimas == 'u') {
        vartotojas = new Ukininkas();
    }
    else if (pasirinkimas == 'v') {
        vartotojas = new Vertintojas();
    }

    if (vartotojas) {
        vartotojas->prisijungti();
        delete vartotojas;
    }
    return 0;
}
