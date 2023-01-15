#include "../include/gioco.h"
#include <cstdlib>
#include <ctime>

void Gioco::start_casuale() {
    srand(time(0));
    int numero_casuale = rand();
    if (numero_casuale % 2 == 0)
        turno_g1_ = true;
    else
        turno_g1_ = false;
}

void Gioco::prossimo_turno() {
    turno_g1_ = !turno_g1_;
}

Gioco::Gioco(bool scelta_bot_game, Giocatore *G1, Giocatore *G2) {
    //controllo della versione, non servono eccezioni per la versione passata perchè viene controllata nel main
    if (scelta_bot_game)
        bot_game_ = true;
    else if (!scelta_bot_game)
        bot_game_ = false;

    //inizializzazione turno
    start_casuale();

    //inizializzazione giocatori
    G1_ = G1;
    G2_ = G2;
}

void Gioco::azione(std::string origin, std::string target) {
    //controllo il turno e imposto la ref al giocatore attivo
    Giocatore *giocatore_attaccante;
    Giocatore *giocatore_difensore;
    if (turno_g1_) {
        giocatore_attaccante = G1_;
        giocatore_difensore = G2_;
    } else {
        giocatore_attaccante = G2_;
        giocatore_difensore = G1_;
    }

    //controlli sui parametri: qua o sul main?
    if (origin.length() != 2 && target.length() != 2) {
        //lancio una eccezione, nel main viene chiesto di reinserire origin e target
    } else {
        //controllo mosse speciali altriementi invoco la funzione azione di origin chiamata da giocatore attivo
        if (origin == "AA" && target == "AA") {
            //cancella gli avvistamenti sonar, cioè le Y
            giocatore_attaccante->cancella_avvistamenti();
        } else if (origin == "XX" && target == "XX") {
            print_griglie(giocatore_attaccante);
            prossimo_turno();
        } else {
            //azione di nave origin
            //controllo sui parametri
            check(origin);
            check(target);
            //controllo che in origin di giocatore attaccante ci sia una nave
            std::vector<Nave *> navi = giocatore_attaccante->get_navi();
            bool trovato = false;
            Nave *nave_scelta;
            for (int i = 0; i < navi.size() && !trovato; i++) {
                std::string num;
                for(int j=0; j<origin.length(); j++)
                    num.push_back(origin[j]);
                if (navi[i]->get_coordinata_centro() == battaglia_navale::Coordinate(stoi(num), origin[0])) {
                    nave_scelta = navi[i];
                    trovato = true;
                }
            }
            if (!trovato) {
                //non ci sono navi in origin
                //TODO eccezione, nave non trovata, nel main viene chiesto di reinserire origin e target
                throw std::invalid_argument("")
            } else {
                //nave origin trovata
                std::string num; num.push_back(origin[1]);num.push_back(origin[2]);
                battaglia_navale::Coordinate coord(target[0], stoi(num));
                if (nave_scelta->azione(giocatore_difensore, coord)) {
                    //colpita, stampo X in griglia attacco
                    giocatore_attaccante->set_risultato(coord, 'X');
                } else {
                    //non coplita, stampo O in griglia attacco
                    giocatore_attaccante->set_risultato(coord, 'O');
                }
                prossimo_turno();
            }
        }
    }
}

void Gioco::print_griglie(Giocatore *G) {
    //recupero griglia attacco
    std::vector<std::vector<char>> griglia_attacco = G->get_griglia_attacco();
    //recupero griglia difesa
    std::vector<std::vector<char>> griglia_difesa = G->get_griglia_difesa();

    char row = 65;
    for (int righe = 0; righe < 12; righe++) { //12 righe
        if (righe == 0) {
            std::cout << "  --------------------------------------------------";
            std::cout << "   ";
            std::cout << "  --------------------------------------------------" << std::endl;

            std::cout << row << ' ' << '|';
            for (int colonne = 0; colonne < 12; colonne++) {
                std::cout << " " << griglia_attacco[righe][colonne] << " " << '|';
            }
            std::cout << "   ";
            std::cout << row << ' ' << '|';
            for (int colonne = 0; colonne < 12; colonne++) {
                std::cout << " " << griglia_difesa[righe][colonne] << " " << '|';
            }
            std::cout << std::endl;
        } else if (righe == 11) {
            std::cout << row << ' ' << '|';
            for (int colonne = 0; colonne < 12; colonne++) {
                std::cout << " " << griglia_attacco[righe][colonne] << " " << '|';
            }
            std::cout << "   ";
            std::cout << row << ' ' << '|';
            for (int colonne = 0; colonne < 12; colonne++) {
                std::cout << " " << griglia_difesa[righe][colonne] << " " << '|';
            }
            std::cout << std::endl;

            std::cout << "  --------------------------------------------------";
            std::cout << "   ";
            std::cout << "  --------------------------------------------------" << std::endl;
            std::cout << "    1   2   3   4   5   6   7   8   9  10   11  12  ";
            std::cout << "   ";
            std::cout << "    1   2   3   4   5   6   7   8   9  10   11  12  " << std::endl;
        } else {
            std::cout << row << ' ' << '|';
            for (int colonne = 0; colonne < 12; colonne++) {
                std::cout << " " << griglia_attacco[righe][colonne] << " " << '|';
            }
            std::cout << "   ";
            std::cout << row << ' ' << '|';
            for (int colonne = 0; colonne < 12; colonne++) {
                std::cout << " " << griglia_difesa[righe][colonne] << " " << '|';
            }
            std::cout << std::endl;
        }
        row++;
    }
}

bool Gioco::is_turno_g1() {
    return turno_g1_;
}

void Gioco::check(std::string parametro) {
    for(int i=0; i<parametro.length(); i++){
        if(i==0){
            if (!(parametro[0] >= 65 && parametro[0] <= 90)){
                //TODO eccezione da gestire nel main
            }
        }else{
            if (!(parametro[0] >= 48 && parametro[0] <= 57)){
                //TODO eccezione da gestire nel main
            }
        }
    }
    std::string num; num.push_back(parametro[1]);
}

