#include <iostream>
#include "../include/gioco.h"
#include "../include/corazzata.h"
#include "../include/supporto.h"
#include "../include/sottomarino.h"
#include <fstream>
#include <string>
#include <thread>

using namespace std;

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

void set_coordinate(const string& input, string &origin, string &target){
    vector<string> coordinate = split(input);
    origin = coordinate[0];
    target = coordinate[1];
}


int main(int argc, char *argv[]) {

    if (argc != 4 && argc != 3) {
        std::cout << "-- E' necessario indicare v [log input] o v [log input] [log output] --";
        return 1;
    }
    Giocatore G1 = Giocatore();
    Giocatore G2 = Giocatore();
    std::vector<std::string> args {argv,argv+argc};
    std::string versione = args[1];
    std::string log_input = args[2];
    std::string log_output;
    if(argc == 4)
        log_output = args[3];

    if (!(versione == "v" || versione == "f")) {
        std::cout << "Invalid Argument. Per favore inserisci 'v' o 'f'" << endl;
        return 1;
    }
    bool turno_g1;
    //leggo il file e lo inserisco in un vector
    std::vector <string> lista_mosse;
    ifstream fin(argv[2]);
    std::string linea;
    //lettura giocatore iniziale
    std::getline(fin,linea);
    if(linea=="G1")
        turno_g1 = true;
    else
        turno_g1 = false;

    while(!fin.eof()){

        std::getline(fin,linea);
        if(!linea.empty())
            lista_mosse.push_back(linea);
    }
    fin.close();

    std::string input;
    std::string origin, target, prua, poppa;
    battaglia_navale::Coordinate x{}, y{};

    //numero navi in posizione: [0] = numero corazzate, [1] = numero supporto, [2] = numero sottomarini
    std::vector<int> numero_navi{3, 3, 2};
    //dimensione delle navi: [0] = dimensione corazzata, [1] = dimensione supporto, [2] = dimensione sottomarino
    std::vector<int> dimensione_navi{5, 3, 1};

    //"player" vs "player"
    bool flag = false;
    Gioco game = args[1]=="v" ? Gioco(turno_g1, &G2, &G1) : Gioco(turno_g1, &G2, &G1, argv[3]);

    if(args[1]=="f"){
        //salvo il giocatore iniziale
        std::string filename(args[3]);
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
    }

    int mossa_corrente=0;
    int tipi_di_navi = 3;
    for(int i=0; i<tipi_di_navi; i++){
        for (int j = 0; j < numero_navi[i];) {
            do {
                try {
                    std::string input_da_file = lista_mosse[mossa_corrente];
                    cout<<mossa_corrente;
                    set_coordinate(input_da_file, prua, poppa);
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
                    mossa_corrente++;
                    flag = false;
                } catch (invalid_argument& e) {
                    flag = true;
                    cout<< "eccezione" << endl;
                }
            } while (flag);
        }
    }
    //inserimento navi G2
    for(int i=0; i<tipi_di_navi; i++){
        for (int j = 0; j < numero_navi[i];) {
            do {
                try {
                    std::string input_da_file = lista_mosse[mossa_corrente];
                    set_coordinate(input_da_file, prua, poppa);
                    x = battaglia_navale::Coordinate(prua);
                    y = battaglia_navale::Coordinate(poppa);
                    if(i==0){
                        //corazzata
                        auto *c = new Corazzata(x, y);
                        G2.add_nave(c);
                    }else if(i==1){
                        //supporto
                        auto *s = new Supporto(x, y);
                        G2.add_nave(s);
                    }else{
                        //explorer
                        auto *e = new Sottomarino(x);
                        G2.add_nave(e);
                    }
                    j++;
                    mossa_corrente++;
                    flag = false;
                } catch (invalid_argument& e) {
                    flag = true;
                    cout<< "eccezione" << endl;
                }
            } while (flag);
        }
    }

    while (!game.is_game_over() && mossa_corrente<lista_mosse.size()-1) {
           std::this_thread::sleep_for(std::chrono::seconds(1));
        do{
            try{
                if (game.is_turno_g1()) {
                    input = lista_mosse[mossa_corrente];
                    set_coordinate(input, origin, target);
                    game.azione("XX", "XX");
                    game.azione(origin, target);
                    flag = false;
                    mossa_corrente++;
                } else {
                    input = lista_mosse[mossa_corrente];
                    set_coordinate(input, origin, target);
                    game.azione("XX", "XX");
                    game.azione(origin, target);
                    flag = false;
                    mossa_corrente++;
                }
            } catch (invalid_argument &e) {
                flag = true;
                cout<< *e.what() << endl;
                cout << "file di log non valido"<<endl;
                return 1; //file di log non valido
           }
        }while(flag);
    }
    std::cout << "Fine Gioco.";
    return 0;
}