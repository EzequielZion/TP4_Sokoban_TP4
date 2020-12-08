#include "Mapa.h"

void swap(vector<int> &vec, int i, int j) {
    int aux = i;
    vec[i] = vec[j];
    vec[j] = vec[aux];
}

int busquedaBinariaX(vector<pair<int, vector<int>>> vec, int l, int r, Coord &c) {
    if (r >= l) {
        int mid = l + (r - l) / 2;

        if (vec[mid].first == c.x()) {
            return mid;
        }

        if (vec[mid].first > c.x()) {
            return busquedaBinariaX(vec, l, mid - 1, c);
        }

        return busquedaBinariaX(vec, mid + 1, r, c);
    }

    return -1;
}

bool busquedaBinariaY(vector<int> vec, int l, int r, Coord &c) {
    if (r >= l) {
        int mid = l + (r - l) / 2;

        if (vec[mid] == c.x()) {
            return mid;
        }

        if (vec[mid] > c.x()) {
            return busquedaBinariaY(vec, l, mid - 1, c);
        }

        return busquedaBinariaY(vec, mid + 1, r, c);
    }

    return -1;
}


Mapa::Mapa() : _paredes(), _depositos(), _bombasTiradas() { }

bool Mapa::agPared(Coord p) {
    bool res = false;
    for (int i = 0; i < this->_paredes.size(); i++) {

        if (p.x() == this->_paredes[i].first) { //Ya hay paredes con esa X

            bool esta = false;
            for (int j = 0; j < this->_paredes[i].second.size(); ++j) { //Me fijo si está esa pared ya en el mapa
                if (this->_paredes[i].second[j] == p.y()) {
                    esta = true;
                }
            }
            if (!esta) { //Si no está, la agrego al final y la ordeno
                res = true;
                this->_paredes[i].second.push_back(p.y());
                int j = this->_paredes[i].second.size() - 1;
                while (j > 0 && this->_paredes[i].second[j] < this->_paredes[i].second[j - 1]) {
                    swap(this->_paredes[i].second, j, j - 1);
                    j--;
                }
            }
        }

        else if (p.x() < this->_paredes[i].first) { //No hay ninguna pared en esa X
            res = true;
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
    return res;
}

bool Mapa::agDeposito(Coord d) {
    bool res = false;
    for (int i = 0; i < this->_depositos.size(); i++) {

        if (d.x() == this->_depositos[i].first) { //Ya hay cajas con esa X

            bool esta = false;
            for (int j = 0; j < this->_depositos[i].second.size(); ++j) { //Me fijo si está esa caja ya en el mapa
                if (this->_depositos[i].second[j] == d.y()) {
                    esta = true;
                }
            }
            if (!esta) { //Si no está, la agrego al final y la ordeno
                res = true;
                this->_depositos[i].second.push_back(d.y());
                int j = this->_depositos[i].second.size() - 1;
                while (j > 0 && this->_depositos[i].second[j] < this->_depositos[i].second[j - 1]) {
                    swap(this->_depositos[i].second, j, j - 1);
                    j--;
                }
            }
        }

        else if (d.x() < this->_depositos[i].first) { //No hay ninguna caja en esa X
            res = true;
            vector<int> vecY;
            vecY.push_back(d.y());
            pair<int, vector<int>> tupla = make_pair(d.x(), vecY);
            this->_depositos.push_back(tupla);
            int j = this->_depositos.size() - 1;
            while (j > 0 && this->_depositos[j].first < this->_depositos[j-1].first) { //Agrego la tupla al final y la ordeno segun X
                pair<int, vector<int>> aux = make_pair(this->_depositos[j].first, this->_depositos[j].second);
                this->_depositos[j] = this->_depositos[j-1];
                this->_depositos[j-1] = aux;
                j--;
            }
        }
    }
    return res;
}

bool Mapa::hayPared(Coord c) const {
    int l = 0;
    int r = this->_paredes.size()-1;
    bool res = false;

    bool coincideBomba = false;
    for (Coord b : this->_bombasTiradas) {
        if (b.x() == c.x() || b.y() == c.y()) {
            coincideBomba = true;
        }
    }

    if (!coincideBomba) {
        int indiceX = busquedaBinariaX(this->_paredes, l, r, c);
        if (indiceX != -1) {
            int indiceY = busquedaBinariaY(this->_paredes[indiceX].second, l, r, c);
            if (indiceY != -1) {
                res = true;
            }
        }
    }
    return res;
}

bool Mapa::hayDeposito(Coord c) const {
    int l = 0;
    int r = this->_depositos.size()-1;
    bool res = false;
    int indiceX = busquedaBinariaX(this->_depositos, l, r, c);

    if (indiceX != -1) {
        int indiceY = busquedaBinariaY(this->_depositos[indiceX].second, l, r, c);
        if (indiceY != -1) {
            for (Coord b : this->_bombasTiradas) {

            }
        }
    }
    return res;
}

set<Coord> Mapa::Depositos() const {
    set<Coord> depos;
    for (int i = 0; i < this->_depositos.size(); i++) {
        for (int j = 0; j < this->_depositos[i].second.size(); j++) {
            pair<int, int> depositoActual = make_pair(this->_depositos[i].first, this->_depositos[i].second[j]);
            depos.insert(depositoActual);
        }
    }
    return depos;
}

set<Coord> Mapa::Paredes() const {
    set<Coord> pareds;
    for (int i = 0; i < this->_paredes.size(); i++) {
        for (int j = 0; j < this->_paredes[i].second.size(); j++) {
            pair<int, int> paredActual = make_pair(this->_paredes[i].first, this->_paredes[i].second[j]);
            pareds.insert(paredActual);
        }
    }
    return pareds;
}

list<Coord> Mapa::bombasTiradas() const {
    list<Coord> res;
    for (Coord c : this->_bombasTiradas) {
        res.push_back(c);
    }
    return res;
}

void Mapa::tirarBomba(Coord c) {
    this->_bombasTiradas.push_back(c);
}

Mapa &Mapa::operator=(const Mapa &mapa) {
    for (Coord elem : mapa.Depositos()) {
        this->agDeposito(elem);
    }
    for (Coord elem : mapa.Paredes()) {
        this->agPared(elem);
    }
    this->_bombasTiradas = mapa.bombasTiradas();
    return *this;
}