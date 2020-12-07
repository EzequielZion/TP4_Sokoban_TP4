//
// Created by santi on 12/7/2020.
//

#include "Direccion.h"
#include "Coord.h"

Direccion::Direccion(PuntoCardinal pc) {
    switch(pc) {
        case Norte:
            _ord = 0;
        case Este:
            _ord = 1;
        case Sur:
            _ord = 2;
        case Oeste:
            _ord = 3;
    }
}

Coord Direccion::proximaDir(const Coord &coord) const {
    switch (_ord) {
        case 0: // Norte
            return Coord(coord.x(), coord.y() + 1); // O(1)
        case 1: // Este
            return Coord(coord.x() + 1, coord.y()); // O(1)
        case 2: // Sur
            return Coord(coord.x(), coord.y() - 1); // O(1)
        case 3: // Oeste
            return Coord(coord.x() - 1, coord.y()); // O(1)
    }

    // nunca pasa
    return Coord(0, 0);
}

int Direccion::ord() {
    return this->_ord;
}

Direccion& Direccion::operator=(const Direccion &dir) {
    this->_ord = dir._ord;
}



