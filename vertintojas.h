#ifndef VERTINTOJAS_H
#define VERTINTOJAS_H
#include "sistema.h"

class Vertintojas : public Sistema {
public:
    void prisijungti() override;
    void vertintiParaiska();
    void perziuretiAktyvias();
};
#endif
