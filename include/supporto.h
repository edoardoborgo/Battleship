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
  void azione(Giocatore difensore, battaglia_navale::Coordinate &target);
  void set_corazza(battaglia_navale::Coordinate &coord);
  void muovi(/*battaglia_navale::Coordinate &origin,*/ battaglia_navale::Coordinate &target,Giocatore &difensore);
  void modifica_range(battaglia_navale::Coordinate centro, battaglia_navale::Coordinate &start_heal,battaglia_navale::Coordinate &finish_heal);
  bool autocura(battaglia_navale::Coordinate coordinata);
  void cura(Nave  * nave);
  bool is_posizionabile(Nave &nave, Giocatore &attaccante);
};

#endif //BATTLESHIP_SUPPORTO_H

