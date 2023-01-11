
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
        Griglia();

        void set_risultato(battaglia_navale::Coordinate coord, char stato);

        void print_griglia();

        //get griglia così è possibile stamparle affiancate stampando in modo alternato la riga i-esima
        std::vector<std::vector<char>> get_griglia();
    };

}

#endif //BATTLESHIP_GRIGLIA_H