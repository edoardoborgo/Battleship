#include "../include/sottomarino.h"
#include "../include/giocatore.h"
#include "../include/computer.h"
#include <vector>

Sottomarino::Sottomarino(battaglia_navale::Coordinate &prua) {
  Sottomarino::dimensione_ = 1;
  corazza_.push_back(Nave::Tupla{prua, simbolo_});
}

void Sottomarino::azione(/*Giocatore::player difensore,*/ battaglia_navale::Coordinate &target) { //bozza di come dovrebbe essere il metodo (scritto malissimo)
  /*if(e' possibile muoversi entro i limiti allora... a.k.a. -> muovi(this.get_centro(), target) == true){
   * permetti lo scan a.k.a. -> scan(Giocatore::player difensore, target)
   *}
  */
}

std::vector<std::vector<char>> Sottomarino::scan_(/*Giocatore::player difensore,*/ battaglia_navale::Coordinate &target) { //problema con la nominazione del giocatore (che namespace/classe prendo?)
  std::vector<std::vector<char>> scan_(5, std::vector<char>(5));
  int row = 0, col = 0;
  if (muovi(coordinata_centro_, target)) {
    battaglia_navale::Coordinate start_scan_(target.get_x() - 2, target.get_y() - 2);
    battaglia_navale::Coordinate finish_scan_(target.get_x() + 2, target.get_y() + 2);
    for (int i = start_scan_.get_y(); i < finish_scan_.get_y(); i++) {
      for (int j = start_scan_.get_x(); j < finish_scan_.get_x(); j++) {
        if (difensore.griglia_difesa[target.get_x(), target.get_y()]
            != ' ') {         //problema con la visione della coordinata corrispondente a target nella griglia di difesa del player avversario
          scan_[row][col] = 'Y';
        } else {
          scan_[row][col] = ' ';
        }
        row++;
      }
      col++;
    }
  }
}
/*
y (row)
, , , , ,
, , , , ,
, , , , ,
, , , , ,
, , , , , x (col)
*/

bool Sottomarino::muovi(battaglia_navale::Coordinate &origin, battaglia_navale::Coordinate &target) { //chiarimento sulla derivazione di griglia_difesa se "gia' presente" o devo inserire un parametro da cui la derivo
  try {
    if (griglia_difesa[target.get_x(), target.get_y()] == "") {
      if (is_orizzontale_) {
        if ((target.get_x() >= 0 && target.get_x() <= 11) && (target.get_y() >= 0 && target.get_y() <= 11)) {
          if (griglia_difesa[target.get_x() - 1][target.get_y()] == " "
              && griglia_difesa[target.get_x() + 1][target.get_y()] == " ") {
            origin.set_x(target.get_x());
            origin.set_y(target.get_y());
            aggiorna_griglia(origin, target);
            return true;
          }
        } else {
          throw std;;std::errc::invalid_argument("non e' possibile muovere in questo punto");
        }
      }
    }
  } catch (std::out_of_range e) {
    return false;
  }

}

void Sottomarino::set_corazza(battaglia_navale::Coordinate &coord) {
  for (int i = 0; i < corazza_.size(); i++) {
    if (corazza_[i].c == coord) {
      if (corazza_[i].stato = 'E') {
        corazza_[i].stato = 'e';
      }
    }
  }
}