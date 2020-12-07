//
// Created by santi on 12/7/2020.
//

#ifndef TP4_SOKOBAN_COORD_H
#define TP4_SOKOBAN_COORD_H
#include "Tipos.h"

class Coord {
public:
    Coord();

    Coord(int X, int Y);

    Coord(Coordenada &coord);

    int x() const;

    int y() const;

    bool operator=(const Coord &coord);

    bool operator!=(const Coord &coord);

    bool operator==(const Coord &coord);

private:
    Coordenada _coord;
};


#endif //TP4_SOKOBAN_COORD_H