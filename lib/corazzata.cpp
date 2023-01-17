#include "../include/corazzata.h"
#include <vector>

Corazzata::Corazzata(battaglia_navale::Coordinate &prua, battaglia_navale::Coordinate &poppa)
    : Nave(prua, poppa, 'C', 5){
}

//recupero griglia del difensore, controllo se c'è una nave, se true diminuisco corazza e stampo 'X', se false 'O'
void Corazzata::azione(Giocatore *attaccante, Giocatore *difensore, battaglia_navale::Coordinate &target) {
    std::vector<Nave *> navi = difensore->get_navi(); //recupero le navi dell'avversario
    //per ogni nave confronto l'entità Tupla che rappresenta un elemento di corazza per vedere se corrisponde al target scelto dall'attacante
    for (int i = 0; i < navi.size(); i++) {
        std::vector<Nave::Tupla> corazza_attaccata = navi[i]->get_corazza();
        for (int j = 0; j < corazza_attaccata.size(); j++) {
            if (corazza_attaccata[i].coord == target) {
                //target trovato
                //accedo alla nave, tramite set_corazza cambio lo stato della Tupla in posizione coordinata target: diventa minuscolo solo se era maiuscolo
                navi[i]->set_corazza(target);
                attaccante->set_risultato(target, 'X');
                return;
            }
        }
    }
    //target non trovato
    attaccante->set_risultato(target, 'O');
}