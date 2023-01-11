#include "nave.h"
#include "coordinata.h"
#include "griglia.h"
#include "giocatore.h"

#ifndef BATTLESHIP_SUPPORTO_H
#define BATTLESHIP_SUPPORTO_H

class Supporto : public Nave {
 private:
  char simbolo_;
  int dimensione_;
 public:
  Supporto(battaglia_navale::Coordinate &prua, battaglia_navale::Coordinate &poppa);
  bool azione(Giocatore difensore, battaglia_navale::Coordinate &target);
  void set_corazza(battaglia_navale::Coordinate &coord);
  bool muovi(battaglia_navale::Coordinate &origin, battaglia_navale::Coordinate &target);
};

#endif //BATTLESHIP_SUPPORTO_H

