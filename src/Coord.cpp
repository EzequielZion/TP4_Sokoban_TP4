#include "Coord.h"
#include "math.h"


Coord::Coord() : _x(0), _y(0) {}

Coord::Coord(int X, int Y) : _x(X), _y(Y) {}

Coord::Coord(const pair<int, int> coord) : _x(coord.first), _y(coord.second) {}

Coord::Coord(const Coord &coord) : _x(coord._x), _y(coord._y) {}

int Coord::x() const {
    return this->_x;
}

int Coord::y() const {
    return this->_y;
}

bool Coord::operator!=(const Coord &coord) const {
    return this->_x != coord.x() || this->_y != coord.y();
}

bool Coord::operator==(const Coord &coord) const {
    return this->_x == coord.x() && this->_y == coord.y();
}

Coord& Coord::operator=(const Coord &coord) {
    this->_x = coord._x;
    this->_y = coord._y;
    return *this;
}

bool Coord::operator<(const Coord &coord) const {
    return this->_x < coord._x || (this->_x == coord._x && this->_y < coord._y);
}

bool Coord::operator>(const Coord &coord) const {
    return this->_x > coord._x || (this->_x == coord._x && this->_y > coord._y);
}
