#include "gtest-1.8.1/gtest.h"
#include "../src/Mapa.h"


TEST(Mapa, vacio) {
    Mapa m = Mapa();
    for (int i = 0; i < 1000; ++i) {
        for (int j = 0; j < 1000; ++j) {
            Coord c = Coord(i, j);
            EXPECT_FALSE(m.HayDeposito(c));
            EXPECT_FALSE(m.HayPared(c));
        }
    }
    EXPECT_TRUE(m.Depositos().empty());
}

TEST(Mapa, paredes) {
    Mapa m = Mapa();
    vector<Coord> paredes = {Coord(0, 0), Coord(1,4), Coord(-7,2),
                             Coord(8,9), Coord(-1,-7), Coord(-5,0)};

    for (int i = 0; i < paredes.size(); ++i) {
        EXPECT_FALSE(m.HayPared(paredes[i]));
    }

    for (int i = 0; i < paredes.size(); ++i) {
        EXPECT_TRUE(m.AgPared(paredes[i]));
    }

    for (int i = 0; i < paredes.size(); ++i) {
        EXPECT_TRUE(m.HayPared(paredes[i]));
    }

    for (int i = 0; i < paredes.size(); ++i) {
        EXPECT_FALSE(m.AgPared(paredes[i]));
    }

}

TEST(Mapa, depositos) {
    Mapa m = Mapa();
    vector<Coord> dep = {Coord(0, 0), Coord(34,46), Coord(-64,2),
                         Coord(88,92), Coord(-3,-61), Coord(-58,54)};

    for (int i = 0; i < dep.size(); ++i) {
        EXPECT_FALSE(m.HayDeposito(dep[i]));
    }

    for (int i = 0; i < dep.size(); ++i) {
        EXPECT_TRUE(m.AgDeposito(dep[i]));
    }

    for (int i = 0; i < dep.size(); ++i) {
        EXPECT_TRUE(m.HayDeposito(dep[i]));
    }

    for (int i = 0; i < dep.size(); ++i) {
        EXPECT_FALSE(m.AgDeposito(dep[i]));
    }

    set<Coord> conDepositos = m.Depositos();
    for (int i = 0; i < dep.size(); ++i) {
        EXPECT_TRUE(conDepositos.count(dep[i]));
    }
}

TEST(Mapa, depositos_y_paredes) {
    Mapa m = Mapa();
    vector<Coord> dep = {Coord(0, 0), Coord(34,46), Coord(-64,2),
                         Coord(88,92), Coord(-3,-61), Coord(-58,54)};
    vector<Coord> paredes = {Coord(0, 0), Coord(1,4), Coord(-7,2),
                             Coord(8,9), Coord(-1,-7), Coord(-5,0)};

    for (int i = 0; i < dep.size(); ++i) {
        EXPECT_FALSE(m.HayDeposito(dep[i]));
    }
    for (int i = 0; i < paredes.size(); ++i) {
        EXPECT_FALSE(m.HayPared(paredes[i]));
    }

    for (int i = 0; i < paredes.size(); ++i) {
        EXPECT_TRUE(m.AgPared(paredes[i]));
    }
    for (int i = 0; i < dep.size(); ++i) {
        if(dep[i] == Coord(0,0)) {
            EXPECT_FALSE(m.AgDeposito(dep[i]));
        } else {
            EXPECT_TRUE(m.AgDeposito(dep[i]));
        }
    }
    for (int i = 0; i < paredes.size(); ++i) {
        EXPECT_TRUE(m.HayPared(paredes[i]));
    }

    for (int i = 0; i < dep.size(); ++i) {
        if(dep[i] == Coord(0,0)) {
            EXPECT_FALSE(m.HayDeposito(dep[i]));
        } else {
            EXPECT_TRUE(m.HayDeposito(dep[i]));
        }
    }

    for (int i = 0; i < paredes.size(); ++i) {
        EXPECT_FALSE(m.AgPared(paredes[i]));
    }

    for (int i = 0; i < dep.size(); ++i) {
        EXPECT_FALSE(m.AgDeposito(dep[i]));
    }

    Coord c = Coord(300, 500);
    dep.push_back(c);
    EXPECT_TRUE(m.AgDeposito(c));
    EXPECT_FALSE(m.AgPared(c));
    for (int i = 0; i < paredes.size(); ++i) {
        EXPECT_TRUE(m.HayPared(paredes[i]));
    }

    set<Coord> conDepositos = m.Depositos();
    for (int i = 0; i < dep.size(); ++i) {
        if(dep[i] == Coord(0,0)) {
            EXPECT_FALSE(conDepositos.count(dep[i]));
        } else {
            EXPECT_TRUE(conDepositos.count(dep[i]));
        }

    }
}
