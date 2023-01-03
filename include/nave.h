#include "coordinata.h"

#ifndef BATTLESHIP_NAVE_H
#define BATTLESHIP_NAVE_H

namespace Nave_lib{
    class Nave{
        char simbolo;
        battaglia_navale::Coordinate centro;
        int dimensione;
        //todo risolvere bool corazza[dimensione];
        bool is_orizzontale;
        //bool is_nave;

    protected:
        //todo: scegliere se fare due costruttori diversi o se fare in modo che il costruttore per le navi con dim.=1 acquisisca in input due coordinate uguali
        /*
         *  costruttore utilizzato per la creazione di oggetti nave con dimensione maggiore di 1.
         */
        virtual Nave(battaglia_navale::Coordinate &prua, battaglia_navale::Coordinate &poppa);
        /*
         *  costruttore utilizzato per la creazione di oggetti nave con dimensione uguale a 1.
         */
        virtual Nave(battaglia_navale::Coordinate &prua);
    public:
        /*
         *  is_nave: controlla se le coordinate di prua e poppa costituiscono una nave.
         *  Il controllo è basato sulle specifiche richieste dal progetto di Laboratorio di programmazione:
         *      -le navi devono essere ortogonali al piano, non ci possono essere navi in obliquo
         *      -le dimensioni di ogni tipo di nave devono essere rispettate: corazzata=5, sottomarino=1, supporto=3.
         */
        bool is_nave(battaglia_navale::Coordinate &prua, battaglia_navale::Coordinate &poppa);
        /*
         *  calcolo_verso: date le coordinate di prua e poppa calcola il verso e setta @param is_orizzontale: true=orizzontale, false=verticale.
         */
        void calcolo_verso(battaglia_navale::Coordinate &prua, battaglia_navale::Coordinate &poppa);
        /*
         *  calcolo_centro: date le coordinate di prua e poppa calcola la coordinata centrale e setta @param centro.
         */
        void calcolo_centro(battaglia_navale::Coordinate &prua, battaglia_navale::Coordinate &poppa);
        /*
         *  sposta_centro: sposta la coordinata centrale di una nave controllando che lo spostamento sia lecito, cioè senza sovrapposizioni con altre navi.
         *  //todo: creare un metodo che controlla data una coordinata se nelle vicinanze, in base al verso della nave da spostare, ci sono sufficienti caselle libere.
         */
        void sposta_centro(battaglia_navale::Coordinate &centro);
        /*
         *  set_corazza: data una posizione (entro i limiti della nave) segna come colpita quella posizione di corazza.
         */
        void set_corazza(int position);
        /*
         *  set_corazza: data una coordinata controlla che faccia effettivamente parte della nave e segna come colpita quella posizione di corazza.
         */
        void set_corazza(battaglia_navale::Coordinate &coord);
        /*
         *  get_nome: restituisce il simbolo di una nave, serve per riprodurre graficamente la nave nella griglia.
         */
        char get_nome();
        /*
         *  azione: data una coordinata deve andare ad agire sulla griglia difensiva dell'avversario
         */
        //virtual void azione(target);
    };
}

#endif //BATTLESHIP_NAVE_H




bool is_nave(coor prua, coord poppa, ideal_length){
  if(prua.x!=poppa.x && prua.y!=poppa.y){
    return false;
  }else{
    if(prua.y==poppa.y) {
      is_orizzontale = true;
      if (prua.x < poppa.x) {
        if ((prua.x + ideal_length) == poppa.x)
          return true;
        else
          return false;
        if ((prua.x - ideal_length) == poppa.x)
          return true;
        else
          return false;
      }
    }else if(prua.x==poppa.x){
      is_orizzontale=false;
      if (prua.y<poppa.y) {
        if ((prua.y + ideal_length) == poppa.y)
          return true;
        else
          return false;
        if ((prua.x - ideal_length) == poppa.x)
          return true;
        else
          return false;
      }
    }
  }
}