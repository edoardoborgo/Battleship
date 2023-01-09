#include "../include/corazzata.h"
#include <vector>

Corazzata::Corazzata(battaglia_navale::Coordinate &prua, battaglia_navale::Coordinate &poppa) {
    dimensione_ = 5;
    simbolo_ = 'C';
    if (Nave::is_nave(prua, poppa, dimensione_)) {
        battaglia_navale::Coordinate appo_coord;
        for (int i = 0; i < dimensione_; i++) {
            if (is_orizzontale_) {
                if (prua.get_x() < poppa.get_x()) {
                    appo_coord.set_x(prua.get_x() + i);
                    appo_coord.set_y(prua.get_y());
                } else {
                    appo_coord.set_x(poppa.get_x() + i);
                    appo_coord.set_y(poppa.get_y());
                }
            } else {
                if (prua.get_y() < poppa.get_y()) {
                    appo_coord.set_x(prua.get_x());
                    appo_coord.set_y(prua.get_y() + i);
                } else {
                    appo_coord.set_x(poppa.get_x());
                    appo_coord.set_y(poppa.get_y() + i);
                }
            }
            Nave::Tupla appo_tupla{appo_coord, simbolo_};
            corazza_.push_back(appo_tupla);
        }
        Corazzata::coordinata_centro_ = Nave::calcolo_centro(prua, poppa);
    }
}

//recupero griglia del difensore, controllo se c'è una nave, se true diminuisco corazza e stampo 'X', se false 'O'
bool Corazzata::azione(Giocatore difensore, battaglia_navale::Coordinate &target) {
    std::vector<Nave *> navi = difensore.get_navi(); //recupero le navi dell'avversario
    //per ogni nave confronto l'entità Tupla che rappresenta un elemento di corazza per vedere se corrisponde al target scelto dall'attacante

    for (int i = 0; i < navi.size(); i++) {
        std::vector<Nave::Tupla> corazza = navi[i]->get_corazza();
        for (int j = 0; j < corazza.size(); j++) {
            if (corazza[i].coord == target) {
                //target trovato
                //accedo alla nave, tramite set_corazza cambio lo stato della Tupla in posizione coordinata target
                corazza[i].stato = (char) (navi[i]->simbolo_ + 32);
                navi[i]->set_corazza(target);
                return true; //TODO stampare la X in griglia chiamante
            }
        }
    }
    //target non trovato
    return false; //TODO stampare la O in griglia chiamante
}