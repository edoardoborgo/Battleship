#include "../include/sottomarino.h"
#include "../include/computer.h"
#include <vector>

Sottomarino::Sottomarino(battaglia_navale::Coordinate &prua) {
  Sottomarino::dimensione_ = 1;
  corazza_.push_back(Nave::Tupla{prua, simbolo_});
}

std::vector<std::vector<char>> Sottomarino::azione(Giocatore difensore, battaglia_navale::Coordinate &target) { //bozza di come dovrebbe essere il metodo (scritto malissimo)
  if(muovi(corazza_[0].coord, target)){ //passo corazza_[0].coord perche' ho bisogno la
    return scan_(difensore, target);
  }else{
      //qualcosa, altrimenti manca il return
  }
}

std::vector<std::vector<char>> Sottomarino::scan_(Giocatore difensore,
                                                  battaglia_navale::Coordinate &target) { //problema con la nominazione del giocatore (che namespace/classe prendo?)
  std::vector<std::vector<char>> griglia_scan_(5, std::vector<char>(5));
  int row = 0, col = 0;
  //battaglia_navale::Coordinate help_(start_scan_.get_x(), start_scan_.get_y());
  if (muovi(coordinata_centro_, target)) {
    battaglia_navale::Coordinate start_scan_(target.get_x() - 2, target.get_y() - 2);
    battaglia_navale::Coordinate finish_scan_(target.get_x() + 2, target.get_y() + 2);
    for (int i = start_scan_.get_y(); i < finish_scan_.get_y() && finish_scan_.get_y() <= 11; i++) {
      if (start_scan_.get_y() >= 0) {
        for (int j = start_scan_.get_x(); j < finish_scan_.get_x() && finish_scan_.get_x() <= 11; j++) {
          if (start_scan_.get_x() >= 0) {
              std::vector<std::vector<char>> griglia = difensore.get_griglia_difesa();
            if (griglia[i][j] != ' ') {         //problema con la visione della coordinata corrispondente a target nella griglia di difesa del player avversario
              griglia_scan_[col][row] = 'Y';
            } else {
              griglia_scan_[col][row] = ' ';
            }
            col++;
          } else {
            col++;
            //scrivi in matrice vuoto ' '
          }
        }
        row++;
      } else {
        row++;
      }
    }
  }
}
/*
y (row)
, , , , ,
, , , , ,
, , E , ,
, , , , ,
, , , , , x (col)
*/

bool Sottomarino::muovi(battaglia_navale::Coordinate &origin,
                        battaglia_navale::Coordinate &target) { //chiarimento sulla derivazione di griglia_difesa se "gia' presente" o devo inserire un parametro da cui la derivo
    if ((target.get_x() >= 0 && target.get_x() <= 11) && (target.get_y() >= 0 && target.get_y() <= 11)) {
      origin.set_x(target.get_x());
      origin.set_y(target.get_y());
      aggiorna_griglia(origin, target);
      return true;
    } else {
        return false;
    }
}

void Sottomarino::set_corazza(battaglia_navale::Coordinate &coord) {
  for (int i = 0; i < corazza_.size(); i++) {
    if (corazza_[i].coord == coord) {
      if (corazza_[i].stato = 'E') {
        corazza_[i].stato = 'e';
      }
    }
  }
}

/*battaglia_navale::Coordinate Sottomarino::get_centro(){
  //return Nave::coordinata_centro_;
  //return Nave::calcolo_centro(battaglia_navale::Coordinate& prua, battaglia_navale::Coordinate& prua);
}
*/