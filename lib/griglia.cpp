#include "../include/griglia.h"

class griglia{

  griglia(){
    for(int i = 0; i < righe; i++)
    {
      for (int j = 0; j < colonne; j++)
      {
        tabellone[i][j] = ' ';
      }
    }
  }
};
