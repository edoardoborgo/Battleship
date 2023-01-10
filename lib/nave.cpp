#include "../include/nave.h"
#include "../include/coordinata.h"
#include "../include/griglia.h"
#include <vector>

Nave::Nave(){

}

bool Nave::is_nave(battaglia_navale::Coordinate &prua, battaglia_navale::Coordinate &poppa, int ideal_length) {
    if((prua.x_ >= 0 && poppa.x_ >= 0) && (prua.x_ < 12 && poppa.x_ < 12) && (prua.x_ >= 0 && poppa.y_ >= 0) && (prua.y_ < 12 && poppa.y_ < 12)){
        if (prua.x_ == poppa.x_ && prua.y_ == poppa.y_) {
            return true;
        } else {
            if (prua.x_ == poppa.x_ || prua.y_ == poppa.y_) {
                if (prua.x_ < poppa.x_ || prua.x_ > poppa.x_) {
                    if ((poppa.x_ - prua.x_) == ideal_length || (prua.x_ - poppa.x_) == ideal_length) {
                        return true;
                    } else {
                        return false;
                    }
                }
                if (prua.y_ < poppa.y_ || prua.y_ > poppa.y_) {
                    if ((poppa.y_ - prua.y_) == ideal_length || (prua.y_ - poppa.y_) == ideal_length) {
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
        if (prua.y_ < poppa.y_) {
            coordinata_centro_.y_ = (poppa.y_ - prua.y_) / 2;
            coordinata_centro_.x_ = (poppa.x_ - prua.x_) / 2;
            return coordinata_centro_;
        } else {
            coordinata_centro_.y_ = (prua.y_ - poppa.y_) / 2;
            coordinata_centro_.x_ = (prua.x_ - poppa.x_) / 2;
            return coordinata_centro_;
        }
    } else { //altrimenti se e orizzontale lavora con le x_
        if (prua.x_ == poppa.x_ && prua.y_ == poppa.y_) {
            coordinata_centro_.x_ = prua.x_;
            coordinata_centro_.y_ = prua.y_;
            return coordinata_centro_;
        }
        if (prua.get_x() < poppa.get_x()) {
            coordinata_centro_.x_ = (poppa.get_x() - prua.get_x()) / 2;
            coordinata_centro_.y_ = (poppa.get_y() - prua.get_y()) / 2;
            return coordinata_centro_;
        } else {
            coordinata_centro_.y_ = (prua.x_ - poppa.x_) / 2;
            coordinata_centro_.x_ = (prua.y_ - poppa.y_) / 2;
            return coordinata_centro_;
        }
    }
}

/*void nave::sposta_centro(Coordinate &nuovo_centro) {

}*/

void Nave::set_corazza(battaglia_navale::Coordinate &coord) {
    for(int i=0; i<corazza_.size(); i++){
        if(corazza_[i].coord==coord){
            if(corazza_[i].stato>=65 && corazza_[i].stato<=90)
                corazza_[i].stato=simbolo_+32;
        }
    }
}

char Nave::get_nome() {
    return simbolo_;
}

std::vector<Nave::Tupla> Nave::get_corazza(){
    return Nave::corazza_;
}