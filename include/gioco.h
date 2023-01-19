//Edoardo Borgo

#ifndef BATTLESHIP_GIOCO_H
#define BATTLESHIP_GIOCO_H

#include "giocatore.h"
#include "../exceptions/exceptions.h"

class Gioco {
private:
    bool bot_game_;
    bool turno_g1_;
    Giocatore *G1_;
    Giocatore *G2_;
    const int numero_massimo_turni = 40;
    int numero_turno_attuale = 0;
    bool salva_mosse_ = true;
    std::string nome_file_ = "log.txt";

    /*
     *  ritorna un valore casuale per dire chi inizia
     */
    void start_casuale();

    /*
     *  cambio_turno: cambia il turno del giocatore attivo
     */
    void cambio_turno();

    static bool check(std::string parametro);

    std::string format(std::string input);

public:
    //costruttori in base alla tipologia di gioco
    Gioco()=default;
    Gioco(bool scelta_bot_game, Giocatore *G1, Computer *G2);
    Gioco(bool scelta_bot_name, Computer *G1, Computer *G2);
    Gioco(bool turno_G1,Giocatore *G1, Giocatore *G2);
    Gioco(bool turno_G1,Giocatore *G1, Giocatore *G2, std::string nome_file);

    /*
     *  azione: recupera coordinate origin e target e tramite funzione virtuale di nave porta a temrine l'azione
     */
    void azione(const std::string &origin,const std::string& target);

    /*
     *  print_griglie: stampa griglia di attacco e griglia di difesa affiancate
     */
    static void print_griglie(Giocatore *G);

    /*
     *  is_turno_g1: getter di turno_g1_
     */
    bool is_turno_g1() const;

    /*
     *  is_bot_game: getter di bot_game_
     */
    bool is_bot_game() const;

    /*
     *  set_log: stampa la mossa sul file log
     */
    void set_log(std::string mosse);

    void set_salva_mosse(bool salva_mosse, std::string nome_file){
        salva_mosse_ = salva_mosse;
        nome_file_ = nome_file;
    }

    /*
     *  is_game_over: indica se il gioco è finito
     */
    bool is_game_over();

    Giocatore* get_giocatore_attuale();

    ~Gioco();
};

#endif //BATTLESHIP_GIOCO_H