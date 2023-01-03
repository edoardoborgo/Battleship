#ifndef BATTLESHIP_GRIGLIA_H
#define BATTLESHIP_GRIGLIA_H

#include <iostream>
#include <vector>

namespace battaglia_navale{

    class griglia{

     private:
      static const int righe{12};
      static const int colonne{12};
      const char tabellone[righe][colonne];

     public:
      /*
        costruttore di default della griglia
      */
        griglia(){};

        /*
          @brief inizializza la nave all'interno della griglia
          @param oggetto nave
        */
        void set_nave(Nave& nave);

        void set_centro();

    };

}

#endif //BATTLESHIP_GRIGLIA_H
