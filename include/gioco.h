
#ifndef BATTLESHIP_GIOCO_H
#define BATTLESHIP_GIOCO_H

#include "giocatore.h"

class Gioco {
private:
    bool bot_game_;
    bool turno_g1_;
    Giocatore *G1_, *G2_;
    const int numero_massimo_turni = 40;
    int numero_turno_attuale = 0;

    //ritorna un valore casuale per dire chi inizia
    void start_casuale();

    void cambio_turno();

    void check(std::string parametro);

public:
    Gioco(bool scelta_bot_game, Giocatore *G1, Giocatore *G2);

    void azione(std::string origin, std::string target);

    void print_griglie(Giocatore *G);

    bool is_turno_g1();

    bool is_bot_game();
};

#endif //BATTLESHIP_GIOCO_H