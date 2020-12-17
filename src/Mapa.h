#ifndef TP4_SOKOBAN_MAPA_H
#define TP4_SOKOBAN_MAPA_H

#include "Coord.h"
#include <vector>
#include <list>

class Mapa {
public:
    Mapa();

    Mapa(const Mapa &m);

    Mapa& operator=(const Mapa& aCopiar);

    bool agPared(Coord p);

    bool agDeposito(Coord d);

    bool hayPared(const Coord &c) const;

    bool hayDeposito(const Coord &c) const;

    set<Coord> Depositos() const;

    set<Coord> Paredes() const;

    void tirarBomba(Coord c);

    vector<Coord> bombasTiradas() const;

    void eliminarBomba();

private:
    vector<pair<int,  vector<int>>> _paredes;
    vector<pair<int,  vector<int>>> _depositos;
    vector<Coord> _bombasTiradas;
    int busquedaBinariaXParedes(int l, int r,Coord c) const;
    int busquedaBinariaYParedes(int l, int r,Coord c, int x) const;
    int busquedaBinariaXDepositos(int l, int r,Coord c) const;
    int busquedaBinariaYDepositos(int l, int r,Coord c, int x) const;
};

using namespace std;

#endif //TP4_SOKOBAN_MAPA_H
