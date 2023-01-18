#include "../include/sottomarino.h"
#include <vector>

Sottomarino::Sottomarino(battaglia_navale::Coordinate &prua)
        : Nave(prua, prua, 'E', 1) {
}

/*void Sottomarino::set_scan_(std::vector<battaglia_navale::Coordinate> coords, Giocatore *attaccante) {
    std::vector<std::vector<char>> appo_griglia = attaccante->get_griglia_attacco();
    for (int i = 0; i < coords.size(); i++) {
        battaglia_navale::Coordinate appo_coord(coords[i].get_x(), coords[i].get_y() + 65);
        appo_griglia[appo_coord.get_x()][appo_coord.get_y()] = 'Y';
    }
}
*/
void Sottomarino::azione(Giocatore *attaccante, Giocatore *difensore, battaglia_navale::Coordinate &target) { //bozza di come dovrebbe essere il metodo (scritto malissimo)
    if (muovi(target, attaccante)) {
        scan_(difensore, attaccante, target);
    } else {
        //qualcosa, altrimenti manca il return eccezzione
    }
}

void Sottomarino::scan_(Giocatore *difensore, Giocatore *attaccante, battaglia_navale::Coordinate &target) { //problema con la nominazione del giocatore (che namespace/classe prendo?)
    int index = 0;
    //battaglia_navale::Coordinate help_(start_scan_.get_x(), start_scan_.get_y());
    battaglia_navale::Coordinate start_scan_;
    battaglia_navale::Coordinate finish_scan_;
    std::vector<std::vector<char>> griglia_difesa_difensore = difensore->get_griglia_difesa();
    //TODO funz. che ritorna la ref. al tabellone di attacco di attaccante, su cui salvare le Y
    std::vector<std::vector<char>> griglia_attacco_attaccante = attaccante->get_griglia_attacco();
    modifica_range(start_scan_, finish_scan_);
    for (int i = start_scan_.get_y(); i < finish_scan_.get_y(); i++) {
        for (int j = start_scan_.get_x(); j < finish_scan_.get_x(); j++) {
            //std::cout<<"re"<<griglia_difesa_difensore[i][j]<<" ";
            if(griglia_difesa_difensore[i][j] != ' '){
                griglia_attacco_attaccante[i][j] = 'Y';
            }
        }
    }
}

bool Sottomarino::muovi(battaglia_navale::Coordinate &target, Giocatore *attaccante) {
    bool libero = true;
    if ((target.get_x() >= 0 && target.get_x() <= 11) && (target.get_y() >= 0 && target.get_y() <= 11)) {
        int indice_this = 0;                                                                                                            // serve per sapere se nelle coordinate in cui devo spostare la nave sono libere
        std::vector<Nave *> navi = attaccante->get_navi();                                                                   // recupero un vettore con tutte le mie navi per poi poter confrontare tutte le coordinate
        for (int i = 0; i < navi.size(); i++) {
            if (navi[i]->get_coordinata_centro() == this->get_coordinata_centro()) {
                indice_this = i;
                break;
            }
        }
        if (is_orizzontale()) {                                                                                                // divido in due il controllo: se è orrizzontale oppure verticale
            for (int i = 0; i <
                            navi.size(); ++i) { // passo tutte le navi all interno dell array navi// prendo le coordinate della nave che sto prendendo in cosiderazione all`interno dell`array navi ,attraverso la funzione get_corazza e le salvo nell`array aux
                if (i != indice_this) {
                    std::vector<Tupla> aux = navi[i]->get_corazza();
                    for (int j = 0; j < aux.size(); ++j) {                                                                     // passo tutte le coordinate della nave che ho preso in considerazione
                        if (aux[j].coord.get_y() ==
                            target.get_y()) {                                                                  // come prima cose se è orizzontale vado a verificare che la coordinata presa in considerazione abbia la stessa y della coordinata target, se non ce l`ha non effettuo i controlli sulla coordinata x (essendo orizzontale tutte le coordinate hannno la st
                            libero = false;                                                                                // se il match avviene, non posso spostare la nave e quindi libero = false
                        }
                    }
                }
            }
        } else {                                                                                                              // se la nave è verticale l`unica cosa che vado a cambiare è il controllo che effettuo sulla coordinata presa in considerazione
            for (int i = 0; i < navi.size() && libero; ++i) {
                if (i != indice_this) {
                    std::vector<Tupla> aux = navi[i]->get_corazza();
                    for (int j = 0; j < aux.size() && libero; ++j) {
                        if (aux[j].coord.get_x() == target.get_x() && aux[j].coord.get_y() == target.get_y()) {                                                                  // verifico la coordinata x (essendo veritcale non cambia)//vado a verificare le coordinate sopra e sotto (essendo verticale)
                            libero = false;
                        }
                    }
                }
            }
        }
    }

    if (libero) {
        this->aggiorna_coord(target,1);                                                                                            // ho ipotizzato un metodo che è da definire
        return true;                                                                                                   // la nave si è potuta spostare
    } else
        return false;
}

void Sottomarino::modifica_range(battaglia_navale::Coordinate &start_scan, battaglia_navale::Coordinate &finish_scan) {
    battaglia_navale::Coordinate target = this->get_coordinata_centro();

    int sx = 0;
    int dx = 0;
    int up = 0;
    int dw = 0;

    if(target.get_x() <2)
        sx = -target.get_x();
    else
        sx = -2;
    if(target.get_x() >9)
        dx = 11-target.get_x();
    else
        dx = 2;
    if(target.get_y() <2)
        up = -target.get_y();
    else
        up = -2;
    if(target.get_y() >9)
        dw = 11-target.get_y();
    else
        dw = 2;

    start_scan.set_x(target.get_x() + sx);
    start_scan.set_y(target.get_y() + up);
    finish_scan.set_x(target.get_x() + dx);
    finish_scan.set_y(target.get_y() + dw);
}