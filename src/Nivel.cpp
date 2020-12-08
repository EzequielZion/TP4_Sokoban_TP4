//
// Created by santi on 12/7/2020.
//

#include "Nivel.h"

Nivel::Nivel(Mapa m, Coord p, set<Coord> cs, Nat b) : _mapa(m), _cajas(cs), _persona(p), _bombas(b) {}

Nivel::Nivel(aed2_Nivel n) {
    Mapa m;
    for (Coordenada c : n.paredes) {
        m.agPared(c);
    }

    for (Coordenada ) {

    }

}

