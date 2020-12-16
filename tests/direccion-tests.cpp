#include "gtest-1.8.1/gtest.h"
#include "../src/Direccion.h"


TEST(Direccion, PuntoCardinal) {
    Direccion direccion1 = Direccion(PuntoCardinal::Norte);
    EXPECT_EQ(direccion1.ord(), 0);
    Direccion direccion2 = Direccion(PuntoCardinal::Este);
    EXPECT_EQ(direccion2.ord(), 1);
    Direccion direccion3 = Direccion(PuntoCardinal::Sur);
    EXPECT_EQ(direccion3.ord(), 2);
    Direccion direccion4 = Direccion(PuntoCardinal::Oeste);
    EXPECT_EQ(direccion4.ord(), 3);
}

TEST(Direccion, proximaaCoord) {

    Coord c = {0,0};
    Coord c1 = {0,1};
    Direccion dir = 0;
    EXPECT_EQ(     dir.proximaCoord(c), c1);

    c = {0,0};
    c1 = {1,0};
    dir = 1;
    EXPECT_EQ(     dir.proximaCoord(c), c1);

    c = {0,0};
    c1 = {0,-1};
    dir = 2;
    EXPECT_EQ(     dir.proximaCoord(c), c1);

    c = {0,0};
    c1 = {-1,0};
    dir = 3;
    EXPECT_EQ(     dir.proximaCoord(c), c1);
}

TEST(Direccion, ord) {
    Direccion direccion1 = Direccion(0);
    EXPECT_EQ(direccion1.ord(), 0);
    Direccion direccion2 = Direccion(1);
    EXPECT_EQ(direccion2.ord(), 1);
    Direccion direccion3 = Direccion(2);
    EXPECT_EQ(direccion3.ord(), 2);
    Direccion direccion4 = Direccion(3);
    EXPECT_EQ(direccion4.ord(), 3);
}


TEST(Direccion, ConstructorPorCajas) {
    Direccion direccion1 = Direccion(PuntoCardinal::Norte);
    Direccion direccion2 = Direccion(direccion1);
    EXPECT_EQ(direccion1.ord(), 0);
    EXPECT_EQ(direccion2.ord(), 0);
    Direccion direccion3 = Direccion(PuntoCardinal::Este);
    Direccion direccion4 = Direccion(direccion3);
    EXPECT_EQ(direccion3.ord(), 1);
    EXPECT_EQ(direccion4.ord(), 1);
    Direccion direccion5 = Direccion(PuntoCardinal::Sur);
    Direccion direccion6 = Direccion(direccion5);
    EXPECT_EQ(direccion5.ord(), 2);
    EXPECT_EQ(direccion6.ord(), 2);
    Direccion direccion7 = Direccion(PuntoCardinal::Oeste);
    Direccion direccion8 = Direccion(direccion7);
    EXPECT_EQ(direccion7.ord(), 3);
    EXPECT_EQ(direccion8.ord(), 3);
}

TEST(Direccion, OperadorAsignacion) {
    Direccion direccion1 = Direccion(PuntoCardinal::Norte);
    EXPECT_EQ(direccion1.ord(), 0);
    Direccion direccion2 = Direccion(PuntoCardinal::Este);
    EXPECT_EQ(direccion2.ord(), 1);

    direccion1 = direccion2;
    EXPECT_EQ(direccion1.ord(), 1);
    EXPECT_EQ(direccion2.ord(), 1);
}