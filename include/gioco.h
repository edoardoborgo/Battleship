
#ifndef BATTLESHIP_GIOCO_H
#define BATTLESHIP_GIOCO_H

#include "giocatore.h"
#include "../exceptions/exceptions.h"

class Gioco {
private:
    bool bot_game_;
    bool turno_g1_;
    Giocatore *G1_;
    Giocatore *G2_;    // Cambiato giocatore 2 da computer a Giocatore
    const int numero_massimo_turni = 40;
    int numero_turno_attuale = 0;
    bool salva_mosse_ = true;
    std::string nome_file_ = "log.txt";

    //ritorna un valore casuale per dire chi inizia
    void start_casuale();

    void cambio_turno();

    static bool check(std::string parametro);

    bool check_input(std::string input);

    std::string format(std::string input);
public:
    Gioco()=default;
    Gioco(bool scelta_bot_game, Giocatore *G1, Computer *G2);
    Gioco(bool scelta_bot_name, Computer *G1, Computer *G2);
    Gioco(bool turno_G1,Giocatore *G1, Giocatore *G2);
    Gioco(bool turno_G1,Giocatore *G1, Giocatore *G2, std::string nome_file);

    void azione(const std::string &origin,const std::string& target);

    static void print_griglie(Giocatore *G);

    bool is_turno_g1() const;

    bool is_bot_game() const;

    void set_log(std::string mosse);

    void set_salva_mosse(bool salva_mosse, std::string nome_file){
        salva_mosse_ = salva_mosse;
        nome_file_ = nome_file;
    }

    bool is_game_over();

    Giocatore* get_giocatore_attuale();

    ~Gioco();
};

#endif //BATTLESHIP_GIOCO_H