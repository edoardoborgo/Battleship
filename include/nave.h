#include "coordinata.h"

#ifndef BATTLESHIP_NAVE_H
#define BATTLESHIP_NAVE_H

namespace Nave_lib{
    class Nave{
        std::string nome;
        coordinata centro;
        int dimensione;
        //todo risolvere bool corazza[dimensione];
        bool is_orizzontale;

    private:
        /*
         *  is_nave: controlla se le coordinate di prua e poppa costituiscono una nave.
         *  Il controllo è basato sulle specifiche richieste dal progetto di Laboratorio di programmazione:
         *      -le navi devono essere ortogonali al piano, non ci possono essere navi in obliquo
         *      -le dimensioni di ogni tipo di nave devono essere rispettate: corazzata=5, sottomarino=1, supporto=3.
         */
        bool is_nave(coordinata &prua, coordinata &poppa);

        /*
         *  calcolo_verso: date le coordinate di prua e poppa calcola il verso e setta @param is_orizzontale: true=orizzontale, false=verticale.
         */
        void calcolo_verso(coordinata &prua, coordinata &poppa);

        /*
         *  calcolo_centro: date le coordinate di prua e poppa calcola la coordinata centrale e setta @param centro.
         */
        void calcolo_centro(coordinata &prua, coordinata &poppa);
    protected:
        //todo: scegliere se fare due costruttori diversi o se fare in modo che il costruttore per le navi con dim.=1 acquisisca in input due coordinate uguali
        /*
         *  costruttore utilizzato per la creazione di oggetti nave con dimensione maggiore di 1.
         */
        Nave(coordinata &prua, coordinata &poppa);
        /*
         *  costruttore utilizzato per la creazione di oggetti nave con dimensione maggiore uguale a 1.
         */
        Nave(coordinata &prua);
    public:
        /*
         *  sposta_centro: sposta la coordinata centrale di una nave controllando che lo spostamento sia lecito, cioè senza sovrapposizioni con altre navi.
         *  //todo: creare un metodo che controlla data una coordinata se nelle vicinanze, in base al verso della nave da spostare, ci sono sufficienti caselle libere.
         */
        void sposta_centro(coordinata &centro);
        //todo azione(target), forse virtual?
        void set_corazza(position);
        std::string get_nome();
    };
}

#endif //BATTLESHIP_NAVE_H
