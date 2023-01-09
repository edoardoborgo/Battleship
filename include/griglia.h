#ifndef BATTLESHIP_GRIGLIA_H
#define BATTLESHIP_GRIGLIA_H

#include "coordinata.h"
#include <vector>
#include <iostream>

namespace battaglia_navale {

    class Griglia {

    private:
        const static int righe=12;
        const static int colonne=12;
        std::vector<std::vector<char>> tabellone {righe, std::vector<char>{colonne}};

    public:

        //costruttore di default della griglia
        //Griglia() {
            /*tabellone[righe][colonne];
            for(int i=0; i<righe; i++){
                for(int j=0; j<colonne; j++){
                    tabellone[i][j]=' ';
                }
            }*/
       // };

        void set_risultato(battaglia_navale::Coordinate coord, bool is_colpito){
            if(is_colpito){
                //tabellone[coord.get_x(),coord.get_y()]='X';
            }else{
                //tabellone[coord.get_x(),coord.get_y()]='X';
            }
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
