
#ifndef BATTLESHIP_GIOCO_H
#define BATTLESHIP_GIOCO_H

#include "giocatore.h"

class Gioco{
private:
    bool bot_game;
    bool turno_g1;
    Giocatore *G1, *G2;
    //ritorna un valore casuale per dire chi inizia
    bool get_start_casuale();

public:
    Gioco(std::string versione);
    void azione(battaglia_navale::Coordinate origin, battaglia_navale::Coordinate target);

};

#endif //BATTLESHIP_GIOCO_H
