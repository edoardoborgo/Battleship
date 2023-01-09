#ifndef BATTLESHIP_GRIGLIA_H
#define BATTLESHIP_GRIGLIA_H

#include "coordinata.h"
#include <vector>
#include <iostream>

namespace battaglia_navale {

    class Griglia {

    private:
        const static int righe = 12;
        const static int colonne = 12;
        std::vector<std::vector<char>> tabellone;
        //vector<vector<int>> myVector(num_of_items, vector<int>(2, 3));

    public:
        Griglia() {
            //inizializzazione vector_char<vector_char>
            for (int col = 0; col < colonne; col++) {
                std::vector<char> appo_vector;
                for (int row = 0; row < righe; row++) {
                    appo_vector.push_back(' ');
                }
                tabellone.push_back(appo_vector);
            }
        };

        void set_risultato(battaglia_navale::Coordinate coord, char stato) {
            tabellone[coord.get_x()][coord.get_y()]=stato;
        }

        /*
          @brief inizializza la nave all'interno della griglia
          @param oggetto nave
        */
        //void set_nave(Nave &nave);

        //void set_centro();

    };

}

#endif //BATTLESHIP_GRIGLIA_H
