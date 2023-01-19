//Mattia Rosa
#include "nave.h"
#include "giocatore.h"

#ifndef BATTLESHIP_SUPPORTO_H
#define BATTLESHIP_SUPPORTO_H

class Supporto : public Nave {
public:
    Supporto()=default;
    //costruttore, viene richiamato il costruttore della classe base
    Supporto(battaglia_navale::Coordinate &prua, battaglia_navale::Coordinate &poppa);
    //viene eseguita l`azione della nave supporto
    void azione(Giocatore* attaccante, Giocatore* difensore, battaglia_navale::Coordinate &target) override;
    //Imposta lo stato della nave nella coordinata passata come argomento su 's' minuscolo  -> è stata colpita
    void set_corazza(battaglia_navale::Coordinate &coord);
    //Vengono verificate le coordinate dove spostarsi se sono libere, in tal caso viene effettuato lo spostamento. Il metodo ritorna true in caso di avvenuto spostamento
    bool muovi(battaglia_navale::Coordinate &origin,battaglia_navale::Coordinate &target,Giocatore * attaccante);
    //Viene mondificato il range di cura in base alla posizione della nave, in modo tale che sia sempre all`interno della tabella 12*12
    void modifica_range(battaglia_navale::Coordinate &start_heal,battaglia_navale::Coordinate &finish_heal);
    //Viene controllato che le coordinate all`interno del range di cura non sia della nave che sta attualmente svolgendo l`azione, in caso la coordinata coincida con una delle coordinate della nave viene restituito true
    bool autocura(battaglia_navale::Coordinate coordinata);
    //Vengono curati i pezzi di navi all`interno del range della cura, Non cura se stessa.
    static void cura(Nave* nave, battaglia_navale::Coordinate da_curare);
    //Verifica in fase di creazione che la nave sia posizionabile
    static bool is_posizionabile(Nave &nave, Giocatore * attaccante);

    Supporto& operator=(const Supporto& source) { return *this ;}
};

#endif //BATTLESHIP_SUPPORTO_H