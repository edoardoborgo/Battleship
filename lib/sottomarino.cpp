#include "../include/sottomarino.h"
#include <vector>

Sottomarino::Sottomarino(battaglia_navale::Coordinate &prua){
    Sottomarino::dimensione_ = 1;
    corazza_.push_back(Nave::Tupla{prua, simbolo_});
}

void Sottomarino::azione(/*Giocatore::player difensore,*/ battaglia_navale::Coordinate &target){
    Sottomarino::muovi(Nave::calcolo_centro(corazza_[0].coord, corazza_[0].coord), target);
}


std::vector<std::vector<char>> Sottomarino::scan_(/*Giocatore::player difensore,*/ battaglia_navale::Coordinate &target){
    std::vector<std::vector<char>> scan_(5, std::vector<char>(5));
    if(muovi(coordinata_centro_, target)){
        battaglia_navale::Coordinate start_scan_(target.get_x()-2, target.get_y()-2);
        int row = 0, col = 0;
        for(int i = start_scan_.get_x(); i < scan_.size(); i++){
            for(int j = start_scan_.get_y(); j < scan_.size(); j++){
                if(difensore.griglia_difesa.x != ' '){         // griglia difesa
                    scan_[col][row] = 'Y';
                } else {
                    scan_[col][row] = ' ';
                }
                col++;
            }
            row++;
        }
    }
}

bool Sottomarino::muovi(battaglia_navale::Coordinate &origin,battaglia_navale::Coordinate &target){
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

void Sottomarino::set_corazza(battaglia_navale:: Coordinate &coord){
    for(int i=0; i<corazza_.size(); i++){
        if(corazza_[i].c==coord){
            if(corazza_[i].stato='E'){
                corazza_[i].stato='e';
            }
        }
    }
}