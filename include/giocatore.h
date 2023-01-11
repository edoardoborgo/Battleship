#include "griglia.h"
#include "nave.h"
#include <vector>

#ifndef BATTLESHIP_GIOCATORE_H
#define BATTLESHIP_GIOCATORE_H

class Giocatore {
private:
    battaglia_navale::Griglia griglia_attacco;
    std::vector<Nave *> navi;
    bool posiziona(Nave &nave){
        //controllo se ci sta nella posizione scelta
        for(int i=0; i<navi.size(); i++){

        }
    }
public:
    Giocatore();

    void add_nave(Nave nave){ //TODO initializer list
        //so gia che è una nave perchè viene controllato nel costruttore, eventuali errori vengono gestiti nel main con un try catch
        //controllo che non si sovrapponga ad altre navi o che esca dalla griglia, usando la funzione bool posiziona che mi dice se il posizionamento è andato o no a buon fine, if true aggiungo nave a navi

        //se è tutto ook la inserisco nel vettore navi, altrimenti abbandono tutto e la nave deve essere ricreata dal main
    }

    //funzione che modifica la griglia di attacco
    //oppure fare un metodo get griglia e tramite reference alla griglia chiamare set_risultato, evitando questa funzione
    void set_risultato(battaglia_navale::Coordinate coord, char stato) {
        griglia_attacco.set_risultato(coord, stato);
    }

    std::vector<Nave *> get_navi() {
        return navi;
    }
};

#endif //BATTLESHIP_GIOCATORE_H
