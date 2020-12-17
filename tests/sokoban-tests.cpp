#include "gtest-1.8.1/gtest.h"
#include "../src/Sokoban.h"

Nivel nivelParaTest1(){
    aed2_Nivel n;

    vector<Coord> depositos;
    depositos.push_back(Coord(0, 9));
    depositos.push_back(Coord(1,4));

    for (Coord deposito : depositos) {
        n.depositos.insert(make_pair(deposito.x(), deposito.y()));
    }

    vector<Coord> paredes;
    paredes.push_back(Coord(2, 2));
    paredes.push_back(Coord(5,4));
    paredes.push_back(Coord(-7,3));
    paredes.push_back(Coord(4,9));

    for (Coord pared : paredes) {
        n.paredes.insert(make_pair(pared.x(), pared.y()));
    }
    vector<Coord> cajas;
    cajas.push_back(Coord(1,1));
    cajas.push_back(Coord(3, 3));

    for (Coord caja : cajas) {
        n.cajas.insert(make_pair(caja.x(), caja.y()));
    }

    n.cantidadBombas = 1;
    n.posicionInicial = make_pair(0,0);

    Nivel nivel = Nivel(n);

    return nivel;
}

Nivel nivelParaTest2(){
    aed2_Nivel n;

    vector<Coord> depositos;
    depositos.push_back(Coord(0, 2));

    for (Coord deposito : depositos) {
        n.depositos.insert(make_pair(deposito.x(), deposito.y()));
    }

    vector<Coord> paredes;
    paredes.push_back(Coord(4,9));
    paredes.push_back(Coord(2, 2));
    paredes.push_back(Coord(5,4));
    paredes.push_back(Coord(-7,3));

    for (Coord pared : paredes) {
        n.paredes.insert(make_pair(pared.x(), pared.y()));
    }

    vector<Coord> cajas;
    cajas.push_back(Coord(0,1));

    for (Coord caja : cajas) {
        n.cajas.insert(make_pair(caja.x(), caja.y()));
    }

    n.cantidadBombas = 1;
    n.posicionInicial = make_pair(0,0);

    Nivel nivel = Nivel(n);

    return nivel;
}

TEST(Sokoban, vacio) {
    EXPECT_TRUE(true);
}

TEST(Sokoban,nuevo){
    Nivel n = nivelParaTest1();
    vector<Coord> paredes = {Coord(2, 2), Coord(5,4), Coord(-7,3),
                             Coord(4,9)};
    EXPECT_EQ(Sokoban(n).mapa().Depositos(),n.MapaN().Depositos());
    for (int i = 0; i < paredes.size(); ++i) {
        EXPECT_FALSE(Sokoban(n).noHayParedNiCaja(paredes[i]));
    }

    EXPECT_EQ(Sokoban(n).bombas(),n.BombasN());
    EXPECT_EQ(Sokoban(n).persona(),n.PersonaN());

}

TEST(Sokoban, porCopiayAsignacion) {
    Nivel n = nivelParaTest1();
    vector<Coord> paredes = {Coord(2, 2), Coord(5,4), Coord(-7,3),
                             Coord(4,9)};

    Sokoban s = Sokoban(n);
    EXPECT_TRUE(s.persona() == n.PersonaN());
    EXPECT_TRUE(s.bombas() == n.BombasN());
    EXPECT_TRUE(s.mapa().Depositos() == n.MapaN().Depositos());
    for (int i = 0; i < paredes.size(); ++i) {
        EXPECT_TRUE(s.mapa().hayPared(paredes[i]));
    }
    for (Coord c:n.CajasN()){
        EXPECT_TRUE(s.hayCaja(c));
    }

    Sokoban t(s);
    EXPECT_TRUE(s.persona() == t.persona());
    EXPECT_TRUE(s.bombas() == t.bombas());
    EXPECT_TRUE(s.mapa().Depositos() == t.mapa().Depositos());
    for (int i = 0; i < paredes.size(); ++i) {
        EXPECT_EQ(s.mapa().hayPared(paredes[i]),t.mapa().hayPared(paredes[i]));
    }
    for (Coord c:n.CajasN()){
        EXPECT_EQ(s.hayCaja(c),t.hayCaja(c));
    }
}

TEST(Sokoban,movimientos){
    Nivel n = nivelParaTest1();
    Sokoban s = Sokoban(n);
    s.mover(Direccion(PuntoCardinal(Norte)));
    EXPECT_EQ(s.persona(),Coord(n.PersonaN().x(),n.PersonaN().y() + 1));
    for (Coord c:n.CajasN()){
        EXPECT_TRUE(s.hayCaja(c));
    }
    s.mover(Direccion(PuntoCardinal(Este)));
    EXPECT_EQ(s.persona(),Coord(n.PersonaN().x() + 1,n.PersonaN().y() + 1));
    EXPECT_TRUE(s.hayCaja(Coord(2,1)));
    s.mover(Direccion(PuntoCardinal(Sur)));
    s.mover(Direccion(PuntoCardinal(Este)));
    EXPECT_EQ(s.persona(),Coord(2,0));
    EXPECT_FALSE(s.puedeMover(0));
    s.mover(1);
    s.mover(Direccion(PuntoCardinal(Norte)));
    s.mover(Direccion(PuntoCardinal(Oeste)));
    s.mover(Direccion(PuntoCardinal(Oeste)));
    s.mover(Direccion(PuntoCardinal(Sur)));
    s.mover(Direccion(PuntoCardinal(Oeste)));
    EXPECT_EQ(s.persona(),Coord(0,0));
    for (int i = 0; i < 8; ++i) {
        s.mover(Direccion(PuntoCardinal(Norte)));
    }
    EXPECT_TRUE(s.hayCaja(Coord(0,9)));
    EXPECT_TRUE(s.mapa().hayDeposito(Coord(0,9)));

}

TEST(Sokoban, ganoNoGano){
    Nivel n = nivelParaTest2();
    Sokoban s = Sokoban(n);
    EXPECT_FALSE(s.gano());
    s.mover(Direccion(PuntoCardinal(Norte)));
    EXPECT_TRUE(s.gano());

}

TEST(Sokoban , tirarBomba){
    Nivel n = nivelParaTest1();
    Sokoban s = Sokoban(n);
    s.mover(Direccion(PuntoCardinal(Este)));
    s.mover(Direccion(PuntoCardinal(Este)));
    s.tirarBomba();
    EXPECT_EQ(s.bombas() , 0);
    EXPECT_FALSE(s.mapa().hayPared(Coord(2,2)));
}

TEST(Sokoban , deshacer) {
    Nivel n = nivelParaTest1();
    Sokoban s = Sokoban(n);
    s.mover(Direccion(PuntoCardinal(Sur)));
    EXPECT_TRUE(s.persona() == Coord(0, -1));
    s.deshacer();
    EXPECT_TRUE(s.persona() == Coord(0, 0));
    s.tirarBomba();
    EXPECT_TRUE(s.bombas() == 0);
    s.deshacer();
    EXPECT_TRUE(s.bombas() == 1);
    EXPECT_TRUE(s.hayCaja(Coord(1, 1)));
    s.mover(Direccion(PuntoCardinal(Norte)));
    s.mover(Direccion(PuntoCardinal(Este)));
    EXPECT_TRUE(s.hayCaja(Coord(2, 1)));
    s.deshacer();
    EXPECT_FALSE(s.hayCaja(Coord(2,1)));
}