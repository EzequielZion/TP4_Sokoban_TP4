#include "Mapa.h"


Mapa::Mapa() : _paredes(), _depositos() {
    // los constructores por defecto de vector tiene complejidad constante.
    // O(1)
}

Mapa::Mapa(const Mapa &aCopiar) {
    *this = aCopiar; // O(P + D)
}

Mapa &Mapa::operator=(const Mapa &aCopiar) {
    // copiar un vector tiene complejidad lineal
    _paredes = aCopiar._paredes;    // O(P)
    _depositos = aCopiar._depositos; // O(D)

    return *this;
}

bool Mapa::AgPared(Coord p) {
    bool res = !_BuscarOrdenado(_depositos, p); // O(log D)
    if(res) { // si en p no hay un depósito, es posible agregar la pared
        res = _InsertarOrdenado(_paredes, p); // O(P)
    }
    return res;
}

bool Mapa::AgDeposito(Coord d) {
    bool res = !_BuscarOrdenado(_paredes, d);   // O(log P)
    if(res) { // si en p no hay una pared, es posible agregar el depósito
        res = _InsertarOrdenado(_depositos, d); // o(D)
    }
    return res;
}

bool Mapa::HayPared(Coord c) const {
    return _BuscarOrdenado(_paredes, c); // O(log P)
}

bool Mapa::HayDeposito(Coord c) const {
    return _BuscarOrdenado(_depositos, c); // O(log D)
}

set<Coord> Mapa::Depositos() const {
    set<Coord> ret = set<Coord>(); // O(1)
    for (int i = 0; i < _depositos.size(); ++i) {
        ret.insert(_depositos[i]); // O(log i)
    } // O(n * log n)
    return ret;
}

bool Mapa::_InsertarOrdenado(vector<Coord> &vec, Coord c) {
    bool res = !_BuscarOrdenado(vec, c); // O(log |vec|)
    if(res) {
        vec.push_back(c); // O(|vec|) con reallocation
        int i = vec.size() - 1;
        while (i > 0 && vec[i] < vec[i - 1]) { // O(|vec|)
            // swap
            Coord tmp = vec[i];
            vec[i] = vec[i - 1];
            vec[i - 1] = tmp;

            i--;
        }
    }

    return res;
} // O(|vec| + log |vec|) = O(|vec|)

bool Mapa::_BuscarOrdenado(const vector<Coord> &vec, Coord c) const {
    if(vec.size() == 0 || c < vec[0] || c > vec[vec.size() - 1]) { // O(1)
        return false;
    } else if(c == vec[vec.size() - 1]) { // O(1)
        return true;
    }
    // else
    // busqueda binaria, O(log |vec|)
    int izq = 0;
    int der = vec.size() - 1;
    while (izq + 1 < der && c != vec[izq]) {
        int mid = (izq + der) /2;
        if(c < vec[mid]) {
            der = mid;
        } else {
            izq = mid;
        }
    }

    return c == vec[izq];
}
