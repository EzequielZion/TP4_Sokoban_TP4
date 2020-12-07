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

int Direccion::ord() {
    return this->_ord;
}

Direccion& Direccion::operator=(const Direccion &dir) {
    this->_ord = dir._ord;
}



