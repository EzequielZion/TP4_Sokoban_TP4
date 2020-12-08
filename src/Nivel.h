//
// Created by santi on 12/7/2020.
//

#ifndef TP4_SOKOBAN_NIVEL_H
#define TP4_SOKOBAN_NIVEL_H
#include "Mapa.h"
#include "Coord.h"

class Nivel {
public:
    Nivel(Mapa m, Coord p, set<Coord> cs, Nat b);

    Nivel(aed2_Nivel n);

    Mapa MapaN();

    set<Coord> CajasN();

    Coord PersonaN();

    Nat BombasN();

private:
    set<Coord> _cajas;
    Mapa _mapa;
    Nat _bombas;
    Coord _persona;
};


#endif //TP4_SOKOBAN_NIVEL_H
