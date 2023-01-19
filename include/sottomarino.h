//Giovanni Giancola

#include "nave.h"
#include "giocatore.h"
#include <vector>

#ifndef BATTLESHIP_SOTTOMARINO_H
#define BATTLESHIP_SOTTOMARINO_H

class Sottomarino : public Nave {
public:

    //costruttore di default di sottomarino
    Sottomarino(){}

    //costruttore di Sottomarino parametrizzato
    explicit Sottomarino(battaglia_navale::Coordinate &prua);

    //funzione che si assicura lo spostamento e la scannerizzazione del sottomarino
    void azione(Giocatore* attaccante, Giocatore* difensore, battaglia_navale::Coordinate &target) override;

    //funzione che scannerizza un 5x5 attorno a se stesso (per il controllo della presenza di navi nella griglia aversaria
  void scan_(Giocatore* difensore, Giocatore* attaccante);

  //funzione che cambia le coordinate all'interno della griglia dell'attaccante
  bool muovi(battaglia_navale::Coordinate &target, Giocatore* attaccante);

  //funzione che, nel caso in cui il sottomarino si trovasse in delle posizioni particolari modifica le coordinate di inizio/fine scan
  void modifica_range(battaglia_navale::Coordinate &start_scan, battaglia_navale::Coordinate &finish_scan);
};

#endif //BATTLESHIP_SOTTOMARINO_H
