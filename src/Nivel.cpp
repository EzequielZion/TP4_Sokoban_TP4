#include "Nivel.h"

Nivel::Nivel(Mapa m, Coord p, set<Coord> cs, Nat b) : _mapa(m), _cajas(cs), _persona(p), _bombas(b) {}

Nivel::Nivel(const aed2_Nivel &n) {
    Mapa m = Mapa();
    for (Coordenada c : n.paredes) {
        m.agPared(Coord(c));
    }
    for(Coordenada c : n.depositos){
        m.agDeposito(Coord(c));
    }
    this->_mapa = m;
    for (Coordenada caja : n.cajas) {
        this->_cajas.insert(Coord(caja));
    }
    this->_persona = Coord(n.posicionInicial);

    this->_bombas = n.cantidadBombas;
}

Mapa Nivel::MapaN() const{
    return this->_mapa;
}

set<Coord> Nivel::CajasN() const{
    return this->_cajas;
}

Coord Nivel::PersonaN() const{
    return this->_persona;
}

Nat Nivel::BombasN() const{
    return this->_bombas;
}

Nivel& Nivel::operator=(const Nivel &n) {
    this->_bombas = n.BombasN();
    this->_cajas = n.CajasN();
    this->_mapa = n.MapaN();
    this->_persona = n.PersonaN();
    return *this;
}

