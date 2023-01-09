#include "../include/corazzata.h"

Corazzata::Corazzata(battaglia_navale::Coordinate &prua, battaglia_navale::Coordinate &poppa){
    dimensione_=5;
    simbolo_='C';
    if(Nave::is_nave(prua, poppa, dimensione_)){
        battaglia_navale::Coordinate appo_coord;
        Nave::Tupla appo_tupla;
        for(int i=0; i<dimensione_; i++){
            if(i==0 || i==4){
                corazza_.push_back(appo_tupla);
            }else{
                if(is_orizzontale_){
                    if(prua.get_x()<poppa.get_x()){
                        appo_coord.set_x(prua.get_x()+i);
                        appo_coord.set_y(prua.get_y());
                    }else{
                        appo_coord.set_x(poppa.get_x()+i);
                        appo_coord.set_y(poppa.get_y());
                    }
                }else{
                    if(prua.get_y()<poppa.get_y()){
                        appo_coord.set_x(prua.get_x());
                        appo_coord.set_y(prua.get_y()+i);
                    }else{
                        appo_coord.set_x(poppa.get_x());
                        appo_coord.set_y(poppa.get_y()+i);
                    }
                }
                Nave::Tupla appo_tupla{appo_coord, simbolo_};
                corazza_.push_back(appo_tupla);
            }
        }
        Corazzata::coordinata_centro_=Nave::calcolo_centro(prua, poppa);

    }
}


void Corazzata::set_corazza(battaglia_navale::Coordinate &coord) {
    for(int i=0; i<corazza_.size(); i++){
        if(corazza_[i].c==coord)
            if(corazza_[i].stato=='C')
                corazza_[i].stato='c';
    }
}