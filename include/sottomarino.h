#include "nave.h"
#include "giocatore.h"
#include <vector>

#ifndef BATTLESHIP_SOTTOMARINO_H
#define BATTLESHIP_SOTTOMARINO_H

class Sottomarino : public Nave {
public:
    /*
     * @prief: costruttore di default di sottomarino
     */
    Sottomarino(){}
    /*
     * @brief: 
     *
     * @param:
     */
    explicit Sottomarino(battaglia_navale::Coordinate &prua);
    void azione(Giocatore* attaccante, Giocatore* difensore, battaglia_navale::Coordinate &target) override;
  void scan_(Giocatore* difensore, Giocatore* attaccante, battaglia_navale::Coordinate &target);
  bool muovi(battaglia_navale::Coordinate &target, Giocatore* attaccante);
  void modifica_range(battaglia_navale::Coordinate &start_scan, battaglia_navale::Coordinate &finish_scan);
};

#endif //BATTLESHIP_SOTTOMARINO_H
