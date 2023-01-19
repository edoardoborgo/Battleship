//Edoardo Borgo

#include "nave.h"
#include "coordinata.h"
#include "griglia.h"
#include "giocatore.h"

#ifndef BATTLESHIP_CORAZZATA_H
#define BATTLESHIP_CORAZZATA_H

class Corazzata : public Nave {
public:
    Corazzata() : Nave() {}

    Corazzata(battaglia_navale::Coordinate &prua, battaglia_navale::Coordinate &poppa);

    void azione(Giocatore *attaccante, Giocatore *difensore, battaglia_navale::Coordinate &target) override;

    Corazzata &operator=(const Corazzata &source) {
        return *this;
    }

};

#endif //BATTLESHIP_CORAZZATA_H