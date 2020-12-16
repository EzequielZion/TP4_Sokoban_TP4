#include "gtest-1.8.1/gtest.h"
#include "../src/Nivel.h"


TEST(Nivel, PersonaNoCoincideConCajas) {
    aed2_Nivel n;
    for (Coord caja : n.cajas) {
        EXPECT_FALSE(caja == n.posicionInicial);
    }
}

TEST(Nivel, MismasCajas) {
    aed2_Nivel n;
    Nivel a = Nivel(n);

    set<Coord> cajas1 = a.CajasN();
    set<Coordenada> cajas2 = n.cajas;

    vector<Coord> vectorCoord = {};
    vector<Coordenada> vectorCoordenada = {};

    for (Coord caja1 : cajas1) {
        vectorCoord.push_back(caja1);
    }
    for (Coordenada caja2 : cajas2) {
        vectorCoordenada.push_back(caja2);
    }

    for (int i = 0; i < vectorCoord.size(); ++i) {
        EXPECT_TRUE(vectorCoord[i] == vectorCoordenada[i]);
    }
}

TEST(Nivel, MismasBombas) {
    aed2_Nivel n;
    Nivel a = Nivel(n);

    EXPECT_TRUE(n.cantidadBombas == a.BombasN());
}

TEST(Nivel, MismosDepositos) {
    aed2_Nivel n;
    Nivel a = Nivel(n);

    set<Coord> depositos1 = a.MapaN().Depositos();
    set<Coordenada> depositos2 = n.depositos;

    vector<Coord> vectorCoord = {};
    vector<Coordenada> vectorCoordenada = {};

    for (Coord deposito1 : depositos1) {
        vectorCoord.push_back(deposito1);
    }
    for (Coordenada deposito2 : depositos2) {
        vectorCoordenada.push_back(deposito2);
    }

    for (int i = 0; i < vectorCoord.size(); ++i) {
        EXPECT_TRUE(vectorCoord[i] == vectorCoordenada[i]);
    }
}

TEST(Nivel, MismaPosicionInicial) {
    aed2_Nivel n;
    n.posicionInicial = Coordenada(5,4);
    Nivel a = Nivel(n);

    Coord persona1 = n.posicionInicial;
    Coord persona2 = a.PersonaN();

    EXPECT_TRUE(persona1 == persona2);
    EXPECT_EQ(persona1, Coord(5,4));
    EXPECT_EQ(persona2, Coord(5,4));
}



