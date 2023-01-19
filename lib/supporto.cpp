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

/*
serve per sapere se nelle coordinate in cui devo spostare la nave sono libere
serve per sapere se nelle coordinate in cui devo spostare la nave sono libere
recupero un vettore con tutte le mie navi per poi poter confrontare tutte le coordinate
divido in due il controllo: se è orrizzontale oppure verticale
passo tutte le navi all interno dell array navi
prendo le coordinate della nave che sto prendendo in cosiderazione all`interno dell`array navi ,attraverso la funzione get_corazza e le salvo nell`array aux
passo tutte le coordinate della nave che ho preso in considerazione
come prima cose se è orizzontale vado a verificare che la coordinata presa in considerazione abbia la stessa y della coordinata target, se non ce l`ha non effettuo i controlli sulla coordinata x (essendo orizzontale tutte le coordinate hannno la stessa y)
vado a verificare se le cooridinate a destra e a sinistra (essendo orizzontale) a quella della coordinata x della coordinata presa in considerazione della nave
se il match avviene, non posso spostare la nave e quindi libero = false
*/

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

/*void Supporto::muovi(battaglia_navale::Coordinate &target,
                     Giocatore* attaccante) {
    Nave *nave_origin = this;
    std::vector<Nave::Tupla> corazza_input;
    //std::vector<Nave *> navi = attaccante->get_navi();
    for (int i = 0; i < navi.size(); i++) {
        battaglia_navale::Coordinate appo_coord = navi[i]->get_coordinata_centro();
        if (appo_coord == coordinata_centro_)
            nave_origin = navi[i];
        else {
            throw std::invalid_argument("BoatNotFoundException");
        }
    }
    //Nave appo_nave = *nave_origin;


    if (is_posizionabile((*nave_origin), attaccante)) {
        //il posto è libero
        aggiorna_coord(target);
    } else {
        throw std::invalid_argument("InvalidCoordinateException");
    }
}*/

bool Supporto::muovi(battaglia_navale::Coordinate &origin, battaglia_navale::Coordinate &target, Giocatore* attaccante) {
    bool libero = true;
    if ((target.get_x() >= 0 && target.get_x() <= 11) && (target.get_y() >= 0 && target.get_y() <= 11))                     // controllo che le coordinate siano dentro la tabella
    {
        int indice_this = 0;                                                                                                 // serve per sapere se nelle coordinate in cui devo spostare la nave sono libere
        std::vector<Nave *> navi = attaccante->get_navi();                                                                   // recupero un vettore con tutte le mie navi per poi poter confrontare tutte le coordinate
        for (int i = 0; i < navi.size(); i++) {
            if(navi[i]->get_coordinata_centro() == this->get_coordinata_centro()){
                indice_this = i;
                break;
            }
        }
        if (is_orizzontale()) {                                                                                                // divido in due il controllo: se è orrizzontale oppure verticale
            for (int i = 0; i < navi.size(); ++i) { // passo tutte le navi all interno dell array navi// prendo le coordinate della nave che sto prendendo in cosiderazione all`interno dell`array navi ,attraverso la funzione get_corazza e le salvo nell`array aux
                if(i!=indice_this){
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
        } else {                                                                                                              // se la nave è verticale l`unica cosa che vado a cambiare è il controllo che effettuo sulla coordinata presa in considerazione
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

//coordinata centro al posto di target
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
            finish_heal.set_x(target.get_y()+1);
        }else{
            flag = true;
        }
    } else {
        if (target.get_x() == 0) {
            start_heal.set_x(target.get_x() + 1);
            start_heal.set_y(target.get_y() - 1);
            finish_heal.set_y(target.get_y()+1);
            finish_heal.set_x(target.get_x()+1);
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
    if(!muovi(appo_coord ,target, difensore)){
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
                /*int x = std::to_string(aux[j].coord.get_y());  (A = y) (11 = x)
                std::string appo_x = (char)(x[0]+48);*/
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