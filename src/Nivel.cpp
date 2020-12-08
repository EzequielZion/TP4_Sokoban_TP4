#include "Nivel.h"

Nivel::Nivel(Mapa m, Coord p, set<Coord> cs, Nat b) : _mapa(m), _cajas(cs), _persona(p), _bombas(b) {}

Nivel::Nivel(aed2_Nivel n) {
    Mapa m;
    for (Coordenada c : n.paredes) {
        m.agPared(c);
    }
    for(Coordenada c : n.depositos){
        m.agDeposito(c);
    }
    this->_mapa = m;
    this->_persona = n.posicionInicial;
    this->_cajas = n.cajas; //Para que funcione hay que cambiar Nivel.h o el struct aed2_Nivel en Tipos.h
    this->_bombas = n.cantidadBombas;
}

Mapa Nivel::MapaN(){
    return this->_mapa;
}

set<Coord> Nivel::CajasN(){
    return this->_cajas;
}

Coord Nivel::PersonaN(){
    return this->_persona;
}

Nat Nivel::BombasN(){
    return this->_bombas;
}

//Para recordar:
/*  struct aed2_Nivel {
    set<Coordenada> paredes;
    set<Coordenada> depositos;
    set<Coordenada> cajas;
    Coordenada posicionInicial;
    Nat cantidadBombas;
    };
 */