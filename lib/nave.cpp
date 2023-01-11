#include "../include/nave.h"
#include "../include/coordinata.h"
#include "../include/griglia.h"
#include <vector>

bool Nave::is_nave(battaglia_navale::Coordinate &prua, battaglia_navale::Coordinate &poppa, int ideal_length) {
    if ((prua.get_x() >= 0 && poppa.get_x() >= 0) && (prua.get_x() < 12 && poppa.get_x() < 12) &&
        (prua.get_y() >= 0 && poppa.get_y() >= 0) && (prua.get_y() < 12 && poppa.get_y() < 12)) {
        if (prua.get_x() == poppa.get_x() && prua.get_y() == poppa.get_y()) {
            return true;
        } else {
            if (prua.get_x() == poppa.get_x() || prua.get_y() == poppa.get_y()) {
                if (prua.get_x() < poppa.get_x() || prua.get_x() > poppa.get_x()) {
                    if ((poppa.get_x() - prua.get_x()) == ideal_length ||
                        (prua.get_x() - poppa.get_x()) == ideal_length) {
                        return true;
                    } else {
                        return false;
                    }
                }
                if (prua.get_y() < poppa.get_y() || prua.get_y() > poppa.get_y()) {
                    if ((poppa.get_y() - prua.get_y()) == ideal_length ||
                        (prua.get_y() - poppa.get_y()) == ideal_length) {
                        return true;
                    } else {
                        return false;
                    }
                }
            } else {
                return false;
            }
        }
    } else {
        throw std::invalid_argument("Coordinate non valide");
    }
}

void Nave::calcolo_verso(battaglia_navale::Coordinate &prua, battaglia_navale::Coordinate &poppa) {
    if (prua.get_x() == poppa.get_x()) {
        orizzontale_ = false; //verticale
    } else {
        orizzontale_ = true; //orizontale
    }
}

battaglia_navale::Coordinate
Nave::calcolo_centro(battaglia_navale::Coordinate &prua, battaglia_navale::Coordinate &poppa) {
    if (orizzontale_ == false) { //se la nave e verticale lavora con le get_y()
        if (prua.get_x() == poppa.get_x() && prua.get_y() == poppa.get_y()) {
            coordinata_centro_.set_x(prua.get_x());
            coordinata_centro_.set_y(prua.get_y());
            return coordinata_centro_;
        }
        if (prua.get_y() < poppa.get_y()) {
            coordinata_centro_.set_y((poppa.get_y() - prua.get_y()) / 2);
            coordinata_centro_.set_x((poppa.get_x() - prua.get_x()) / 2);
            return coordinata_centro_;
        } else {
            coordinata_centro_.set_y((prua.get_y() - poppa.get_y()) / 2);
            coordinata_centro_.set_x((prua.get_x() - poppa.get_x()) / 2);
            return coordinata_centro_;
        }
    } else { //altrimenti se e orizzontale lavora con le get_x()
        if (prua.get_x() == poppa.get_x() && prua.get_y() == poppa.get_y()) {
            coordinata_centro_.set_x(prua.get_x());
            coordinata_centro_.set_y(prua.get_y());
            return coordinata_centro_;
        }
        if (prua.get_x() < poppa.get_x()) {
            coordinata_centro_.set_x((poppa.get_x() - prua.get_x()) / 2);
            coordinata_centro_.set_y((poppa.get_y() - prua.get_y()) / 2);
            return coordinata_centro_;
        } else {
            coordinata_centro_.set_y((prua.get_x() - poppa.get_x()) / 2);
            coordinata_centro_.set_x((prua.get_y() - poppa.get_y()) / 2);
            return coordinata_centro_;
        }
    }
}

/*void nave::sposta_centro(Coordinate &nuovo_centro) {

}*/

void Nave::set_corazza(battaglia_navale::Coordinate &coord) {
    for (int i = 0; i < corazza_.size(); i++) {
        if (corazza_[i].coord == coord) {
            if (corazza_[i].stato >= 65 && corazza_[i].stato <= 90)
                corazza_[i].stato = simbolo_ + 32;
        }
    }
}

char Nave::get_simbolo() {
    return simbolo_;
}

std::vector<Nave::Tupla> Nave::get_corazza() {
    return Nave::corazza_;
}