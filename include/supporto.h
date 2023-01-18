#include "nave.h"
#include "giocatore.h"

#ifndef BATTLESHIP_SUPPORTO_H
#define BATTLESHIP_SUPPORTO_H

class Supporto : public Nave {
 private:
  //char simbolo_ ='S';
  //int dimensione_ = 3;
 public:
    Supporto(){};
  Supporto(battaglia_navale::Coordinate &prua, battaglia_navale::Coordinate &poppa);
  void azione(Giocatore* attaccante, Giocatore* difensore, battaglia_navale::Coordinate &target);
  void set_corazza(battaglia_navale::Coordinate &coord);
  bool muovi(battaglia_navale::Coordinate &origin,battaglia_navale::Coordinate &target,Giocatore * attaccante);
  void modifica_range(battaglia_navale::Coordinate &start_heal,battaglia_navale::Coordinate &finish_heal);
  bool autocura(battaglia_navale::Coordinate coordinata);
  void cura(Nave* nave, battaglia_navale::Coordinate da_curare);
  bool is_posizionabile(Nave &nave, Giocatore * attaccante);
  Supporto& operator=(const Supporto& source) { return *this ;}
};

#endif //BATTLESHIP_SUPPORTO_H