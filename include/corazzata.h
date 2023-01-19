//Edoardo Borgo
#include "nave.h"
#include "coordinata.h"
#include "griglia.h"
#include "giocatore.h"

#ifndef BATTLESHIP_CORAZZATA_H
#define BATTLESHIP_CORAZZATA_H

class Corazzata : public Nave {
private:
    /*struct Tupla {
        battaglia_navale::Coordinate coord;
        char stato = 'C';
    };*/
public:
    Corazzata() : Nave() { }

    //Corazzata(const Corazzata&){ }

    Corazzata(battaglia_navale::Coordinate &prua, battaglia_navale::Coordinate &poppa);

    void azione(Giocatore *attaccante, Giocatore *difensore, battaglia_navale::Coordinate &target) override ;

    Corazzata& operator=(const Corazzata& source){
        return *this;
    }

};

#endif //BATTLESHIP_CORAZZATA_H