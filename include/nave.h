//Giovanni Giancola

#include "coordinata.h"
#include <vector>
#include <iostream>

#ifndef NAVE_H
#define NAVE_H

class Giocatore;

class Nave {
public:
    struct Tupla;
private:
    char simbolo_;
    int dimensione_;
    const int to_lower_case = 32;

protected:
    bool orizzontale_;
    std::vector<Tupla> corazza_;
    battaglia_navale::Coordinate coordinata_centro_;

    /*
     *  calcolo_centro: date le coordinate di prua e poppa calcola la coordinata centrale e setta coordinata_centro_
     */
    battaglia_navale::Coordinate
    calcolo_centro(battaglia_navale::Coordinate &prua, battaglia_navale::Coordinate &poppa);

public:
    struct Tupla {
        battaglia_navale::Coordinate coord;
        char stato;
    };

    /*
     *  costruttore di default
     */
    Nave();

    /*
     *  costruttore per navi con dimensione >= 1
     */
    Nave(battaglia_navale::Coordinate &prua, battaglia_navale::Coordinate &poppa, char simbolo, int dimensione);

    /*
     *  costruttore per navi con dimensione = 1
     */
    explicit Nave(battaglia_navale::Coordinate &prua);

    /*
     *  is_nave: controlla se le coordinate di prua e poppa costituiscono una nave.
     *  Il controllo è basato sulle specifiche richieste dalla consegna del progetto:
     *      -le navi devono essere ortogonali al piano, non ci possono essere navi in obliquo
     *      -le dimensioni di ogni tipo di nave devono essere rispettate: corazzata=5, sottomarino=1, supporto=3
     */
    static bool is_nave(battaglia_navale::Coordinate &prua, battaglia_navale::Coordinate &poppa, int ideal_length);

    /*
     *  set_corazza: data una coordinata controlla che faccia effettivamente parte della nave e segna come colpita quella posizione di corazza.
     *  (rendendo il carattere minuscolo)
     */
    void set_corazza(battaglia_navale::Coordinate &coord);

    /*
     *  azione: data una coordinata di destinazione agisce sulla griglia avversaria in base al tipo di nave chiamante
     */
    virtual void azione(Giocatore *attaccante, Giocatore *difensore, battaglia_navale::Coordinate &target) = 0;

    /*
     * aggiorna_griglia: metodo che aggiorna tutte le coordinate della corazza nave, per poi aggiornarne anche il centro
    */
    void aggiorna_coord(const battaglia_navale::Coordinate& target, int dimensione_ideale);

    //getters:
    char get_simbolo() const;

    battaglia_navale::Coordinate get_coordinata_centro() const;

    int get_dimensione() const;

    bool is_orizzontale() const;

    bool is_affondata() const;

    std::vector<Tupla> get_corazza() const;

    virtual ~Nave()=default;
};

#include "giocatore.h"

#endif //NAVE_H