#include "../include/supporto.h"
#include "../include/giocatore.h"
#include <stdexcept>

Supporto::Supporto(battaglia_navale::Coordinate &prua, battaglia_navale::Coordinate &poppa)
    : Nave(prua, poppa, 'S', 3) {

}

void Supporto::set_corazza(battaglia_navale::Coordinate &coord) {
    for (int i = 0; i < corazza_.size(); i++) {
        if (corazza_[i].coord == coord) {
            if (corazza_[i].stato == 'S') {
                corazza_[i].stato = 's';
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

bool Supporto::is_posizionabile(Nave &nave, Giocatore &attaccante) {
    bool flag = true;
    std::vector<Nave::Tupla> corazza_input = nave.get_corazza();
    for (int i = 0; i < corazza_input.size() && flag; i++) {
        std::vector<Nave *> navi = attaccante.get_navi();
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

void Supporto::muovi(battaglia_navale::Coordinate &target,
                     Giocatore &attaccante) {
    Nave *nave_origin;
    std::vector<Nave::Tupla> corazza_input;
    std::vector<Nave *> navi = attaccante.get_navi();
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
}



void Supporto::modifica_range(battaglia_navale::Coordinate target, battaglia_navale::Coordinate &start_heal,
                              battaglia_navale::Coordinate &finish_heal)  //todo rifare il metodo con le variabili giuste e dare un nome sensato
//todo verificare se il metodo è giusto anche sul lato logico
{
    if (is_orizzontale()) {
        if (target.get_y() == 12) {
            start_heal.set_y(target.get_y() - 1);
            start_heal.set_x(target.get_x() - 1);
            finish_heal.set_y(target.get_y() - 1);
            finish_heal.set_x(target.get_x() + 1);
        } else if (target.get_y() == 1) {
            start_heal.set_y(target.get_y() + 1);
            start_heal.set_x(target.get_x() - 1);
            finish_heal.set_y(target.get_y() + 1);
            finish_heal.set_x(target.get_x() + 1);
        }
    } else {
        if (target.get_x() == 1) {
            start_heal.set_x(target.get_x() + 1);
            start_heal.set_y(target.get_y() - 1);
            finish_heal.set_y(target.get_y() + 1);
            finish_heal.set_x(target.get_x() + 1);
        } else if (target.get_x() == 12) {
            start_heal.set_x(target.get_x() - 1);
            start_heal.set_y(target.get_y() - 1);
            finish_heal.set_y(target.get_y() + 1);
            finish_heal.set_x(target.get_x() - 1);
        }
    }
}

void Supporto::azione(Giocatore difensore, battaglia_navale::Coordinate &target) {

    muovi(target, difensore);

    battaglia_navale::Coordinate start_heal(target.get_x() - 1, (char) (target.get_y() - 1 + 65));
    battaglia_navale::Coordinate finish_heal(target.get_x() + 1, (char) (target.get_y() + 1 + 65));

    modifica_range(target, start_heal, finish_heal);

    std::vector<Nave *> navi = difensore.get_navi(); //recupero le navi dell'avversario

    for (int i = 0; i < navi.size(); ++i) {
        std::vector<Tupla> aux = navi[i]->get_corazza();
        for (int j = 0; j < navi[i]->get_dimensione(); ++j) {
            battaglia_navale::Coordinate Coordinata_da_verificare = battaglia_navale::Coordinate{aux[j].coord.get_x(),
                                                                                                 (char) (aux[j].coord.get_y() +
                                                                                                    65)};  //todo non so se sia giusto
            if (Coordinata_da_verificare >= start_heal && Coordinata_da_verificare <= finish_heal) {
                if (!autocura(Coordinata_da_verificare)) {
                    cura(navi[i]);
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

void Supporto::cura(Nave *nave) {
    for (int i = 0; i < nave->get_dimensione(); ++i) {
        if (nave->get_corazza()[i].stato > 96) {
            nave->get_corazza()[i].stato -= 32;
        }
    }
}

/*
  bool Supporto::muovi(battaglia_navale::Coordinate &origin, battaglia_navale::Coordinate &target){
    if((target.get_x() >= 0 && target.get_x() <= 12) && (target.get_y() >= 1 && target.get_y() <= 12))  // controllo che le coordinate siano dentro la tabella
    {
        bool libero = true;                                                                                                // serve per sapere se nelle coordinate in cui devo spostare la nave sono libere
        std::vector<Nave *> navi = difensore.get_navi();                                                                   // recupero un vettore con tutte le mie navi per poi poter confrontare tutte le coordinate
        if(is_orizzontale){                                                                                                // divido in due il controllo: se è orrizzontale oppure verticale
            for (int i = 0; i < navi.size(); ++i) {                                                                        // passo tutte le navi all interno dell array navi
                std::vector<Tupla> aux = navi[i].get_corazza();                                                            // prendo le coordinate della nave che sto prendendo in cosiderazione all`interno dell`array navi ,attraverso la funzione get_corazza e le salvo nell`array aux
                for (int j = 0; j < aux.size(); ++j) {                                                                     // passo tutte le coordinate della nave che ho preso in considerazione
                    if(aux[j].get_y324() == target.get_y()){                                                                  // come prima cose se è orizzontale vado a verificare che la coordinata presa in considerazione abbia la stessa y della coordinata target, se non ce l`ha non effettuo i controlli sulla coordinata x (essendo orizzontale tutte le coordinate hannno la stessa y)
                        if(aux[j].get_x() == target.get_x()+1  ||  aux[j].get_x() == target.get_x()-1 ){                   // vado a verificare se le cooridinate a destra e a sinistra (essendo orizzontale) a quella della coordinata x della coordinata presa in considerazione della nave
                            libero = false;                                                                                // se il match avviene, non posso spostare la nave e quindi libero = false
                        }
                    }
                }
            }
        }
        else{                                                                                                              // se la nave è verticale l`unica cosa che vado a cambiare è il controllo che effettuo sulla coordinata presa in considerazione
            for (int i = 0; i < navi.size(); ++i) {
                std::vector<Tupla> aux = navi[i].get_corazza();
                for (int j = 0; j < aux.size(); ++j) {
                    if(aux[j].get_x() == target.get_x()){                                                                  // verifico la coordinata x (essendo veritcale non cambia)
                        if(aux[j].get_y() == target.get_y()+1  ||  aux[j].get_y() == target.get_y()-1 ){                   //vado a verificare le coordinate sopra e sotto (essendo verticale)
                            libero = false;
                        }
                    }
                }
            }
        }

        if(libero)
        {
            aggiorna_griglia();                                                                                            // ho ipotizzato un metodo che è da definire
            return true;                                                                                                   // la nave si è potuta spostare
        }
        return false;                                                                                                      // la nave non si è potuta spostare
    }
}*/