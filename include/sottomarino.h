#include "nave.h"
#include "giocatore.h"
#include <vector>


#ifndef BATTLESHIP_SOTTOMARINO_H
#define BATTLESHIP_SOTTOMARINO_H

class Sottomarino : public Nave {
 public:
  char simbolo_ = 'E';
  int dimensione_;
 private:
  Sottomarino(battaglia_navale::Coordinate &prua);
  std::vector<std::vector<char>> azione(Giocatore difensore, battaglia_navale::Coordinate &target);
  std::vector<std::vector<char>> scan_(Giocatore difensore, battaglia_navale::Coordinate &target);
  bool muovi(battaglia_navale::Coordinate &origin, battaglia_navale::Coordinate &target);
  void set_corazza(battaglia_navale::Coordinate &coord);
  battaglia_navale::Coordinate get_centro();
};

#endif //BATTLESHIP_SOTTOMARINO_H
