#include "nave.h"
#include "giocatore.h"
#include <vector>


#ifndef BATTLESHIP_SOTTOMARINO_H
#define BATTLESHIP_SOTTOMARINO_H

class Sottomarino : public Nave {
 private:
  //char simbolo_ = 'E';
  //int dimensione_ = 1;
 public:
  Sottomarino(battaglia_navale::Coordinate &prua);
  void azione(Giocatore* attaccante, Giocatore* difensore, battaglia_navale::Coordinate &target);
  void scan_(Giocatore* difensore, Giocatore* attaccante, battaglia_navale::Coordinate &target);
  //void set_scan_(std::vector<battaglia_navale::Coordinate> coords, Giocatore* attaccante);
  battaglia_navale::Coordinate get_centro();
  void aggiorna_griglia(battaglia_navale::Coordinate& origin, const battaglia_navale::Coordinate& target);
  bool muovi(battaglia_navale::Coordinate &target, Giocatore* attaccante);
  void modifica_range(battaglia_navale::Coordinate &start_scan, battaglia_navale::Coordinate &finish_scan);
};

#endif //BATTLESHIP_SOTTOMARINO_H
