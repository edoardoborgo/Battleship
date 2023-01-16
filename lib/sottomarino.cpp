#include "../include/sottomarino.h"
#include <vector>

Sottomarino::Sottomarino(battaglia_navale::Coordinate &prua) {
    Sottomarino::dimensione_ = 1;
    corazza_.push_back(Nave::Tupla{prua, simbolo_});
}

void Sottomarino::azione(Giocatore *attaccante, Giocatore *difensore,
                         battaglia_navale::Coordinate &target) { //bozza di come dovrebbe essere il metodo (scritto malissimo)
    if (muovi(target)) { //passo corazza_[0].coord perche' ho bisogno la
        set_scan_(scan_(difensore, target), attaccante);
    } else {
        //qualcosa, altrimenti manca il return eccezzione
    }
}



std::vector<battaglia_navale::Coordinate> Sottomarino::scan_(Giocatore *difensore,
                                                  battaglia_navale::Coordinate &target) { //problema con la nominazione del giocatore (che namespace/classe prendo?)
    std::vector<battaglia_navale::Coordinate> vector_scan_;
    int index = 0;
    //battaglia_navale::Coordinate help_(start_scan_.get_x(), start_scan_.get_y());

    if (muovi(target)) {
        battaglia_navale::Coordinate start_scan_(target.get_x() - 2, (char) (target.get_y() - 2 + 65));
        battaglia_navale::Coordinate finish_scan_(target.get_x() + 2, (char) (target.get_y() + 2 + 65));
        for (int i = start_scan_.get_y(); i < finish_scan_.get_y() && finish_scan_.get_y() <= 11; i++) {
            if (start_scan_.get_y() >= 0 && start_scan_.get_y() <= 11) {
                for (int j = start_scan_.get_x(); j < finish_scan_.get_x() && finish_scan_.get_x() <= 11; j++) {
                    if (start_scan_.get_x() >= 0 && start_scan_.get_y() <= 11) {
                        std::vector<std::vector<char>> griglia = difensore->get_griglia_difesa();
                        if (griglia[i][j] !=
                            ' ') {
                            vector_scan_[i] = battaglia_navale::Coordinate(i, j + 65);
                        }
                    }
                }
            }
        }
    }

    return vector_scan_;
}

bool Sottomarino::muovi(battaglia_navale::Coordinate &target) {
    if ((target.get_x() >= 0 && target.get_x() <= 11) && (target.get_y() >= 0 && target.get_y() <= 11)) {
        Nave::aggiorna_coord(target);
        return true;
    } else {
        return false;
    }
}