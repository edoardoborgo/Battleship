
#ifndef BATTLESHIP_GIOCO_H
#define BATTLESHIP_GIOCO_H

#include "giocatore.h"

class Gioco{
private:
    bool bot_game_;
    bool turno_g1_;
    Giocatore *G1_, *G2_;
    //ritorna un valore casuale per dire chi inizia
    void start_casuale();
    void prossimo_turno();

public:
    Gioco(bool scelta_bot_game, Giocatore *G1, Giocatore *G2);
    void azione(std::string origin, std::string target);
    void print_griglie(Giocatore *G);
};

#endif //BATTLESHIP_GIOCO_H