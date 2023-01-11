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

bool Supporto::azione(Giocatore difensore, battaglia_navale::Coordinate &target) {
  /* battaglia_navale::Coordinate start_heal(target.get_x()-1,target.get_y()-1);
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
   }*/
}

bool Supporto::muovi(battaglia_navale::Coordinate &origin, battaglia_navale::Coordinate &target) {
  try {
    if (griglia_difesa[target.get_x(), target.get_y()] == "") {
      if (is_orizzontale_) {
        if (griglia_difesa[target.get_x() - 1][target.get_y()] == " "
            && griglia_difesa[target.get_x() + 1][target.get_y()] == " ") {
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

}

/*
bool Supporto::azione(Giocatore difensore,battaglia_navale::Coordinate &target){
    battaglia_navale::Coordinate start_heal(target.get_x()-1,target.get_y()-1);
    battaglia_navale::Coordinate finish_heal(target.get_x()+1,target.get_y()+1);

    Supporto::modifica_range(coord_limite,&start_heal,&finish_heal);  // cambio le coordinate in base alla posizione della nave
    char tabella[12][12] = difensore.get_tabellone();          // mi salvo la tabella mia per avercela comoda

    if(muovi(coordinatacentro,target)){  // se la nave puo spostarsi, faccio l azione
        for (int i = start_heal.get_y(); i < finish_heal.get_y() ; ++i) {
            for (int j = start_heal.get_x(); j < finish_heal.get_x(); ++j) {
                if()                                                            // todo devo verificare che nn si autocuri
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
}
----------------------------------------------------------------
----------------------------------------------------------------
----------------------------------------------------------------

 * il metodo modifica le coordinate di finish e start heal se la nave si trova in una dei quattro lati della tabella


// il metodo verrebbe chiamato sempre e si entrerebbe sempre o nell if o nell esle perchè la nave sicuramente è o orizzontale o verticale, non so se ce un modo migliore per farlo

void Supporto::modifica_range(coord_limite,&start_heal,&finish_heal)  //todo rifare il metodo con le variabili giuste e dare un nome sensato
//todo verificare se il metodo è giusto anche sul lato logico
{
  if(is_orizzontale)
  {
    if(coord_limite.get_y()==12)
    {
      //finish_heal.get_y() -=1;
      finish_heal.set_y(finish_heal.get_y()-1);
    }
    else if(coord_limite.get_y() == 1){
      //start_heal.get_y() +=1;
      start_heal.set_y(start_heal.get_y()+1)
    }
  }
  else{
    if(coord_limite.get_x() == 1)
    {
      //start_heal.get_x() +=1;
      start_heal.set_x(start_heal.get_x()+1)
    }
    else if(coord_limite.get_x() ==12)
    {
      //finish_heal.get_x() -=1;
      finish_heal.set_x(finish_heal.get_x()-1)
    }
  }
}
*/

, , S -> prua | poppa (12, 1)  S S S
, , S ^                c c c
, , S |

a
b
c
b
d
e
f
  1 2 3 4 5 6 7