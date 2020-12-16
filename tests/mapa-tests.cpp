#include "gtest-1.8.1/gtest.h"
#include "../src/Mapa.h"


TEST(Mapa, NoHayNadaEnMapaVacio) {
    Mapa m = Mapa();
    pair<int, int> c = make_pair(53, -6);
    EXPECT_FALSE(m.hayDeposito(c));
    EXPECT_FALSE(m.hayPared(c));
    EXPECT_TRUE(m.Depositos().empty());
    EXPECT_TRUE(m.Paredes().empty());

}

TEST(Mapa, NoHayParedLuegoAgregoEntoncesSiHay) {
    Mapa m = Mapa();
    vector<Coord> paredes = {Coord(0, 0), Coord(3, 7), Coord(-9, 2)};

    for (Coord pared : paredes) {
        EXPECT_FALSE(m.hayPared(pared));
        EXPECT_TRUE(m.agPared(pared));
        EXPECT_TRUE(m.hayPared(pared));
        EXPECT_FALSE(m.agPared(pared));
    }
}

TEST(Mapa, NoHayDepositoLuegoAgregoEntoncesSiHay) {
    Mapa m = Mapa();
    vector<Coord> depositos = {Coord(0, 0), Coord(-10,10), Coord(-1,-1)};

    for (Coord deposito : depositos) {
        EXPECT_FALSE(m.hayDeposito(deposito));
        EXPECT_TRUE(m.agDeposito(deposito));
        EXPECT_TRUE(m.hayDeposito(deposito));
        EXPECT_FALSE(m.agDeposito(deposito));
    }
}

TEST(Mapa, NoHayDepositosNiParedesLuegoAgregoEntoncesSiHay) {
    Mapa m = Mapa();
    vector<Coord> depositos = {Coord(-1, 66), Coord(5, 10), Coord(1, 1)};
    vector<Coord> paredes = {Coord(0, 0), Coord(1, 1), Coord(-7, -8)};

    for (Coord pared : paredes) {
        EXPECT_FALSE(m.hayPared(pared));
        EXPECT_TRUE(m.agPared(pared));
        EXPECT_TRUE(m.hayPared(pared));
        EXPECT_FALSE(m.agPared(pared));
    }

    for (Coord deposito : depositos) {
        EXPECT_FALSE(m.agDeposito(deposito));
        EXPECT_FALSE(m.hayDeposito(deposito));
    }
}

TEST(Mapa, AgregoUnDepositoEntoncesNoPuedoAgregarUnaPared) {
    Mapa m = Mapa();
    Coord c = Coord(15, -15);
    vector<Coord> depositos =  vector<Coord>(0);
    depositos.push_back(c);
    EXPECT_TRUE(m.agDeposito(c));
    EXPECT_FALSE(m.agPared(c));

    for (Coord deposito : depositos) {
        EXPECT_TRUE(m.hayDeposito(deposito));
    }
}
TEST(Mapa, AgregoUnaParedEntoncesNoPuedoAgregarUnDeposito) {
    Mapa m = Mapa();
    Coord c = Coord(-15, 15);
    vector<Coord> paredes = {Coord(0, 0), Coord(1, 1), Coord(-7, -8)};
    paredes.push_back(c);
    EXPECT_TRUE(m.agPared(c));
    EXPECT_FALSE(m.agDeposito(c));

    for (Coord pared : paredes) {
        EXPECT_TRUE(m.hayPared(pared));
    }
}