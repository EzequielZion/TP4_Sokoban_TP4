#ifndef TP4_SOKOBAN_NIVEL_H
#define TP4_SOKOBAN_NIVEL_H
#include "Mapa.h"
#include "Coord.h"

class Nivel {
public:
    Nivel(Mapa m, Coord p, set<Coord> cs, Nat b);

    Nivel& operator=(const Nivel &n);

    Nivel(aed2_Nivel n);

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
