
main{
    Game.azione(origin, target);
};

Game{
    ref G1, ref G2
    griglia attacco g1, griglia attacco g2;

    azione(origin, target){
        //turno g1
        if(origin=="MOSSA SPECIALE" && target=="MOSSA SPECIALE"){
            MOSSA SPECIALE 1:
            MOSSA SPECIALE 2:
            ecc...
        }
        lista navi=G1.get_navi;
        //controllo che tra le navi ce ne sia una con coordinata centro == coordinata origin, salvo la posizione in i, variabile usata per il ciclo
        if(lista_navi[i].azione(G2, target)){
            //target preso
            G1.set_risultato('X', target);
                //oppure
            griglia attacco G1[target.get_x(), target.get_y()]='X';
        }else{
            //target non preso
            griglia attacco G1[target.get_x(), target.get_y()]='O';
        }
        cambio_turno(); //switcha il player attivo
    }
};


/*
giocatori

        azione dal main(origin e target){
turno g2
ref giocatore = ALTRO
VICEVERSA

        navi attaccante[posizione origin].azione nave(ref giocatore altro, target)
}*/