#ifndef TP4_SOKOBAN_COORD_H
#define TP4_SOKOBAN_COORD_H
#include "Tipos.h"

class Coord {
public:
    Coord();

    Coord(int x, int y);

    Coord(pair<int, int> coord);

    Coord(const Coord &coord);

    int x() const;

    int y() const;

    Coord& operator=(const Coord &coord);

    bool operator<(const Coord &coord) const;

    bool operator>(const Coord &coord) const;

    bool operator!=(const Coord &coord) const;

    bool operator==(const Coord &coord) const;

private:
    int _x;
    int _y;
};


#endif //TP4_SOKOBAN_COORD_H
