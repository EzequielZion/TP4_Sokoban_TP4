#include "Sokoban.h"
#include "Direccion.h"
#include "Coord.h"

Sokoban::Sokoban(Nivel n) : _mapa(n.MapaN()), _bombas(n.BombasN()),
                            _cajas(n.CajasN()), _persona(n.PersonaN()),
                            _depositosSinCaja()//_historial()
                            {}

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

bool Sokoban::hayDeposito(Coord cAVer) {
    bool res = false;
    for(Coord c : this->_mapa.Depositos()){
        if(cAVer == c){
            res = true;
        }
    }
    return res;
}

void Sokoban::mover(Direccion dir) {
    //También se tiene que poder agregar al historial
    Coord proxCord = dir.proximaCoord(this->persona());
    Coord proxProxCord = dir.proximaCoord(proxCord);

    if(hayCaja(proxCord)){
        if(hayDeposito(proxProxCord)){
            this->_depositosSinCaja++;
            this->_cajas.erase(proxCord);
            this->_cajas.insert(proxProxCord);
            this->_persona = proxCord;
        }
        else if(hayDeposito(proxProxCord)){
            this->_depositosSinCaja--;
            this->_cajas.erase(proxCord);
            this->_cajas.insert(proxProxCord);
            this->_persona = proxCord;
        }
        else{
            this->_cajas.erase(proxCord);
            this->_cajas.insert(proxProxCord);
            this->_persona = proxCord;
        }
    }
    else{
        this->_persona = proxCord;
    }
}

void Sokoban::deshacer() {
}