#include "Mapa.h"

void swap(vector<int> &vec, int i, int j) {
    int aux = i;
    vec[i] = vec[j];
    vec[j] = vec[aux];
}

Mapa::Mapa() : _paredes(), _depositos() { }

Mapa &Mapa::operator=(const Mapa &mapa) {
    for (auto elem : mapa.Depositos()) {
    }
}

bool Mapa::AgPared(Coord p) {
    for (int i = 0; i < this->_paredes.size(); i++) {

        if (p.x() == this->_paredes[i].first) { //Ya hay cajas con esa X

            bool esta = false;
            for (int j = 0; j < this->_paredes[i].second.size(); ++j) { //Me fijo si está esa caja ya en el mapa
                if (this->_paredes[i].second[j] == p.y()) {
                    esta = true;
                }
            }
            if (!esta) { //Si no está, la agrego al final y la ordeno
                this->_paredes[i].second.push_back(p.y());
                int j = this->_paredes[i].second.size() - 1;
                while (j > 0 && this->_paredes[i].second[j] < this->_paredes[i].second[j-1]) {
                    swap(this->_paredes[i].second, j, j-1);
                    j--;
                }
            }
        }
        else if (p.x() < this->_paredes[i].first) { //No hay ninguna caja en esa X
            vector<int> vecY;
            vecY.push_back(p.y());
            pair<int, vector<int>> tupla = make_pair(p.x(), vecY);
            this->_paredes.push_back(tupla);
            int j = this->_paredes.size() - 1;
            while (j > 0 && this->_paredes[j].first < this->_paredes[j-1].first) { //Agrego la tupla al final y la ordeno segun X
                pair<int, vector<int>> aux = make_pair(this->_paredes[j].first, this->_paredes[j].second);
                this->_paredes[j] = this->_paredes[j-1];
                this->_paredes[j-1] = aux;
                j--;
            }
        }
    }
}

bool Mapa::AgDeposito(Coord d) {

}

bool Mapa::HayPared(Coord c) const {

}

bool Mapa::HayDeposito(Coord c) const {

}

set<Coord> Mapa::Depositos() const {

}

set<Coord> Mapa::Paredes() const {

}

set<Coord> Mapa::bombasTiradas() const {

}