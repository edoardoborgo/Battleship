#include "griglia.h"
#include "nave.h"
#include <vector>

#ifndef BATTLESHIP_GIOCATORE_H
#define BATTLESHIP_GIOCATORE_H

class Giocatore {
private:
    battaglia_navale::Griglia griglia_attacco;
    std::vector<Nave *> navi;
public:
    //costruttore su classi derivate
    void add_nave(Nave nave);
    //funzione che controlla se in una determinata coordinata c'è una nave
    //

    //funzione che modifica la griglia di attacco
    void set_risultato(){
        griglia_attacco.
    }
    std::vector<Nave *> get_navi() {
        return navi;
    }
};

#endif //BATTLESHIP_GIOCATORE_H
