#include "../include/nave.h"

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
                else if (prua.get_y() < poppa.get_y() || prua.get_y() > poppa.get_y()) {
                    if ((poppa.get_y() - prua.get_y()) == ideal_length ||
                        (prua.get_y() - poppa.get_y()) == ideal_length) {
                        return true;
                    } else {
                        return false;
                    }
                }else{
                    return false;
                }
            } else {
                return false;
            }
        }
    } else {
        return false;
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
    if (!orizzontale_) { //se la nave e verticale lavora con le get_y()
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

void Nave::set_corazza(battaglia_navale::Coordinate &coord) {
    for (int i = 0; i < corazza_.size(); i++) {
        if (corazza_[i].coord == coord) {
            if (corazza_[i].stato >= 65 && corazza_[i].stato <= 90)
                corazza_[i].stato = simbolo_ + 32;
        }
    }
}

//TODO sposta nave
void Nave::sposta(battaglia_navale::Coordinate &target) {
    //controllo che non sia affondata
    //controllo che la coordinata centrale di destinazione sia accettabile
    //controllo che le caselle di destinazione siano libere
    //se sono libere cambio i valori X,Y delle coordinate delle tuple

    //nb: se chiamato da supporto: se è orizzontale il target deve essere compreso tra le colonne 1 e 10, se verticale tra le righe 1 e 10 (indici che partono da 0)
    //nb: explorer può andare ovunque perchè sta sotto le navi
    //nb: corazzata non si muove quindi va disabilitata la funzione nella derivata Corazzata
}

//getters
char Nave::get_simbolo() const {
    return simbolo_;
}

std::vector<Nave::Tupla> Nave::get_corazza() const {
    return Nave::corazza_;
}

battaglia_navale::Coordinate Nave::get_coordinata_centro() const {
    return coordinata_centro_;
}

int Nave::get_dimensione() const {
    return dimensione_;
}

bool Nave::is_orizzontale() const {
    return orizzontale_;
}

bool Nave::is_affondata() const {
    return affondata_;
}
//todo controllare se serve battaglia_navale::Coordinate& origin (rimosso perchè già presente nelle celle di corazza)
void Nave::aggiorna_coord(const battaglia_navale::Coordinate& target){
    int indice = 0;
    if(is_orizzontale()){
        for (int i = -((dimensione_-1)/2); i <= +((dimensione_-1)/2) && indice < dimensione_; i++){
            corazza_[indice].coord.set_x(target.get_x()+i);
            corazza_[indice].coord.set_y(target.get_y());
            indice++;
        }
    } else {
        for (int i = -((dimensione_-1)/2); i <= +((dimensione_-1)/2) && indice < dimensione_; i++){
            corazza_[indice].coord.set_x(target.get_x());
            corazza_[indice].coord.set_y(target.get_y()+i);
            indice++;
        }
    }
}



/*
#include <iostream>
#include <string>

#include "../include/Replay.h"

int main(int argc,char** argv) {
    // if screen print
    if (argc < 3 || argc >4)
        throw std::invalid_argument("Invalid number of argumensts");
    if(argc == 3)
    {
        replay_game::Replay replay {argv[2]};
        replay.print();
    }
    // else file print
    else if(argc == 4)
    {
        replay_game::Replay replay {argv[2],argv[3]};
        replay.print();
    }
    return 0;
}
*/