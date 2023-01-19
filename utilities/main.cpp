//Mattia Rosa
#include <iostream>
#include "../include/gioco.h"
#include "../include/corazzata.h"
#include "../include/supporto.h"
#include "../include/sottomarino.h"
#include <fstream>

using namespace std;

vector<string> split(string mossa);

void set_coordinate(const string& input, string &origin, string &target);

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "-- E' necessario selezionare una versione: pc/cc --";
        return 0;
    }
    Computer G2 = Computer();

    /*------------------------------------------------------------------------------------------------
     * TIPOLOGIA DI GIOCO
     -------------------------------------------------------------------------------------------------*/
    char p1 = argv[1][0];
    char p2 = argv[1][1];
    bool scelta_bot_game = false;

    if (!(p1 == 'c' || p1 == 'p') || p2 != 'c') {
        std::cout << "Invalid Argument. Per favore inserisci 'pc' o 'cc'." << argc << endl;
        return 0;
    } else if (p1 == 'c') {
        scelta_bot_game = true;
    }

    string input;
    string origin, target, prua, poppa;
    battaglia_navale::Coordinate x{}, y{};

    //numero navi in posizione: [0] = numero corazzate, [1] = numero supporto, [2] = numero sottomarini
    std::vector<int> numero_navi{3, 3, 2};
    //dimensione delle navi: [0] = dimensione corazzata, [1] = dimensione supporto, [2] = dimensione sottomarino
    std::vector<int> dimensione_navi{5, 3, 1};

    /*------------------------------------------------------------------------------------------------
     * Gioco CC
     ------------------------------------------------------------------------------------------------*/
    if (scelta_bot_game) {
        Computer G1 = Computer();
        Gioco game = Gioco(scelta_bot_game, &G1, &G2);

        std::string filename("../log.txt");
        std::fstream fout;
        fout.open(filename, std::ofstream::out | std::ofstream::trunc);
        fout.close();
        fout.open(filename);
        if (fout.good()) {
            if(game.is_turno_g1())
                fout<<"G1";
            else
                fout<<"G2";
            fout << "\n";
            fout.close();
        }

        //creazione casuale delle navi di Computer1
        for (int c = 0; c < numero_navi[0]; c++) {
            G2.crea_nave(dimensione_navi[0]);
        }
        for (int s = 0; s < numero_navi[1]; s++) {
            G2.crea_nave(dimensione_navi[1]);
        }
        for (int e = 0; e < numero_navi[2]; e++) {
            G2.crea_nave(dimensione_navi[2]);
        }
        //creazione casuale delle navi di Computer2
        for (int c = 0; c < numero_navi[0]; c++) {
            G1.crea_nave(dimensione_navi[0]);
        }
        for (int s = 0; s < numero_navi[1]; s++) {
            G1.crea_nave(dimensione_navi[1]);
        }
        for (int e = 0; e < numero_navi[2]; e++) {
            G1.crea_nave(dimensione_navi[2]);
        }

        while (!game.is_game_over()) {
            bool flag = false;
            do{
                try{
                    if (game.is_turno_g1()) {
                        input = G1.choose_move();
                        set_coordinate(input, origin, target);
                        game.azione(origin, target);
                        flag = false;
                        //game.azione("XX","XX");
                        //cout<<endl<<"Computer 1"<<endl;
                    } else {
                        input = G2.choose_move();
                        set_coordinate(input, origin, target);
                        game.azione(origin, target);
                        flag = false;
                        //game.azione("XX","XX");
                        //cout<<endl<<"Computer 2"<<endl;
                    }
                } catch (invalid_argument& e) {
                    //nel caso in cui vengano sollevate eccezioni viene rieffettuato il turno
                    flag = true;
                }
            }while(flag);
        }
        cout << "Il gioco è finito";
    /*------------------------------------------------------------------------------------------------
    * Gioco PC
    ------------------------------------------------------------------------------------------------*/
    } else {
        bool flag = false;
        Giocatore G1 = Giocatore();
        Gioco game = Gioco(scelta_bot_game, &G1, &G2);

        std::string filename("../log.txt");
        std::fstream fout;
        fout.open(filename, std::ofstream::out | std::ofstream::trunc);
        fout.close();
        fout.open(filename);
        if (fout.good()) {
            if(game.is_turno_g1())
                fout<<"G1";
            else
                fout<<"G2";
            fout << "\n";
            fout.close();
        }

        //creazione casuale delle navi di Computer2
        for (int c = 0; c < numero_navi[0]; c++) {
            G2.crea_nave(dimensione_navi[0]);
        }
        for (int s = 0; s < numero_navi[1]; s++) {
            G2.crea_nave(dimensione_navi[1]);
        }
        for (int e = 0; e < numero_navi[2]; e++) {
            G2.crea_nave(dimensione_navi[2]);
        }


        int tipi_di_navi = 3;
        //inserimento navi giocatore
        for(int i=0; i<tipi_di_navi; i++){
            for (int j = 0; j < numero_navi[i];) {
                do {
                    try {
                        cout << "Inserisci le coordinate di prua e poppa della nave n° " + to_string(j+1) + " (lunghezza "+to_string(dimensione_navi[i])+"): ";
                        getline(std::cin,input);
                        cout << "\n";
                        set_coordinate(input, prua, poppa);
                        x = battaglia_navale::Coordinate(prua);
                        y = battaglia_navale::Coordinate(poppa);
                        if(i==0){
                            //corazzata
                            auto *c = new Corazzata(x, y);
                            G1.add_nave(c);
                        }else if(i==1){
                            //supporto
                            auto *s = new Supporto(x, y);
                            G1.add_nave(s);
                        }else{
                            //explorer
                            auto *e = new Sottomarino(x);
                            G1.add_nave(e);
                        }
                        j++;
                        flag = false;
                    } catch (invalid_argument& e) {
                        flag = true;
                        //cout<< "eccezione" << endl;
                    }
                } while (flag);
            }
        }
        while (!game.is_game_over()) {
            do{
                try{
                    if (game.is_turno_g1()) {
                        cout<< "Inserisci centro origin e centro target, oppure AA/XX: ";
                        getline(std::cin,input);
                        cout<< "\n";
                        set_coordinate(input, origin, target);
                        game.azione(origin, target);
                        flag = false;
                    } else {
                        input = G2.choose_move();
                        set_coordinate(input, origin, target);
                        game.azione(origin, target);
                        flag = false;
                    }
                } catch (invalid_argument &e) {
                    //nel caso in cui vengano sollevate eccezioni viene rieffettuato il turno
                    flag = true;
                    //cout<< *e.what() << endl;
                    //cout << "eccezione"<<endl;
                }
            }while(flag);
        }
        //std::cout << "worka";
    }
    return 0;
}

vector<string> split(string mossa) {
    string aux;
    int ascii_space = 32;
    vector<string> coordinate;
    for (int j = 0; j <= mossa.length(); ++j) {
        if (mossa[j] != ascii_space && mossa[j] != '\0') {
            aux += mossa[j];
        } else {
            coordinate.push_back(aux);
            aux = "";
        }
    }
    return coordinate;
}

//divide le coordinate origin e target in due stringhe
void set_coordinate(const string& input, string &origin, string &target) {
    vector<string> coordinate = split(input);
    origin = coordinate[0];
    target = coordinate[1];
}