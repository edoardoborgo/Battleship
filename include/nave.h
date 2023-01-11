#include "coordinata.h"
#include <vector>

#ifndef NAVE_H
#define NAVE_H

class Giocatore;

class Nave {
private:
    char simbolo_;
    battaglia_navale::Coordinate coordinata_centro_;
    int dimensione_;
    bool orizzontale_;
    bool affondata_;
    struct Tupla{
        battaglia_navale::Coordinate coord;
        char stato;
    };
    std::vector<Tupla> corazza_;

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
    battaglia_navale::Coordinate calcolo_centro(battaglia_navale::Coordinate &prua, battaglia_navale::Coordinate &poppa);

public:

    Nave(){};

    Nave(battaglia_navale::Coordinate &prua, battaglia_navale::Coordinate &poppa);

    Nave(battaglia_navale::Coordinate &prua);

    /*
     *  sposta_centro: sposta la coordinata centrale di una nave controllando che lo spostamento sia lecito, cioè senza sovrapposizioni con altre navi.
     *  //todo: creare un metodo che controlla data una coordinata se nelle vicinanze, in base al verso della nave da spostare, ci sono sufficienti caselle libere.
     */
    void sposta_centro(battaglia_navale::Coordinate &centro);

    /*
     *  set_corazza: data una coordinata controlla che faccia effettivamente parte della nave e segna come colpita quella posizione di corazza.
     */
    void set_corazza(battaglia_navale::Coordinate &coord);

    /*
     *  azione: data una coordinata deve andare ad agire sulla griglia difensiva dell'avversario
     */
    virtual bool azione(Giocatore difensore, battaglia_navale::Coordinate &target);


    char get_simbolo();
    battaglia_navale::Coordinate get_coordinata_centro();
    int get_dimensione();
    bool is_orizzontale();
    bool is_affondata();
    std::vector<Tupla> get_corazza();
};

#include "giocatore.h"

#endif //NAVE_H

