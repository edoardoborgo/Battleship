#include "coordinata.h"
#include <vector>

#ifndef NAVE_H
#define NAVE_H

class Nave {
public:
    char simbolo_;
    battaglia_navale::Coordinate coordinata_centro_;
    int dimensione_;
    //todo risolvere <Tupla> corazza[dimensione];
    bool is_orizzontale_;

    struct Tupla{
        battaglia_navale::Coordinate c;
        char stato;
    };
    std::vector<Tupla> corazza_;

    /*
     *  costruttore di default
    */
    Nave();
    /*
     *  costruttore utilizzato per la creazione di oggetti nave con dimensione maggiore di 1.
     */
    Nave(battaglia_navale::Coordinate &prua, battaglia_navale::Coordinate &poppa);

    /*
     *  costruttore utilizzato per la creazione di oggetti nave con dimensione uguale a 1.
     */
    Nave(battaglia_navale::Coordinate &prua);

    /*
     *  is_nave: controlla se le coordinate di prua e poppa costituiscono una nave.
     *  Il controllo è basato sulle specifiche richieste dal progetto di Laboratorio di programmazione:
     *      -le navi devono essere ortogonali al piano, non ci possono essere navi in obliquo
     *      -le dimensioni di ogni tipo di nave devono essere rispettate: corazzata=5, sottomarino=1, supporto=3.
     */
    bool is_nave(battaglia_navale::Coordinate &prua, battaglia_navale::Coordinate &poppa, int ideal_length);

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
    /*void sposta_centro(battaglia_navale::Coordinate &centro);

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
    virtual bool azione(Giocatore::player difensore, battaglia_navale::Coordinate &target);
};

#endif NAVE_H