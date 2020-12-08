#include "Sokoban.h"
#include "Direccion.h"
#include "Coord.h"

Sokoban::Sokoban(Nivel n) : _mapa(n.MapaN()), _bombas(n.BombasN()),
                            _cajas(n.CajasN()), _persona(n.PersonaN())
                            //_historial()
                            {
                                int contCajasEnDepositos = 0;
                                for (Coord d : n.MapaN().Depositos()) {
                                    bool cajaEnDeposito = false;
                                    for (Coord c : n.CajasN()) {
                                        if (c == d) {
                                            cajaEnDeposito = true;
                                        }
                                    }
                                    if (!cajaEnDeposito) {
                                        contCajasEnDepositos++;
                                    }
                                }
                                _depositosSinCaja = n.CajasN().size() - contCajasEnDepositos;
                            }

Mapa Sokoban::mapa() {
    return this->_mapa;
}

Nat Sokoban::bombas() {
    return this->_bombas;
}

Coord Sokoban::persona() {
    return this->_persona;
}

bool Sokoban::hayCaja(Coord cAVer) {
    bool res = false;
    for(Coord c : this->_cajas){
        if(cAVer == c){
            res = true;
        }
    }
    return res;
}

bool Sokoban::noHayParedNiCaja(Coord cAVer) {
    bool res = true;
    for(Coord p : this->_mapa.Paredes()){
        if(cAVer == p){
            res = false;
        }
    }
    for (Coord c : this->_cajas) {
        if(cAVer == c) {
            res = false;
        }
    }
    return res;
}

bool Sokoban::puedeMover(Direccion dir) {
    bool res = false;
    Coord proxCord = dir.proximaCoord(this->persona());
    Coord proxProxCord = dir.proximaCoord(proxCord);
    if(!this->_mapa.hayPared(proxCord)) {
        if (hayCaja(proxCord)) {
            if(!noHayParedNiCaja(proxProxCord)) {
                res = true;
            }
        } else { res = true; }
    }
    return res;
}

void Sokoban::mover(Direccion dir) {
    //También se tiene que poder agregar al historial
    Coord proxCord = dir.proximaCoord(this->persona());
    Coord proxProxCord = dir.proximaCoord(proxCord);

    if (puedeMover(dir)) {
        if (hayCaja(proxCord)) {
            if (mapa().hayDeposito(proxCord)) {
                this->_depositosSinCaja++;
                this->_cajas.erase(proxCord);
                this->_cajas.insert(proxProxCord);
                this->_persona = proxCord;
            } else if (mapa().hayDeposito(proxProxCord)) {
                this->_depositosSinCaja--;
                this->_cajas.erase(proxCord);
                this->_cajas.insert(proxProxCord);
                this->_persona = proxCord;
            } else {
                this->_cajas.erase(proxCord);
                this->_cajas.insert(proxProxCord);
                this->_persona = proxCord;
            }
            Coord* itCaja;
            for(Coord c : this->_cajas) {
                if (c == proxProxCord) {
                    itCaja = &c;
                }
            }
            this->_accion.push(make_tuple(make_tuple(true, Coord(proxCord), itCaja), make_tuple(false), make_tuple(true, proxCord)));
        } else {
            this->_persona = proxCord;
            this->_accion.push(make_tuple(make_tuple(false, Coord(0,0), nullptr), make_tuple(false), make_tuple(true, proxCord)));
        }
    }
}

void Sokoban::deshacer() {
    if (this->_accion.size() > 0) {
        if (get<0>(get<0>(this->_accion.top()))) {
            this->_persona = get<1>(get<2>(this->_accion.top()));
            get<2>(get<0>(this->_accion.top())) = &get<1>(get<0>(this->_accion.top()));
        } else if (get<0>(get<1>(this->_accion.top()))) {
            this->_mapa.bombasTiradas().pop_back();
        } else if (get<0>(get<2>(this->_accion.top()))) {
            this->_persona = get<1>(get<2>(this->_accion.top()));
        }
        this->_accion.pop();
    }
}

void Sokoban::tirarBomba(Coord c) {
    if(this->_bombas > 0) {
        this->_mapa.tirarBomba(c);
        this->_bombas--;
        this->_accion.push(make_tuple(make_tuple(false, Coord(0, 0), nullptr), make_tuple(true), make_tuple(false, this->_persona)));
    }
}

bool Sokoban::gano() {
    bool res = false;
    if (this->_depositosSinCaja == 0) {
        res = true;
    }
    return res;
}

bool Sokoban::hayCajas(set<Coord> cajas) {

}
