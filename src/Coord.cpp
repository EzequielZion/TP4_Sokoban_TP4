#include "Coord.h"
#include "math.h"


Coord::Coord() : _coord(0,0) {}

Coord::Coord(int X, int Y) : _coord(make_pair(X,Y)) {}

Coord::Coord(const Coordenada coord) : _coord(coord.first, coord.second) {}

Coord::Coord(const Coord &coord) : _coord(coord.x(), coord.y()) {}

int Coord::x() const {
    return this->_coord.first;
}

int Coord::y() const {
    return this->_coord.second;
}

Coord &Coord::operator=(Coord aCopiar) {
    _coord = aCopiar._coord; // O(1)
    return *this;
}

bool Coord::operator<(const Coord &c) const {
    return this->x() < c.x() || (this->x() == c.x() && this->y() < c.y()); // O(1)
}

bool Coord::operator==(const Coord &c) const {
    return this->x() == c.x() && this->y() == c.y(); // O(1)
}

bool Coord::operator>(const Coord &c) const {
    return !(*this < c || *this == c); // O(1)
}

bool Coord::operator!=(const Coord &c) const {
    return !(*this == c); // O(1)
}


/*bool Coord::operator!=(const Coord &coord) const {
    return this->_coord.first != coord.x() || this->_coord.second != coord.y();
}

bool Coord::operator==(const Coord &coord) const {
    return this->_coord.first == coord.x() && this->_coord.second == coord.y();
}

Coord& Coord::operator=(const Coord &coord) {
    this->_coord.first = coord.x();
    this->_coord.second = coord.y();
    return *this;
}

bool Coord::operator<(const Coord &coord) const {
    return this->x() < coord.x() || (this->x() == coord.x() && this->y() < coord.y());
}

bool Coord::operator>(const Coord &coord) const {
    return !(*this < coord || *this == coord); // O(1)
}*/
