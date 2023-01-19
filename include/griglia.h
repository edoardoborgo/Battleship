//Giovanni Giancola

#ifndef BATTLESHIP_GRIGLIA_H
#define BATTLESHIP_GRIGLIA_H

#include "coordinata.h"
#include <vector>
#include <iostream>

namespace battaglia_navale {

    class Griglia {
    private:
        const int righe = 12;
        const int colonne = 12;
        std::vector<std::vector<char>> tabellone;

    public:
        //costruttore di griglia
        Griglia();

        //funzione che setta la 'X' (colpita) e la 'O' (mancata) all'interno della griglia di attacco
        void set_risultato(battaglia_navale::Coordinate coord, char stato);

        //get griglia così è possibile stamparle affiancate stampando in modo alternato la riga i-esima
        std::vector<std::vector<char>>& get_griglia();

        //funzione che cancella le y presenti all'interno della griglia di attacco
        void cancella_avvistamenti();
    };

};

#endif //BATTLESHIP_GRIGLIA_H