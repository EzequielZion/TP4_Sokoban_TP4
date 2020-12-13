#ifndef TP4_SOKOBAN_DIRECCION_H
#define TP4_SOKOBAN_DIRECCION_H
#include "Tipos.h"
#include "Coord.h"

class Direccion {
public:
    Direccion(Nat ord);

    Direccion(PuntoCardinal pc);

    Direccion(const Direccion &dir);

    Direccion& operator=(const Direccion &dir);

    int ord() const;

    Coord proximaCoord(const Coord &coord) const;

private:
    Nat _ord{};
};


#endif //TP4_SOKOBAN_DIRECCION_H
