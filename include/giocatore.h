#include "griglia.h"
#include <vector>

#ifndef BATTLESHIP_GIOCATORE_H
#define BATTLESHIP_GIOCATORE_H

class Nave;

class Giocatore {
private:
    battaglia_navale::Griglia griglia_attacco;
    std::vector<Nave *> navi;

    //controllo se le coordinate della nave sono libere nella "griglia"
    bool is_posizionabile(Nave* nave);

public:
    //costruttore
    Giocatore() =default;

    //aggiunge una nave nella lista di navi
    void add_nave(Nave * nave);

    //setta il risultato (X/O) di un'azione nella griglia di attacco
    void set_risultato(battaglia_navale::Coordinate coord, char stato);

    //restituisce le navi
    std::vector<Nave *> get_navi();

    void cancella_avvistamenti();

    std::vector<std::vector<char>> get_griglia_attacco();

    std::vector<std::vector<char>> get_griglia_difesa();
};

class Computer : public Giocatore{
    //metodo che restituisce origin e target
    //origin scelto tra le navi disonibili
    //target random
    //nel main tramite computer. get origin e computer.get target si recuperano le coordinate da passare a game per eseguire l'azione
    std::string choose_move();
};

#include "nave.h"

#endif //BATTLESHIP_GIOCATORE_H