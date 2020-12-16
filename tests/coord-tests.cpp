#include "gtest-1.8.1/gtest.h"
#include "../src/Mapa.h"

TEST(Coord, Constructor) {
    Coord coord1 = Coord(1, -2);
    EXPECT_EQ(coord1.x(), 1);
    EXPECT_EQ(coord1.y(), -2);

    Coord coord2 = Coord(0, 0);
    EXPECT_EQ(coord2.x(), 0);
    EXPECT_EQ(coord2.y(), 0);
}

TEST(Coord, ConstructorCoordenada) {
    Coordenada aed2_coordenada = Coordenada(2,-1);
    Coord c = Coord(aed2_coordenada);

    EXPECT_EQ(c.x(), 2);
    EXPECT_EQ(c.y(), -1);
}

TEST(Coord, ConstructorCopia) {
    Coord coord1 = Coord(5,-10);
    EXPECT_EQ(coord1.x(), 5);
    EXPECT_EQ(coord1.y(), -10);

    Coord coord2 = Coord(coord1);
    EXPECT_EQ(coord1.x(), 5);
    EXPECT_EQ(coord1.y(), -10);
    EXPECT_EQ(coord2.x(), 5);
    EXPECT_EQ(coord2.y(), -10);
}

TEST(Coord, Asignacion) {
    Coord coord1 = Coord(5,-10);
    EXPECT_EQ(coord1.x(), 5);
    EXPECT_EQ(coord1.y(), -10);

    Coord coord2 = Coord(-20,5);
    EXPECT_EQ(coord2.x(), -20);
    EXPECT_EQ(coord2.y(), 5);

    coord1 = coord2;
    EXPECT_EQ(coord1.x(), -20);
    EXPECT_EQ(coord1.y(), 5);
    EXPECT_EQ(coord2.x(), -20);
    EXPECT_EQ(coord2.y(), 5);
}

TEST(Coord, Mayor) {
    Coord coord1 = Coord(0,0);
    Coord coord2 = Coord(20,20);

    EXPECT_FALSE(coord1 > coord2);
    EXPECT_TRUE(coord2 > coord1);
}

TEST(Coord, Menor) {
    Coord coord1 = Coord(3,5);
    Coord coord2 = Coord(4,-2);

    EXPECT_TRUE(coord1 < coord2);
    EXPECT_FALSE(coord2 < coord1);
}

TEST(Coord, Igual) {
    Coord coord1 = Coord(7,1);
    Coord coord2 = Coord(-3,46);

    EXPECT_FALSE(coord1 == coord2);

    coord1 = coord2;

    EXPECT_TRUE(coord1 == coord2);
}

TEST(Coord, Distinto) {
    Coord coord1 = Coord(0,-15);
    Coord coord2 = Coord(-3,55);

    EXPECT_TRUE(coord1 != coord2);

    coord1 = coord2;

    EXPECT_FALSE(coord1 != coord2);
}