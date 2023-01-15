#include "../include/supporto.h"
#include "../include/giocatore.h"
#include <stdexcept>

Supporto::Supporto(battaglia_navale::Coordinate &prua, battaglia_navale::Coordinate &poppa) {
    dimensione_ = 3;
    simbolo_ = 'S';
    if (Nave::is_nave(prua, poppa, dimensione_)) {
        corazza_.push_back(Nave::Tupla{prua, 'S'});
        corazza_.push_back(Nave::Tupla{Nave::calcolo_centro(prua, poppa), 'S'});
        corazza_.push_back(Nave::Tupla{poppa, 'S'});

    }
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
    Nave appo_nave = *nave_origin;
    if (is_posizionabile(appo_nave, attaccante)) {
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

























/*bool Supporto::azione(Giocatore difensore,battaglia_navale::Coordinate &target){
    battaglia_navale::Coordinate start_heal(target.get_x()-1,target.get_y()-1);
    battaglia_navale::Coordinate finish_heal(target.get_x()+1,target.get_y()+1);

    Supporto::modifica_range(coord_limite,&start_heal,&finish_heal);  // cambio le coordinate in base alla posizione della nave
    char tabella[12][12] = difensore.get_tabellone();          // mi salvo la tabella mia per avercela comoda

    if(muovi(coordinatacentro,target)){  // se la nave puo spostarsi, faccio l azione
        for (int i = start_heal.get_y(); i < finish_heal.get_y() ; ++i) {
            for (int j = start_heal.get_x(); j < finish_heal.get_x(); ++j) {
                if()                                                      // todo devo verificare che nn si autocuri
                if(tabella[j,i] >96)
                {
                    difensore.set_risultato(battaglia_navale::Coordinate{j,i},tabella[j,i]-=32)
                }
            }
        }
        return true;
    }
    else{
        return false;
    }
}*/

/*bool Supporto::azione(Giocatore difensore, battaglia_navale::Coordinate &target) {
   battaglia_navale::Coordinate start_heal(target.get_x()-1,target.get_y()-1);
   battaglia_navale::Coordinate finish_heal(target.get_x()+1,target.get_y()+1);

   if(start_heal <= battaglia_navale::Coordinate{0,0})
   std::vector<Nave *> navi = difensore.get_navi(); //recupero le navi dell'avversario
   if(muovi(coordinata_centro_,target)){
       for (int i = 0; i < navi.size(); ++i) {
           std::vector<Nave::Tupla> corazza = navi[i]->get_corazza();
           for (int j = 0; j < navi[i]->dimensione_; ++j) {
               if(navi[i]->get_corazza()[j].coord >= start_heal && navi[i]->get_corazza()[j].coord<= finish_heal)
               if(!(corazza_[j].stato>=65 && corazza_[j].stato<=90)){ //se non è maiuscolo
                   corazza_[j].stato=(char)(corazza_[j].stato-=32); //non può funzionare perchè non mi pare un setter
               }
           }
       }
   }
}*/

/*bool Supporto::muovi(battaglia_navale::Coordinate &origin, battaglia_navale::Coordinate &target) {
  try {
    if (griglia_difesa[target.get_x(), target.get_y()] == "") {
      if (is_orizzontale_) {
        if (griglia_difesa[target.get_x() - 1][target.get_y()] == " "&& griglia_difesa[target.get_x() + 1][target.get_y()] == " ") {
          aggiorna_griglia(origin, target);
          return true;
        }
      } else {
        if (griglia_difesa[target.get_x()][target.get_y() - 1] == " "
            && griglia_difesa[target.get_x()][target.get_y() + 1] == " ") {
          aggiorna_griglia(origin, target);
          return true;
        }
      }
    }
  } catch (std::out_of_range e) {
    return false;
  }

}*/