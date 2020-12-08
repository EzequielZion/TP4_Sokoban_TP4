#include "gtest-1.8.1/gtest.h"
#include "../src/Mapa.h"
#include "../src/Coord.h"


TEST(Mapa, vacio) {
    Mapa m1 = Mapa();
    Mapa m2 = Mapa();

    Coordenada c = Coordenada();

    m1.agPared();
    m2.agPared();

    EXPECT_EQ(m1,m2);
}
