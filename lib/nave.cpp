#include "../include/nave.h"
#include "../include/coordinata.h"

namespace Nave_lib{
  class nave{
    bool is_nave(battaglia_navale::Coordinate &prua, battaglia_navale::Coordinate &poppa, int ideal_length)
    {
      if(prua.x == poppa.x && prua.y == poppa.y){
        return true;
      }
      else{
        if (prua.x == poppa.x || prua.y == poppa.y){
          if(prua.x == poppa.x){
            is_orizzontale true;
          }
          else{
            is_orizzontale = false;
          }
          if(prua.x < poppa.x || prua.x > poppa.x){
            if((poppa.x - prua.x) == ideal_length || (prua.x - poppa.x) == ideal_length){
              return true;
            }
            else{
              return false;
            }
          }
          if(prua.y < poppa.y || prua.y > poppa.y){
            if((poppa.y - prua.y) == ideal_length || (prua.y - poppa.y) == ideal_length ){
              return true;
            }
            else{
              return false;
            }
          }
        }
        else{
          return false;
        }
      }
    }

    void calcolo_direzione(battaglia_navale::Coordinate &prua, battaglia_navale::Coordinate &poppa)
    {

    }

    void calcolo_centro(battaglia_navale::Coordinate &prua, battaglia_navale::Coordinate &poppa)
    {

    }

    Nave(battaglia_navale::Coordinate &prua, battaglia_navale::Coordinate &poppa)
    {

    }

    Nave(battaglia_navale::Coordinate &prua)
    {

    }

    void sposta_centro(battaglia_navale::Coordinate &centro)
    {}

    void set_corazza(int position)
    {}

    void set_corazza(battaglia_navale::Coordinate &coord)
    {

    }

    char get_nome()
    {

    }
  };
}

/*
if (prua.x < poppa.x && prua.y == poppa.y && ((poppa.x - prua.x) == 4 || (poppa.x -prua.x) == 2)){
        return false;
      }
      else if(poppa.x < prua.x && poppa.y == prua.y && ((prua.x - poppa.x) == 4 || (prua.x -poppa.x) == 2)){
        return false;
      }
      else if(poppa.y < prua.y && poppa.x == prua.x && ((prua.y - poppa.y) == 4 || (prua.y -poppa.y) == 2)){
        return false;
      }
      else if (prua.y < poppa.y && prua.x == poppa.x && ((poppa.y - prua.y) == 4 || (poppa.y -prua.y) == 2)){
        return false;
      }
      else if (){

      }
*/