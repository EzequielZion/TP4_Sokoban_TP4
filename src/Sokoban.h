#ifndef TP4_SOKOBAN_SOKOBAN_H
#define TP4_SOKOBAN_SOKOBAN_H
#include "Mapa.h"
#include "Coord.h"
#include "Nivel.h"
#include "Direccion.h"
#include "stack"

class Sokoban {
public:
    Sokoban(const Nivel &n);
    void deshacer();
    void mover(const Direccion &dir);
    Mapa mapa() const;
    Nat bombas() const;
    Coord persona() const;
    bool hayCaja(const Coord &c) const;
    bool noHayParedNiCaja(const Coord &c) const;
    bool hayCajas(const set<Coord>& cajas) const;
    void tirarBomba(const Coord& c);
    bool puedeMover(const Direccion &dir) const;
    bool gano() const;

private:
    set<Coord> _cajas;
    Mapa _mapa;
    Nat _bombas;
    Coord _persona;
    Nat _depositosSinCaja;
    stack< tuple< tuple<bool, Coord, Coord*>, tuple<bool>, tuple<bool, Coord> > > _accion;
};

#endif //TP4_SOKOBAN_SOKOBAN_H
