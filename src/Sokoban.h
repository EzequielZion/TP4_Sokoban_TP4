#ifndef TP4_SOKOBAN_SOKOBAN_H
#define TP4_SOKOBAN_SOKOBAN_H
#include "Mapa.h"
#include "Coord.h"
#include "Nivel.h"
#include "Direccion.h"


class Sokoban {
public:
    Sokoban(Nivel n);
    void deshacer();
    void mover(Direccion dir);
    Mapa mapa();
    Nat bombas();
    Coord persona();
    bool hayCaja(Coord c);
    bool hayDeposito(Coord c);

private:
    set<Coord> _cajas;
    Mapa _mapa;
    Nat _bombas;
    Coord _persona;
    Nat _depositosSinCaja;
    //Pila _historial; o lo que sea que implementemos para esto
};

//Hay cosas que puse copiando directamente
// del docs que se entremezclan con Nivel y Mapa que no sé si tienen que ir
// en el cpp y creo que es mejor que las discutamos entre todos je
//(tal vez sí tienen que ir y yo soy medio colgado nomás lmao)

#endif //TP4_SOKOBAN_SOKOBAN_H
