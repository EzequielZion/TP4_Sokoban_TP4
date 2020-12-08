#ifndef TP4_SOKOBAN_MAPA_H
#define TP4_SOKOBAN_MAPA_H

#include "Coord.h"
#include <vector>
#include <list>

class Mapa {
public:
    Mapa();

    Mapa& operator=(const Mapa& aCopiar);

    bool AgPared(Coord p);

    bool AgDeposito(Coord d);

    bool HayPared(Coord c) const;

    bool HayDeposito(Coord c) const;

    set<Coord> Depositos() const;

    set<Coord> Paredes() const;

    void tirarBomba(Coord c);

    set<Coord> bombasTiradas() const;

private:
    vector<pair<int,  vector<int>>> _paredes;
    vector<pair<int,  vector<int>>> _depositos;
    list<Coordenada> _bombasTiradas;
};

using namespace std;

#endif //TP4_SOKOBAN_MAPA_H
