#include "coordinata.h"
//TODO vector: meglio includerlo qua o nel .cpp?
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
    struct Tupla {
        battaglia_navale::Coordinate coord;
        char stato;
    };
    std::vector<Tupla> corazza_;

    /*
     *  calcolo_verso: date le coordinate di prua e poppa calcola il verso e setta orizzontale: true=orizzontale, false=verticale.
     */
    void calcolo_verso(battaglia_navale::Coordinate &prua, battaglia_navale::Coordinate &poppa);

    /*
     *  calcolo_centro: date le coordinate di prua e poppa calcola la coordinata centrale e setta coordinata_centro_
     */
    battaglia_navale::Coordinate
    calcolo_centro(battaglia_navale::Coordinate &prua, battaglia_navale::Coordinate &poppa);

public:
    /*
     *  costruttore di default
     */
    Nave() = default;

    /*
     *  costruttore per navi con dimensione >= 1
     */
    Nave(battaglia_navale::Coordinate &prua, battaglia_navale::Coordinate &poppa);

    /*
     *  costruttore per navi con dimensione = 1
     */
    Nave(battaglia_navale::Coordinate &prua);

    /*
     *  is_nave: controlla se le coordinate di prua e poppa costituiscono una nave.
     *  Il controllo è basato sulle specifiche richieste dalla consegna del progetto:
     *      -le navi devono essere ortogonali al piano, non ci possono essere navi in obliquo
     *      -le dimensioni di ogni tipo di nave devono essere rispettate: corazzata=5, sottomarino=1, supporto=3.
     *      //TODO is_nave dovrebbe essere protected così è accessibile dalle classi derivate ma non dall'esterno
     */
    bool is_nave(battaglia_navale::Coordinate &prua, battaglia_navale::Coordinate &poppa, int ideal_length);

    /*
     *  sposta_centro: sposta la coordinata centrale di una nave controllando che lo spostamento sia lecito, cioè senza sovrapposizioni con altre navi.
     *  //todo: creare un metodo che controlla data una coordinata se nelle vicinanze, in base al verso della nave da spostare, ci sono sufficienti caselle libere.
     */
    void sposta(battaglia_navale::Coordinate &centro);

    /*
     *  set_corazza: data una coordinata controlla che faccia effettivamente parte della nave e segna come colpita quella posizione di corazza.
     */
    void set_corazza(battaglia_navale::Coordinate &coord);

    /*
     *  azione: data una coordinata agisce sulla griglia avversaria in base al tipo di nave chiamante
     */
    virtual bool azione(Giocatore difensore, battaglia_navale::Coordinate &target);


    //getters
    char get_simbolo() const;

    battaglia_navale::Coordinate get_coordinata_centro() const;

    int get_dimensione() const;

    bool is_orizzontale() const;

    bool is_affondata() const;

    std::vector<Tupla> get_corazza() const;
};

#include "giocatore.h"

#endif //NAVE_H