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
    Giocatore();

    void add_nave(Nave nave);

    //funzione che modifica la griglia di attacco
    //oppure fare un metodo get griglia e tramite reference alla griglia chiamare set_risultato, evitando questa funzione
    void set_risultato(battaglia_navale::Coordinate coord, char stato) {
        griglia_attacco.set_risultato(coord, stato);
    }

    std::vector<Nave *> get_navi() {
        return navi;
    }
};

#endif //BATTLESHIP_GIOCATORE_H
