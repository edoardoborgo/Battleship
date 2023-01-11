#include "griglia.h"
#include "nave.h"
#include <vector>

#ifndef BATTLESHIP_GIOCATORE_H
#define BATTLESHIP_GIOCATORE_H

class Giocatore {
private:
    battaglia_navale::Griglia griglia_attacco;
    std::vector<Nave *> navi;

    //controllo se le coordinate della nave sono libere nella "griglia"
    bool is_posizionabile(Nave &nave);

public:
    //costruttore
    Giocatore() =default;

    //aggiunge una nave nella lista di navi
    void add_nave(Nave nave);

    //setta il risultato (X/O) di un'azione nella griglia di attacco
    void set_risultato(battaglia_navale::Coordinate coord, char stato);

    //restituisce le navi
    std::vector<Nave *> get_navi();
};

#endif //BATTLESHIP_GIOCATORE_H
