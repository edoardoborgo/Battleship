#include "../include/gioco.h"

Gioco::Gioco(std::string &versione){
    //controllo della versione
    if(versione=="cc")
        bot_game=false;
    else if(versione=="pc")
        bot_game=true;
    else{
        //eccezione, la versione passata come parametro non appartiene alle due scelte possibili CC/PC
    }
    //inizializzazione turno
    turno_g1=true; //TODO randomizzare il turno di inizio
}