//Mattia Rosa
#include "../include/supporto.h"
#include <stdexcept>

Supporto::Supporto(battaglia_navale::Coordinate &prua, battaglia_navale::Coordinate &poppa)
    : Nave(prua, poppa, 'S', 3) {
}

void Supporto::set_corazza(battaglia_navale::Coordinate &coord) {
    for (auto & i : corazza_) {
        if (i.coord == coord) {
            if (i.stato == 'S') {
                i.stato = 's';
            }
        }
    }
}

bool Supporto::is_posizionabile(Nave &nave, Giocatore* attaccante) {
    bool flag = true;
    std::vector<Nave::Tupla> corazza_input = nave.get_corazza();
    for (int i = 0; i < corazza_input.size() && flag; i++) {
        std::vector<Nave *> navi = attaccante->get_navi();
        for (int j = 0; j < navi.size() && flag; j++) {
            std::vector<Nave::Tupla> corazza_test = navi[j]->get_corazza();
            for (int k = 0; k < navi[j]->get_corazza().size() && flag; k++) {
                if (corazza_input[i].coord == corazza_test[k].coord)
                    flag = false;
            }
        }
    }
    return flag;
}

bool Supporto::muovi(battaglia_navale::Coordinate &origin, battaglia_navale::Coordinate &target, Giocatore* attaccante) {
    bool libero = true;
    if ((target.get_x() >= 0 && target.get_x() <= 11) && (target.get_y() >= 0 && target.get_y() <= 11))
    {
        int indice_this = 0;   // tiene traccia della posizione della nave nell`array di navi
        std::vector<Nave *> navi = attaccante->get_navi();
        for (int i = 0; i < navi.size(); i++) {
            if(navi[i]->get_coordinata_centro() == this->get_coordinata_centro()){
                indice_this = i;
                break;
            }
        }
        if (is_orizzontale()) {
            //essendo la nave orizzontale non potrà mai avere il centro lungo il lato dx e sx
            if(target.get_x() == 11 ||  target.get_x() == 0){
                libero = false;
            }
            for (int i = 0; i < navi.size(); ++i) {
                if(i!=indice_this){ //salto il controllo se la nave è quella che sta svolgendo l`azione
                    std::vector<Tupla> aux = navi[i]->get_corazza();
                    for (auto & j : aux) {
                        if (j.coord.get_y() == target.get_y()) { //verifico, essendo orizzontale , prima la coordinata y, in tal caso poi controllo la y
                            //verifico le coordinate a dx e sx del target
                            if (j.coord.get_x() == target.get_x() + 1 || j.coord.get_x() == target.get_x() - 1 || j.coord.get_x() == target.get_x()) {
                                libero = false;
                            }
                        }
                    }
                }
            }
        } else {
            //essendo verticale non potrà mai avere il centro lungo il lato basso o quello alto
            if(target.get_y() == 11 ||  target.get_y() == 0){
                libero = false;
            }// se la nave è verticale l`unica cosa che vado a cambiare è il controllo che effettuo sulla coordinata presa in considerazione
            for (int i = 0; i < navi.size(); ++i) {
                if(i != indice_this)
                {
                    std::vector<Tupla> aux = navi[i]->get_corazza();
                    for (auto & j : aux) {
                        if (j.coord.get_x() == target.get_x()) { //verifico, essendo orizzontale , prima la coordinata y, in tal caso poi controllo la x
                            //verifico le coordinate sopra e sotto il target
                            if (j.coord.get_y() == target.get_y() + 1 || j.coord.get_y() == target.get_y() -1 || j.coord.get_y() == target.get_y()) {
                                libero = false;
                            }
                        }
                    }
                }
            }
        }

        if (libero){
            this->aggiorna_coord(target, this->get_dimensione());
            return true;
        } else{
            return false;
        }
    }
    return false;
}


// vado a modificare le coordinate del range di cura soltanto se la nave si trova lungo i lati, nel resto dei casi il range sarà 3*3
void Supporto::modifica_range(battaglia_navale::Coordinate &start_heal, battaglia_navale::Coordinate &finish_heal){
    battaglia_navale::Coordinate target = this->get_coordinata_centro();
    bool flag = false;
    if (is_orizzontale()) {
        if (target.get_y() == 11) {
            start_heal.set_y(target.get_y()- 1);
            start_heal.set_x(target.get_x()- 1);
            finish_heal.set_y(target.get_y() - 1);
            finish_heal.set_x(target.get_x() + 1);
        } else if (target.get_y() == 0) {
            start_heal.set_y(target.get_y() + 1);
            start_heal.set_x(target.get_x() - 1);
            finish_heal.set_y(target.get_y() +1);
            finish_heal.set_x(target.get_y() + 1);
        }else{
            flag = true;
        }
    } else {
        if (target.get_x() == 0) {
            start_heal.set_x(target.get_x() + 1);
            start_heal.set_y(target.get_y() - 1);
            finish_heal.set_y(target.get_y() + 1);
            finish_heal.set_x(target.get_x() + 1);
        } else if (target.get_x() == 11) {
            start_heal.set_y(target.get_y() - 1);
            start_heal.set_x(target.get_x() - 1);
            finish_heal.set_y(target.get_y() + 1);
            finish_heal.set_x(target.get_x() - 1);
        }else{
            flag = true;
        }
    }
     if(flag)
    {
        start_heal.set_y(target.get_y() - 1);
        start_heal.set_x(target.get_x() - 1);
        finish_heal.set_y(target.get_y() + 1);
        finish_heal.set_x(target.get_x() + 1);
    }
}

void Supporto::azione(Giocatore* attaccante, Giocatore* difensore, battaglia_navale::Coordinate &target) {
    battaglia_navale::Coordinate appo_coord = this->get_coordinata_centro();
    if(!muovi(appo_coord ,target, attaccante)){
        throw std::invalid_argument("non si può muovere");
    }else {

        battaglia_navale::Coordinate start_heal{};
        battaglia_navale::Coordinate finish_heal{};

        modifica_range(start_heal, finish_heal);

        std::vector<Nave *> navi = attaccante->get_navi(); //recupero le navi dell'avversario

        for (auto & i : navi) {
            std::vector<Tupla> aux = i->get_corazza();
            for (int j = 0; j < i->get_dimensione(); ++j) {
                int x = aux[j].coord.get_x();
                char y = (char) (aux[j].coord.get_y() + 65);
                battaglia_navale::Coordinate Coordinata_da_verificare = battaglia_navale::Coordinate(x, y);
                if (Coordinata_da_verificare >= start_heal && Coordinata_da_verificare <= finish_heal) {
                    if (!autocura(Coordinata_da_verificare)) {
                        cura(i,Coordinata_da_verificare);
                    }
                }
            }
        }
    }
}


bool Supporto::autocura(battaglia_navale::Coordinate coordinata) {
    for (int i = 0; i < get_dimensione(); ++i) {
        if (coordinata.get_y() == get_corazza()[i].coord.get_y() &&
            coordinata.get_x() == get_corazza()[i].coord.get_x()) {
            return true;
        }
    }
    return false;
}

void Supporto::cura(Nave * nave, battaglia_navale::Coordinate da_curare) {
    int ascii_code_a = 97;
    int ascii_code_z = 122;
    int to_upper_case = 32;
    std::vector<Tupla> corazza = nave->get_corazza();
    for (auto & i : corazza) {
        if (i.coord.get_x() == da_curare.get_x() && i.coord.get_y() == da_curare.get_y() && i.stato > ascii_code_a && i.stato < ascii_code_z) {
            i.stato -= to_upper_case;
        }
    }
}