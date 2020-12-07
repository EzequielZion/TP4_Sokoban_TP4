#ifndef TP4_SOKOBAN_MAPA_H
#define TP4_SOKOBAN_MAPA_H

#include "Coord.h"
#include <vector>
#include <list>

class Mapa {
public:

    /**
     * Constructor
     * Complejidad O(1)
     */
    Mapa();

    /**
     * Constructor por copia
     * Complejidad O(D + P)
     */
    Mapa(const Mapa& aCopiar);

    /**
     * Operador asignación
     * Complejidad O(D + P)
     */
    Mapa& operator=(const Mapa& aCopiar);

    /**
     * Agrega una pared en la coordenada indicada
     * si no hay ni un depósito ni otra pared en dicha coordenada.
     * Devuelve true si la pared se agregó.
     * Complejidad: O(P + log D)
     */
    bool AgPared(Coord p);

    /**
     * Agrega un depósito en la coordenada indicada
     * si no hay ni otro depósito ni una pared en dicha coordenada.
     * Devuelve true si el depósito se agregó.
     * Complejidad: O(D + log P)
     */
    bool AgDeposito(Coord d);

    /**
     * Devuelve true si hay una pared en la coordenada indicada.
     * Complejidad O(log P)
     */
    bool HayPared(Coord c) const;

    /**
     * Devuelve true si hay un depósito en la coordenada indicada.
     * Complejidad O(log D)
     */
    bool HayDeposito(Coord c) const;

    /**
     * Devuelve el conjunto de depósitos del mapa.
     * Complejidad O(D * log D)
     */
    set<Coord> Depositos() const;

private:
    vector<pair<int,  vector<int>>> _paredes;
    vector<pair<int,  vector<int>>> _depositos;
    list<Coordenada> _bombasTiradas;

    /**
     * Inserta la coordenada c ordenadamente en el vector
     * si no estaba.
     * Devuelve true si la coordenada c no estaba en vec
     * y se pudo insertar.
     * Complejidad O(|vec|)
     */
    bool _InsertarOrdenado(vector<Coord>& vec, Coord c);

    /**
     * Devuelve true si la cordenada c está en vec.
     * Complejidad O(log |vec|)
     */
    bool _BuscarOrdenado(const vector<Coord>& vec, Coord c) const;
};


#endif //TP4_SOKOBAN_MAPA_H
