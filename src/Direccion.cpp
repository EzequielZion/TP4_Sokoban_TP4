//
// Created by santi on 12/7/2020.
//

#include "Direccion.h"
#include "Coord.h"

Direccion::Direccion(PuntoCardinal pc) {
    if (pc == Norte) {
        _ord = 0;
    } else if (pc == Este) {
        _ord = 1;
    } else if (pc == Sur) {
        _ord = 2;
    } else if (pc == Oeste) {
        _ord = 3;
    }

}

