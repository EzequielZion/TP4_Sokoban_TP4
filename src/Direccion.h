//
// Created by santi on 12/7/2020.
//

#ifndef TP4_SOKOBAN_DIRECCION_H
#define TP4_SOKOBAN_DIRECCION_H
#include "Tipos.h"

class Direccion {
public:

    Direccion()

    Direccion(PuntoCardinal pc);

    Direccion& operator=(const Direccion &dir);

    int ord();

private:
    Nat orden;

};


#endif //TP4_SOKOBAN_DIRECCION_H
