
#ifndef BATTLESHIP_GIOCO_H
#define BATTLESHIP_GIOCO_H

#include "giocatore.h"
#include "../exceptions/exceptions.h"

class Gioco {
private:
    bool bot_game_;
    bool turno_g1_;
    Giocatore *G1_;
    Computer * G2_;
    const int numero_massimo_turni = 40;
    int numero_turno_attuale = 0;

    //ritorna un valore casuale per dire chi inizia
    void start_casuale();

    void cambio_turno();

    void check(std::string parametro);

    bool check_input(std::string input);
    std::string format(std::string input);
public:
    //TODO creare un costruttore che inizializza il player attivo come da specifica proveniente dal log
    Gioco(bool scelta_bot_game, Giocatore *G1, Computer *G2);
    Gioco(bool scelta_bot_name, Computer *G1, Computer *G2);

    void azione(std::string origin, std::string target);

    void print_griglie(Giocatore *G);

    bool is_turno_g1();

    bool is_bot_game();

    void set_log(std::string mosse);

    bool is_game_over();

    Giocatore* get_giocatore_attuale();
};

#endif //BATTLESHIP_GIOCO_H