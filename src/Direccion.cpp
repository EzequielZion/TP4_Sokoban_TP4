#include "Direccion.h"
#include "Coord.h"

Direccion::Direccion(Nat ord) : _ord(ord) {}

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

Direccion::Direccion(const Direccion &dir) {
    *this = dir;
}

Coord Direccion::proximaCoord(const Coord &coord) const {
    Coord res;
    switch (_ord) {
        case 0:
            res = Coord(coord.x(), coord.y() + 1);
            break;
        case 1:
            res = Coord(coord.x() + 1, coord.y());
            break;
        case 2:
            res = Coord(coord.x(), coord.y() - 1);
            break;
        case 3:
            res = Coord(coord.x() - 1, coord.y());
            break;
    }
    return res;
}

int Direccion::ord() const {
    return this->_ord;
}

Direccion& Direccion::operator=(const Direccion &dir) {
    this->_ord = dir.ord();
    return *this;
}



