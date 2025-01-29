#ifndef UKININKAS_H
#define UKININKAS_H
#include "sistema.h"

class Ukininkas : public Sistema {
private:
    string vardas, pavarde;
    string asmensKodas;
    int sklypoNr;
    float plotas;
public:
    void prisijungti() override;
    void pildytiParaiska();
    void perziuretiParaiskas();
};
#endif