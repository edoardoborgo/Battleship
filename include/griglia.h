

#ifndef BATTLESHIP_GRIGLIA_H
#define BATTLESHIP_GRIGLIA_H

#include "coordinata.h"
#include <vector>
#include <iostream>

namespace battaglia_navale {

    class Griglia {

    private:
        int righe = 12;
        int colonne = 12;
        std::vector<std::vector<char>> tabellone;

    public:
        Griglia();

        void set_risultato(battaglia_navale::Coordinate coord, char stato);

        void print_griglia();

        /*
          @brief inizializza la nave all'interno della griglia
          @param oggetto nave
        */
        //void set_nave(Nave &nave);

        //void set_centro();

    };
}

#endif //BATTLESHIP_GRIGLIA_H