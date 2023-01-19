//Edoardo Borgo

#include "griglia.h"
#include <vector>

#ifndef BATTLESHIP_GIOCATORE_H
#define BATTLESHIP_GIOCATORE_H

class Nave;

class Giocatore {
private:
    //griglia_attacco: griglia che tiene traccia di colpi andati a buon fine, colpi non andati a buon fine e avvistamenti del sonar (explorer).
    battaglia_navale::Griglia griglia_attacco;
    //navi: contiene le navi del giocatore
    std::vector<Nave *> navi;

    /*
     *  is_posizionabile: true se le posizioni occupate dal parametro nave sono liberi nella griglia di difesa del giocatore attivo
     */
    bool is_posizionabile(Nave *nave);

public:
    Giocatore();

    /*
     *  add_nave: aggiunge una nave nella la lista delle navi del giocatore attivo
     */
    void add_nave(Nave *nave);

    /*
     *  set_risultato: salil risultato di un'azione (O/X) nella griglia di attacco dl giocatore attivo
     */
    void set_risultato(battaglia_navale::Coordinate coord, char stato);

    /*
     *  get_navi: restituisce le navi del giocatore attivo
     */
    std::vector<Nave *> get_navi();

    /*
     *  cancella_avvistamenti: modifica la griglia di attacco del giocatore attivo rimuovendo i rilevamenti dell'explorer
     */
    void cancella_avvistamenti();

    /*
     *  get_griglia_attacco: restituisce la griglia di attacco del giocatore attivo
     */
    std::vector<std::vector<char>> &get_griglia_attacco();

    /*
     *  get_griglia_difesa: restituisce la griglia di difesa a partire dalla lista di navi del giocatore attivo
     */
    std::vector<std::vector<char>> get_griglia_difesa();

    bool check_input(std::string input);

    std::string format(std::string input);

    /*
     *  set_log: apre un file in scrittura e inserisce in append la mossa (origin target) eseguita durante il turno
     */
    static void set_log(std::string mosse);

    void affonda_nave(battaglia_navale::Coordinate coord);

    ~Giocatore();
};

//Computer: estende la classe Giocatore implementando la generazione casuale di mosse
class Computer : public Giocatore {

public:
    Computer() : Giocatore() {}

    /*
     *  choose_move: genera casualmente una mossa
     *  origin, coordinata scelta casualmente tra le coordinate centrali delle navi
     *  target, coordinata generata casualmente
     */
    std::string choose_move();

    /*
     *  crea_nave: crea una nave da passare a add_nave che la inserisce tra le navi nel caso in cui sia posizionabile nella griglia
     */
    void crea_nave(int dimensione);

};

#include "nave.h"

#endif //BATTLESHIP_GIOCATORE_H