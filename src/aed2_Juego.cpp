#include "aed2_Juego.h"

aed2_Juego::aed2_Juego(vector<aed2_Nivel> ns) : _nivelesPendientes(), _sokoActual(Nivel(ns[0])) {
    for (int i = 1; i < ns.size(); ++i) {
        _nivelesPendientes.push_back(ns[i]);
    }
}

bool aed2_Juego::hayPared(Coordenada c) const {
    return this->_sokoActual.mapa().hayPared(c);
}

bool aed2_Juego::hayDeposito(Coordenada c) const {
    return this->_sokoActual.mapa().hayDeposito(c);
}

bool aed2_Juego::hayCaja(Coordenada c) const {
    return this->_sokoActual.hayCaja(c);
}

Coordenada aed2_Juego::posicionActual() const {
    return Coordenada (this->_sokoActual.persona().x(), this->_sokoActual.persona().y());
}

Nat aed2_Juego::cantidadBombas() const {
    return this->_sokoActual.bombas();
}

bool aed2_Juego::sePuedeMover(PuntoCardinal pc) const {
    return this->_sokoActual.puedeMover(Direccion(pc));
}

// IMPORTANTE: Debe devolver:
// - true si al mover se completa el nivel actual
// - false en caso contrario.
bool aed2_Juego::mover(PuntoCardinal pc) {
    bool res = false;
    this->_sokoActual.mover(Direccion(pc));
    if (this->_sokoActual.gano()) {
        if (this->_nivelesPendientes.empty()) {
            this->_sokoActual = Sokoban(Nivel(this->_nivelesPendientes[0]));
            this->_nivelesPendientes.erase(this->_nivelesPendientes.begin());
        }
        res = true;
    }
    return res;
}

void aed2_Juego::tirarBomba() {
    this->_sokoActual.tirarBomba(this->_sokoActual.persona());
}

void aed2_Juego::deshacer() {
    this->_sokoActual.deshacer();
}

