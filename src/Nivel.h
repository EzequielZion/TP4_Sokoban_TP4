#ifndef TP4_SOKOBAN_NIVEL_H
#define TP4_SOKOBAN_NIVEL_H
#include "Mapa.h"

class Nivel {
public:
    Nivel(aed2_Nivel n);

    Nivel(const Nivel& n);

    Nivel& operator=(const Nivel &n);

    Mapa MapaN() const;

    set<Coord> CajasN() const;

    Coord PersonaN() const;

    Nat BombasN() const;

private:
    set<Coord> _cajas;
    Mapa _mapa;
    Nat _bombas;
    Coord _persona;
};


#endif //TP4_SOKOBAN_NIVEL_H
