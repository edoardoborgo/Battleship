#include "nave.h"
#include "giocatore.h"

#ifndef BATTLESHIP_SUPPORTO_H
#define BATTLESHIP_SUPPORTO_H

class Supporto : public Nave {
public:
  Supporto()=default;
  Supporto(battaglia_navale::Coordinate &prua, battaglia_navale::Coordinate &poppa);                                    //costruttore, viene
  void azione(Giocatore* attaccante, Giocatore* difensore, battaglia_navale::Coordinate &target) override;
  void set_corazza(battaglia_navale::Coordinate &coord); //TODO
  bool muovi(battaglia_navale::Coordinate &origin,battaglia_navale::Coordinate &target,Giocatore * attaccante);
  void modifica_range(battaglia_navale::Coordinate &start_heal,battaglia_navale::Coordinate &finish_heal);
  bool autocura(battaglia_navale::Coordinate coordinata);
  void cura(Nave* nave, battaglia_navale::Coordinate da_curare);
  bool is_posizionabile(Nave &nave, Giocatore * attaccante);
  Supporto& operator=(const Supporto& source) { return *this ;}
};

#endif //BATTLESHIP_SUPPORTO_H