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

void Supporto::muovi(battaglia_navale::Coordinate &origin, battaglia_navale::Coordinate &target, Giocatore &difensore){
        bool libero = true;                                                                                                // serve per sapere se nelle coordinate in cui devo spostare la nave sono libere
        std::vector<Nave *> navi = difensore.get_navi();                                                                   // recupero un vettore con tutte le mie navi per poi poter confrontare tutte le coordinate
        if(orizzontale_){                                                                                                // divido in due il controllo: se è orrizzontale oppure verticale
            for (int i = 0; i < navi.size(); ++i) {                                                                        // passo tutte le navi all interno dell array navi
                std::vector<Tupla> aux = navi[i]->get_corazza();                                                            // prendo le coordinate della nave che sto prendendo in cosiderazione all`interno dell`array navi ,attraverso la funzione get_corazza e le salvo nell`array aux
                for (int j = 0; j < aux.size(); ++j) {                                                                     // passo tutte le coordinate della nave che ho preso in considerazione
                    if(aux[j].coord.get_y() == target.get_y()){                                                                  // come prima cose se è orizzontale vado a verificare che la coordinata presa in considerazione abbia la stessa y della coordinata target, se non ce l`ha non effettuo i controlli sulla coordinata x (essendo orizzontale tutte le coordinate hannno la stessa y)
                        if(aux[j].coord.get_x() == target.get_x()+1  ||  aux[j].coord.get_x() == target.get_x()-1 ){                   // vado a verificare se le cooridinate a destra e a sinistra (essendo orizzontale) a quella della coordinata x della coordinata presa in considerazione della nave
                            libero = false;                                                                                // se il match avviene, non posso spostare la nave e quindi libero = false
                        }
                    }
                }
            }
        }
        else{                                                                                                              // se la nave è verticale l`unica cosa che vado a cambiare è il controllo che effettuo sulla coordinata presa in considerazione
            for (int i = 0; i < navi.size(); ++i) {
                std::vector<Tupla> aux = navi[i]->get_corazza();
                for (int j = 0; j < aux.size(); ++j) {
                    if(aux[j].coord.get_x() == target.get_x()){                                                                  // verifico la coordinata x (essendo veritcale non cambia)
                        if(aux[j].coord.get_y() == target.get_y()+1  ||  aux[j].coord.get_y() == target.get_y()-1 ){                   //vado a verificare le coordinate sopra e sotto (essendo verticale)
                            libero = false;
                        }
                    }
                }
            }
        }

        if(libero)
        {
            sposta();                                                                                            // ho ipotizzato un metodo che è da definire// la nave si è potuta spostare
        }
        else{
            //todo lanciare eccezione
        }
                                                                                                              // la nave non si è potuta spostar
}

void Supporto::modifica_range(battaglia_navale::Coordinate target,battaglia_navale::Coordinate &start_heal, battaglia_navale::Coordinate &finish_heal)  //todo rifare il metodo con le variabili giuste e dare un nome sensato
//todo verificare se il metodo è giusto anche sul lato logico
{
    if(is_orizzontale())
    {
        if(target.get_y()==12)
        {
            //finish_heal.get_y() -=1;
            start_heal.set_y(target.get_y()-1);
            start_heal.set_x(target.get_x()-1);
            finish_heal.set_y(target.get_y()-1);
            finish_heal.set_x(target.get_x()+1);

        }
        else if(target.get_y() == 1){
            //start_heal.get_y() +=1;
            start_heal.set_y(target.get_y()+1);
            start_heal.set_x(target.get_x()-1);
            finish_heal.set_y(target.get_y()+1);
            finish_heal.set_x(target.get_x()+1);
        }
    }
    else{
        if(target.get_x() == 1)
        {
            //start_heal.get_x() +=1;
            start_heal.set_x(target.get_x()+1);
            start_heal.set_y(target.get_y()-1);
            finish_heal.set_y(target.get_y()+1);
            finish_heal.set_x(target.get_x()+1);
        }
        else if(target.get_x() ==12)
        {
            //finish_heal.get_x() -=1;
            start_heal.set_x(target.get_x()-1);
            start_heal.set_y(target.get_y()-1);
            finish_heal.set_y(target.get_y()+1);
            finish_heal.set_x(target.get_x()-1);
        }
    }
}

void Supporto::azione(Giocatore difensore, battaglia_navale::Coordinate &target){

    battaglia_navale::Coordinate start_heal(target.get_x()-1,(char)(target.get_y()-1+65));
    battaglia_navale::Coordinate finish_heal(target.get_x()+1,(char)(target.get_y()+1+65));

    modifica_range(target,start_heal,finish_heal);

    std::vector<Nave *> navi = difensore.get_navi(); //recupero le navi dell'avversario

    if(is_orizzontale()){
        for (int i = 0; i < navi.size(); ++i) {
            std::vector<Tupla> aux = navi[i]->get_corazza();
            for (int j = 0; j < navi[i]->get_dimensione(); ++j) {
                if(battaglia_navale::Coordinate{aux[j].coord.get_x(),aux[j].coord.get_y()} >= start_heal && battaglia_navale::Coordinate{aux[j].coord.get_x(),aux[j].coord.get_y()} <= finish_heal )
                    if(aux[j].coord.get_y() != this. )                                //todo verificare che la coordinata che sto verificando non sia della nave supporto che sta attualmente compiendo l`azione
            }
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