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

Coord Direccion::proximaCoord(Coord coord) {
    switch (_ord) {
        case 0: // Norte
            coord = Coord(coord.x(), coord.y() + 1);
            break;
        case 1: // Este
            coord = Coord(coord.x() + 1, coord.y());
            break;
        case 2: // Sur
            coord = Coord(coord.x(), coord.y() - 1);
            break;
        case 3: // Oeste
            coord = Coord(coord.x() - 1, coord.y());
            break;
    }
    return coord;
}

int Direccion::ord() const {
    return this->_ord;
}

Direccion& Direccion::operator=(const Direccion &dir) {
    this->_ord = dir.ord();
    return *this;
}



