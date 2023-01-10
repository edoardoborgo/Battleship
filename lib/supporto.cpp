#include "../include/supporto.h"
#include "../include/giocatore.h"
#include <stdexcept>


Supporto::Supporto(battaglia_navale::Coordinate &prua, battaglia_navale::Coordinate &poppa) {
    dimensione_ = 3;
    simbolo_ = 'S';
    if(Nave::is_nave(prua, poppa, dimensione_)){
        corazza_.push_back(Nave::Tupla{prua, 'S'});
        corazza_.push_back(Nave::Tupla{Nave::calcolo_centro(prua, poppa), 'S'});
        corazza_.push_back(Nave::Tupla{poppa, 'S'});

    }
}

void Supporto::set_corazza(battaglia_navale:: Coordinate &coord){
    for(int i=0; i<corazza_.size(); i++){
        if(corazza_[i].coord==coord){
            if(corazza_[i].stato=='S'){
                corazza_[i].stato='s';
            }
        }
    }
}

bool Supporto::azione(Giocatore difensore,battaglia_navale::Coordinate &target){
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

***
*s*
***
bool Supporto::muovi(battaglia_navale::Coordinate &origin,battaglia_navale::Coordinate &target){
    try{
        if(griglia_difesa[target.get_x(),target.get_y()] == ""){
            if(is_orizzontale_){
                if(griglia_difesa[target.get_x()-1][target.get_y()] == " " && griglia_difesa[target.get_x()+1][target.get_y()] == " "){
                    aggiorna_griglia(origin,target);
                    return true;
                }
            }
            else{
                if(griglia_difesa[target.get_x()][target.get_y()-1] == " " && griglia_difesa[target.get_x()][target.get_y()+1] == " "){
                    aggiorna_griglia(origin,target);
                    return true;
                }
            }
        }
    } catch (std::out_of_range e) {
        return false;
    }

}


