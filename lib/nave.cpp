#include "../include/nave.h"
#include "../include/coordinata.h"
#include "../include/griglia.h"
#include <iostream>
#include <string>

    bool nave::is_nave(Coordinate &prua, Coordinate &poppa, int ideal_length) {
      if (prua.x == poppa.x && prua.y == poppa.y) {
        return true;
      } else {
        if (prua.x == poppa.x || prua.y == poppa.y) {
          if (prua.x < poppa.x || prua.x > poppa.x) {
            if ((poppa.x - prua.x) == ideal_length || (prua.x - poppa.x) == ideal_length) {
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

    void nave::calcolo_verso(Coordinate &prua, Coordinate &poppa){
      if (prua.x == poppa.x) {
        is_orizzontale = false; //verticale
      } else {
        is_orizzontale = true; //orizontale
      }
    }

    void nave::calcolo_centro(Coordinate &prua, Coordinate &poppa) {
      if (is_orizzontale == false) { //se la nave e verticale lavora con le y
        if (prua.get_x() == poppa.get_x() && prua.get_y() == poppa.get_y()) {
          centro.set_x(prua.get_x());
          centro.set_y(prua.get_y());
        }
        if (prua.get_y() < poppa.get_y()) {
          centro.set_y((poppa.get_y() - prua.get_y()) / 2);
          centro.set_x((poppa.get_x() - prua.get_x()) / 2);
        } else {
          centro.set_y((prua.get_y() - poppa.get_y()) / 2);
          centro.set_x((prua.get_x() - poppa.get_x()) / 2);
        }
      }
      else { //altrimenti se e orizzontale lavora con le x
        if (prua.x == poppa.x && prua.y == poppa.y) {
          centro.set_x(prua.get_x());
          centro.set_y(prua.get_y());
        }
        if (prua.get_x() < poppa.get_x()) {
          centro.set_x((poppa.get_x() - prua.get_x()) / 2);
          centro.set_y((poppa.get_y() - prua.get_y()) / 2);
        } else {
          centro.set_y((prua.get_x() - poppa.get_x()) / 2);
          centro.set_x((prua.get_y() - poppa.get_y()) / 2);
        }
      }
    }

    void nave::sposta_centro(Coordinate &nuovo_centro) {
      centro.x = nuovo_centro.x;
      centro.y = nuovo_centro.y;
    }

    void nave::set_corazza(Coordinate &coord) {
      if (is_orizzontale == true) {

      }
    }

    char get_nome()
    {

    }