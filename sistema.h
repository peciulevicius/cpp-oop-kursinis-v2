// sistema.h
#ifndef SISTEMA_H
#define SISTEMA_H
#include <iostream>
#include <vector>
#include "paraiska.h"
using namespace std;

class Sistema {
public:
    virtual ~Sistema() = default; // Add a virtual destructor
    virtual void prisijungti() = 0;
};
#endif
