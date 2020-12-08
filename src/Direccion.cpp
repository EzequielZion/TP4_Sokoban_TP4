//
// Created by santi on 12/7/2020.
//

#include "Direccion.h"
#include "Coord.h"

Direccion::Direccion(PuntoCardinal pc) {
    switch(pc) {
        case Norte:
            _ord = 0;
            break;
        case Este:
            _ord = 1;
            break;
        case Sur:
            _ord = 2;
            break;
        case Oeste:
            _ord = 3;
            break;
    }
}

Coord Direccion::proximaCoord(const Coord &coord) {
    Coord c;
    switch (_ord) {
        case 0: // Norte
            c = Coord(coord.x(), coord.y() + 1);
        case 1: // Este
            c = Coord(coord.x() + 1, coord.y());
        case 2: // Sur
            c = Coord(coord.x(), coord.y() - 1);
        case 3: // Oeste
            c = Coord(coord.x() - 1, coord.y());
    }
    return c;
}

int Direccion::ord() const {
    return this->_ord;
}

Direccion& Direccion::operator=(const Direccion &dir) {
    this->_ord = dir.ord();
    return *this;
}



