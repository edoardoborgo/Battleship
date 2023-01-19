//Giovanni Giancola

#include "../include/sottomarino.h"
#include <vector>

//costruttore di sottomarino che richiama il costruttore della classe base (nave)
Sottomarino::Sottomarino(battaglia_navale::Coordinate &prua)
        : Nave(prua, prua, 'E', 1) {
}

//mossa effettiva della nave (comprende il movimento e lo scan)
void Sottomarino::azione(Giocatore *attaccante, Giocatore *difensore, battaglia_navale::Coordinate &target) {
    //se possibile il movimento scannerizza
    if (muovi(target, attaccante)) {
        scan_(difensore, attaccante);
    } else {
        throw std::invalid_argument("Spostamento non effettuato e scan non partito, rifare");
    }
}

//scan di un 5x5 attorno alla nave (compresa la nave stessa)
void Sottomarino::scan_(Giocatore *difensore, Giocatore *attaccante) {

    battaglia_navale::Coordinate start_scan_{};
    battaglia_navale::Coordinate finish_scan_{};

    //recupero delle griglie di attacco e difesa rispettivamente del'attaccante e del difensore
    //che popi andranno scannerizzate (griglia_difesa_difensore) e modificate (griglia_attacco_attaccante)
    std::vector<std::vector<char>> griglia_difesa_difensore = difensore->get_griglia_difesa();
    std::vector<std::vector<char>> &griglia_attacco_attaccante = attaccante->get_griglia_attacco();

    //nel caso in cui le cordinate fossero particolari vengono modificate prima dello scan effettivo
    modifica_range(start_scan_, finish_scan_);

    for (int i = start_scan_.get_y(); i < finish_scan_.get_y(); i++) {
        for (int j = start_scan_.get_x(); j < finish_scan_.get_x(); j++) {
            if (griglia_difesa_difensore[j][i] != ' ') {
                griglia_attacco_attaccante[j][i] = 'Y';
            }else{
                griglia_attacco_attaccante[j][i] = ' ';
            }
        }
    }

}

//funzione che controlla se:
// -le coordinate di destinazione siano valide
// -non si sovrapponga a se stessa e ad altre navi
//se nessuna di queste due condizioni sia vera, allora lo spostamento si puo effettuare
bool Sottomarino::muovi(battaglia_navale::Coordinate &target, Giocatore *attaccante) {
    bool libero = true;
    if ((target.get_x() >= 0 && target.get_x() <= 11) && (target.get_y() >= 0 && target.get_y() <= 11)) {
        int indice_this = 0;
        std::vector<Nave *> navi = attaccante->get_navi();
        for (int i = 0; i < navi.size(); i++) {
            if (navi[i]->get_coordinata_centro() == this->get_coordinata_centro()) {
                indice_this = i;
                break;
            }
        }
        if (is_orizzontale()) {
            for (int i = 0; i < navi.size(); ++i) {
                if (i != indice_this) {
                    std::vector<Tupla> aux = navi[i]->get_corazza();
                    for (int j = 0; j < aux.size() && libero; ++j) {
                        if (aux[j].coord.get_y() == target.get_y() && aux[j].coord.get_x() == target.get_x()) {
                            libero = false;
                        }
                    }
                }
            }
        } else {
            for (int i = 0; i < navi.size() && libero; ++i) {
                if (i != indice_this) {
                    std::vector<Tupla> aux = navi[i]->get_corazza();
                    for (int j = 0; j < aux.size() && libero; ++j) {
                        if (aux[j].coord.get_x() == target.get_x() && aux[j].coord.get_y() == target.get_y()) {
                            libero = false;
                        }
                    }
                }
            }
        }
    }

    if (libero) {
        this->aggiorna_coord(target, 1);
        return true;
    } else
        return false;
}

//funzione che modifica le coordinate di inizio e fine scan, nel caso in cui fosse negli angolo/nel lato/ o vicino agli angoli
void Sottomarino::modifica_range(battaglia_navale::Coordinate &start_scan, battaglia_navale::Coordinate &finish_scan) {
    battaglia_navale::Coordinate target = this->get_coordinata_centro();


    int sx;
    int dx;
    int up;
    int dw;

    if (target.get_x() < 3)
        sx = -target.get_x();
    else
        sx = -2;
    if (target.get_x() > 10)
        dx = 12 - target.get_x();
    else
        dx = 2;
    if (target.get_y() < 3)
        up = -target.get_y();
    else
        up = -2;
    if (target.get_y() > 10)
        dw = 12 - target.get_y();
    else
        dw = 2;

    start_scan.set_x(target.get_x() + sx);
    start_scan.set_y(target.get_y() + up);
    finish_scan.set_x(target.get_x() + dx);
    finish_scan.set_y(target.get_y() + dw);
}