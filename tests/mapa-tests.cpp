#include "gtest-1.8.1/gtest.h"
#include "../src/Mapa.h"


TEST(Mapa, NoHayNadaEnMapaVacio) {
    Mapa m = Mapa();
    Coord c = Coord(69, 420);
    EXPECT_FALSE(m.hayDeposito(c));
    EXPECT_FALSE(m.hayPared(c));
    EXPECT_TRUE(m.Depositos().empty());
    EXPECT_TRUE(m.Paredes().empty());

}

TEST(Mapa, NoHayParedLuegoAgregoEntoncesSiHay) {
    Mapa m = Mapa();
    vector<Coord> paredes;
    paredes.push_back(Coord(0, 0));
    paredes.push_back(Coord(3, 7));
    paredes.push_back(Coord(-9, 2));

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
        EXPECT_FALSE(m.hayDeposito(deposito));
        EXPECT_TRUE(m.agDeposito(deposito));
        EXPECT_TRUE(m.hayDeposito(deposito));
        EXPECT_FALSE(m.agDeposito(deposito));
    }
}
