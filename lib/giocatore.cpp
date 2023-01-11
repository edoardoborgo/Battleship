#include "../include/giocatore.h"

bool Giocatore::is_posizionabile(Nave &nave) {
    bool flag = true;
    std::vector<Nave::Tupla> corazza_input = nave.get_corazza();
    for (int i = 0; i < corazza_input.size() && flag; i++) {
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

void Giocatore::add_nave(Nave nave) { //TODO initializer list
    //so già che mi viene passata una nave perchè le condizioni di nave vengono controllate nel costruttore
    //controllo che non si sovrapponga ad altre navi usando la funzione is_posizionabile che mi dice se il posizionamento è andato a buon fine o no
    if(navi.size()==5){
        //le navi sono già state tutte aggiunte
        if (is_posizionabile(nave)) {
            //posizionamento corretto, aggiungo la nave
            navi.push_back(&nave);
        } else {
            //posizionamento scorretto, lancio un'eccezione da gestire alla chiamata della funzione; la nave viene eliminata e cicreata nel main
            //TODO creare eccezione personalizzata
            throw std::invalid_argument("Aggiunta di nave non andata a buon fine.");
        }
    }
}

void Giocatore::set_risultato(battaglia_navale::Coordinate coord, char stato) {
    griglia_attacco.set_risultato(coord, stato);
}

std::vector<Nave *> Giocatore::get_navi() {
    return navi;
}