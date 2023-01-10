#include "nave.h"
#include "coordinata.h"
#include "griglia.h"
#include "giocatore.h"

#ifndef BATTLESHIP_CORAZZATA_H
#define BATTLESHIP_CORAZZATA_H

class Corazzata : public Nave {
private:
    char simbolo_ = 'C';
    int dimensione_;
    struct Tupla {
        battaglia_navale::Coordinate coord;
        char stato = 'C';
    };
public:
    Corazzata(battaglia_navale::Coordinate &prua, battaglia_navale::Coordinate &poppa);

    bool azione(Giocatore difensore, battaglia_navale::Coordinate &target); //TODO funzione "azione" può essere fatto static
};

#endif //BATTLESHIP_CORAZZATA_H