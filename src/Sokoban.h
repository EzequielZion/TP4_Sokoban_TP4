#ifndef TP4_SOKOBAN_SOKOBAN_H
#define TP4_SOKOBAN_SOKOBAN_H
#include"Mapa.h"
#include "Coord.h"
#include "Nivel.h"
#include "Direccion.h"
#include "stack"

class Sokoban {
public:
    Sokoban(Nivel n);
    void deshacer();
    void mover(Direccion dir);
    Mapa mapa() const;
    Nat bombas() const;
    Coord persona() const;
    bool hayCaja(Coord c) const;
    bool noHayParedNiCaja(Coord c) const;
    bool hayCajas(set<Coord> cajas) const;
    void tirarBomba(Coord c);
    bool puedeMover(Direccion dir) const;
    bool gano() const;

private:
    set<Coord> _cajas;
    Mapa _mapa;
    Nat _bombas;
    Coord _persona;
    Nat _depositosSinCaja;
    stack<tuple<tuple<bool, Coord, Coord*>, tuple<bool>, tuple<bool, Coord>>> _accion;
};

//Hay cosas que puse copiando directamente
// del docs que se entremezclan con Nivel y Mapa que no sé si tienen que ir
// en el cpp y creo que es mejor que las discutamos entre todos je
//(tal vez sí tienen que ir y yo soy medio colgado nomás lmao)

#endif //TP4_SOKOBAN_SOKOBAN_H
