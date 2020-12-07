//
// Created by santi on 12/7/2020.
//

#include "Coord.h"

Coord::Coord(int X, int Y) : _coord(X, Y) {}

Coord::Coord(Coordenada &coord) : _coord(coord) {}

int Coord::x() const {
    return this->_coord.first;
}

int Coord::y() const {
    return this->_coord.second;
}

bool Coord::operator!=(const Coord &coord) {
    return this->_coord.first != coord.x() || this->_coord.second != coord.y();
}

bool Coord::operator==(const Coord &coord) {
    return this->_coord.first == coord.x() && this->_coord.second == coord.y();
}

Coord& Coord::operator=(const Coord &coord) {
    this->_coord.first = coord.x();
    this->_coord.second = coord.y();
    return *this;
}
