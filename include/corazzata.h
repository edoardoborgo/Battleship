#include "nave.h"
#include "coordinata.h"
#include "griglia.h"
#include "giocatore.h"

#ifndef BATTLESHIP_CORAZZATA_H
#define BATTLESHIP_CORAZZATA_H

class Corazzata : public Nave {
private:
    //char simbolo_;
    //int dimensione_;
    struct Tupla {
        battaglia_navale::Coordinate coord;
        char stato = 'C';
    };*/
public:
    Corazzata() : Nave() { }

    Corazzata(battaglia_navale::Coordinate &prua, battaglia_navale::Coordinate &poppa);

    void azione(Giocatore *attaccante, Giocatore *difensore, battaglia_navale::Coordinate &target) override ;

    Corazzata& operator=(const Corazzata& source){
        return *this;
    }

    void get_francesco(){
        std::cout<<"francesco ma corazzato";
    }

    Corazzata(const Corazzata&){

    }

    /*Corazzata& operator = (const Corazzata& source)    //assignment operator
    {
        if (this == &source)    //avoid self-assignment
            return *this;
        m_id = source.m_id;
        return *this;
    }*/
};

#endif //BATTLESHIP_CORAZZATA_H