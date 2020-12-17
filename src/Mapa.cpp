#include "Mapa.h"

Mapa::Mapa() : _paredes(), _depositos(), _bombasTiradas() { }

Mapa::Mapa(const Mapa &m) : _paredes(m._paredes), _depositos(m._depositos), _bombasTiradas(m._bombasTiradas) {}

void swap(vector<int> &vec, int i, int j) {
    int aux = i;
    vec[i] = vec[j];
    vec[j] = vec[aux];
}

int Mapa::busquedaBinariaXParedes(int l, int r,Coord c) const {
    if (this->_paredes.size() == 1) {
        if(this->_paredes[0].first == c.x()) {
            return 0;
        }
    } else if (this->_paredes.size() > 1) {
        if (r >= l) {
            int mid = (l + r) / 2;

            if (this->_paredes[mid].first == c.x()) {
                return mid;
            }

            if (this->_paredes[mid].first > c.x()) {
                return busquedaBinariaXParedes(l, mid - 1, c);
            }

            return busquedaBinariaXParedes(mid + 1, r, c);
        }
    }

    return -1;
}

int Mapa::busquedaBinariaYParedes(int l, int r, Coord c, int x) const {
    if (this->_paredes[x].second.size() == 1) {
        if(this->_paredes[x].second[0] == c.y()) {
            return 0;
        }
    } else if (this->_depositos[x].second.size() > 1) {
        if (r >= l) {
            int mid = l + (r - l) / 2;

            if (this->_paredes[x].second[mid] == c.y()) {
                return mid;
            }

            if (this->_paredes[x].second[mid] > c.y()) {
                return busquedaBinariaYParedes(l, mid - 1, c, x);
            }

            return busquedaBinariaYParedes(mid + 1, r, c, x);
        }
    }

    return -1;
}

int Mapa::busquedaBinariaXDepositos(int l, int r,Coord c) const {
    if (this->_depositos.size() == 1) {
        if(this->_depositos[0].first == c.x()) {
            return 0;
        }
    } else if (this->_depositos.size() > 1) {
        if (r >= l) {
            int mid = (l + r) / 2;

            if (this->_depositos[mid].first == c.x()) {
                return mid;
            }

            if (this->_depositos[mid].first > c.x()) {
                return busquedaBinariaXDepositos(l, mid - 1, c);
            }

            return busquedaBinariaXDepositos(mid + 1, r, c);
        }
    }

    return -1;
}

int Mapa::busquedaBinariaYDepositos(int l, int r, Coord c, int x) const {
    if (this->_depositos[x].second.size() == 1) {
        if(this->_depositos[x].second[0] == c.y()) {
            return 0;
        }
    } else if (this->_depositos[x].second.size() > 1) {
        if (r >= l) {
            int mid = l + (r - l) / 2;

            if (this->_depositos[x].second[mid] == c.y()) {
                return mid;
            }

            if (this->_depositos[x].second[mid] > c.y()) {
                return busquedaBinariaYDepositos(l, mid - 1, c, x);
            }

            return busquedaBinariaYDepositos(mid + 1, r, c, x);
        }
    }

    return -1;
}

bool Mapa::agPared(Coord p) {
    bool res = false;
    if (this->_paredes.empty()) {
        vector<int> vecY;
        vecY.push_back(p.y());
        this->_paredes.push_back(make_pair(p.x(), vecY));
        res = true;
    } else {

        bool esta = false;
        int indiceX = -1;
        for (int i = 0; i < this->_paredes.size(); i++) {
            if (this->_paredes[i].first == p.x()) {
                indiceX = i;
                for (int j = 0; j < this->_paredes[i].second.size(); ++j) {
                    if (this->_paredes[i].second[j] == p.y()) {
                        esta = true;
                    }
                }
            }
        }

        if (!esta) {
            if (indiceX != -1) {
                res = true;
                this->_paredes[indiceX].second.push_back(p.y());
                int j = this->_paredes[indiceX].second.size() - 1;
                while (j > 0 && this->_paredes[indiceX].second[j] < this->_paredes[indiceX].second[j - 1]) {
                    swap(this->_paredes[indiceX].second, j, j - 1);
                    j--;
                }
            } else {
                res = true;
                vector<int> vecY;
                vecY.push_back(p.y());
                pair<int, vector<int>> tupla = make_pair(p.x(), vecY);
                this->_paredes.push_back(tupla);
                int j = this->_paredes.size() - 1;
                while (j > 0 && this->_paredes[j].first < this->_paredes[j - 1].first) { //Agrego la tupla al final y la ordeno segun X
                    pair<int, vector<int>> aux = make_pair(this->_paredes[j].first, this->_paredes[j].second);
                    this->_paredes[j] = this->_paredes[j - 1];
                    this->_paredes[j - 1] = aux;
                    j--;
                }
            }
        }
    }
    return res;
}

bool Mapa::agDeposito(Coord d) {
    bool res = false;
    if (this->_depositos.empty()) {
        vector<int> vecY;
        vecY.push_back(d.y());
        this->_depositos.push_back(make_pair(d.x(), vecY));
        res = true;
    } else {

        bool esta = false;
        int indiceX = -1;
        for (int i = 0; i < this->_depositos.size(); i++) {
            if (this->_depositos[i].first == d.x()) {
                indiceX = i;
                for (int j = 0; j < this->_depositos[i].second.size(); ++j) {
                    if (this->_depositos[i].second[j] == d.y()) {
                        esta = true;
                    }
                }
            }
        }

        if (!esta) {
            if (indiceX != -1) {
                res = true;
                this->_depositos[indiceX].second.push_back(d.y());
                int j = this->_depositos[indiceX].second.size() - 1;
                while (j > 0 && this->_depositos[indiceX].second[j] < this->_depositos[indiceX].second[j - 1]) {
                    swap(this->_depositos[indiceX].second, j, j - 1);
                    j--;
                }
            } else {
                res = true;
                vector<int> vecY;
                vecY.push_back(d.y());
                pair<int, vector<int>> tupla = make_pair(d.x(), vecY);
                this->_depositos.push_back(tupla);
                int j = this->_depositos.size() - 1;
                while (j > 0 && this->_depositos[j].first < this->_depositos[j - 1].first) { //Agrego la tupla al final y la ordeno segun X
                    pair<int, vector<int>> aux = make_pair(this->_depositos[j].first, this->_depositos[j].second);
                    this->_depositos[j] = this->_depositos[j - 1];
                    this->_depositos[j - 1] = aux;
                    j--;
                }
            }
        }
    }
    return res;
}

bool Mapa::hayPared(const Coord &c) const {
    bool res = false;

    bool coincideBomba = false;
    for (const Coord& b : this->_bombasTiradas) {
        if (b.x() == c.x() || b.y() == c.y()) {
            coincideBomba = true;
        }
    }

    if (!coincideBomba) {
        int indiceX = busquedaBinariaXParedes(0, this->_paredes.size(), c);
        if (indiceX != -1) {
            int indiceY = busquedaBinariaYParedes(0, this->_paredes[indiceX].second.size(), c, indiceX);
            if (indiceY != -1) {
                res = true;
            }
        }
    }
    return res;
}

bool Mapa::hayDeposito(const Coord &c) const {
    bool res = false;
    int indiceX = busquedaBinariaXDepositos(0, this->_depositos.size(), c);
    if (indiceX != -1) {
        int indiceY = busquedaBinariaYDepositos(0, this->_depositos[indiceX].second.size(), c, indiceX);
        if (indiceY != -1) {
            res = true;
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

vector<Coord> Mapa::bombasTiradas() const {
    vector<Coord> res;
    for (Coord c : this->_bombasTiradas) {
        res.push_back(c);
    }
    return res;
}

void Mapa::tirarBomba(Coord c) {
    this->_bombasTiradas.push_back(c);
}

Mapa &Mapa::operator=(const Mapa &mapa) {
    vector<pair<int,  vector<int>>> vecVacio;
    this->_paredes = vecVacio;
    this->_depositos = vecVacio;
    for (Coord elem : mapa.Depositos()) {
        this->agDeposito(elem);
    }
    for (Coord elem : mapa.Paredes()) {
        this->agPared(elem);
    }
    this->_bombasTiradas = mapa.bombasTiradas();
    return *this;
}

void Mapa::eliminarBomba() {
    this->_bombasTiradas.pop_back();
}
