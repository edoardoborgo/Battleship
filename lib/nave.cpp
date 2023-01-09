#include "../include/nave.h"
#include "../include/coordinata.h"
#include "../include/griglia.h"
#include <iostream>
#include <string>

bool Nave::is_nave(battaglia_navale::Coordinate &prua, battaglia_navale::Coordinate &poppa, int ideal_length) {
    if (prua.x == poppa.x && prua.y == poppa.y) {
        return true;
    } else {
        if (prua.x == poppa.x || prua.y == poppa.y) {
            if (prua.x < poppa.x || prua.x > poppa.x) {
                if ((poppa.x - prua.x) == ideal_length || (prua.x - poppa.x) == ideal_length) {
                    return true;
                } else {
                    return false;
                }
            }
            if (prua.y < poppa.y || prua.y > poppa.y) {
                if ((poppa.y - prua.y) == ideal_length || (prua.y - poppa.y) == ideal_length) {
                    return true;
                } else {
                    return false;
                }
            }
        } else {
            return false;
        }
    }
}

void Nave::calcolo_verso(battaglia_navale::Coordinate &prua, battaglia_navale::Coordinate &poppa) {
    if (prua.x == poppa.x) {
        is_orizzontale_ = false; //verticale
    } else {
        is_orizzontale_ = true; //orizontale
    }
}

battaglia_navale::Coordinate Nave::calcolo_centro(battaglia_navale::Coordinate &prua, battaglia_navale::Coordinate &poppa) {
    if (is_orizzontale_ == false) { //se la nave e verticale lavora con le y_
        if (prua.x_ == poppa.x_ && prua.y_ == poppa.y_) {
            coordinata_centro_.x_ = prua.x_;
            coordinata_centro_.y_ = prua.y_;
            return coordinata_centro_;
        }
        if (prua.get_y() < poppa.get_y()) {
            centro.set_y((poppa.get_y() - prua.get_y()) / 2);
            centro.set_x((poppa.get_x() - prua.get_x()) / 2);
        } else {
            centro.set_y((prua.get_y() - poppa.get_y()) / 2);
            centro.set_x((prua.get_x() - poppa.get_x()) / 2);
        }
    } else { //altrimenti se e orizzontale lavora con le x
        if (prua.x == poppa.x && prua.y == poppa.y) {
            centro.set_x(prua.get_x());
            centro.set_y(prua.get_y());
        }
        if (prua.get_x() < poppa.get_x()) {
            centro.set_x((poppa.get_x() - prua.get_x()) / 2);
            centro.set_y((poppa.get_y() - prua.get_y()) / 2);
        } else {
            centro.set_y((prua.get_x() - poppa.get_x()) / 2);
            centro.set_x((prua.get_y() - poppa.get_y()) / 2);
        }
    }
}

    void nave::sposta_centro(Coordinate &nuovo_centro) {
      centro.x = nuovo_centro.x;
      centro.y = nuovo_centro.y;
    }

void Nave::set_corazza(battaglia_navale::Coordinate &coord) {
    for(int i=0; i<corazza_.size(); i++){
        if(corazza_[i].c==coord)
            corazza_[i].stato='c';
    }
}

char Nave::get_nome() {
    return simbolo_;
}

std::vector<Nave::Tupla> Nave::get_corazza(){
    return Nave::corazza_;
}