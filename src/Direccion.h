//
// Created by santi on 12/7/2020.
//

#ifndef TP4_SOKOBAN_DIRECCION_H
#define TP4_SOKOBAN_DIRECCION_H
#include "Tipos.h"
#include "Coord.h"

class Direccion {
public:

    Direccion(PuntoCardinal pc);

    Direccion& operator=(const Direccion &dir);

    int ord() const;

    Coord proximaCoord(const Coord &coord);


private:
    Nat _ord;

};


#endif //TP4_SOKOBAN_DIRECCION_H
