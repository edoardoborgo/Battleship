#include <iostream>
#include "../include/gioco.h"
#include "../include/corazzata.h"
#include "../include/supporto.h"
#include "../include/sottomarino.h"
#include <fstream>

using namespace std;

vector<string> split(string mossa);

void set_coordinate(const string& input, string &origin, string &target);

int mainf(int argc, char **argv) {
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
        for (int s = 0; s < numero_supporto; s++) {
            G2.crea_nave(dimensione_supporto);
        }
        for (int e = 0; e < numero_sottomarino; e++) {
            G2.crea_nave(dimensione_sottomarino);
        }
        //creazione casuale delle navi di Computer2
        for (int c = 0; c < numero_navi[0]; c++) {
            G1.crea_nave(dimensione_navi[0]);
        }
        for (int s = 0; s < numero_supporto; s++) {
            G1.crea_nave(dimensione_supporto);
        }
        for (int e = 0; e < numero_sottomarino; e++) {
            G1.crea_nave(dimensione_sottomarino);
        }

        while (!game.is_game_over()) {

            if (game.is_turno_g1()) {
                input = G1.choose_move();
                set_coordinate(input, origin, target);
                game.azione(origin, target);
            } else {
                input = G2.choose_move();
                set_coordinate(input, origin, target);
                game.azione(origin, target);
            }
        }
        cout << "Il gioco è finito";
    } else {
        //non bot game
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
                        cout<< "eccezione" << endl;
                    }
                } while (flag);
            }
        }
        //flag = true;
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
                        cout<< "Turno pc, effettuato"<<endl;
                        input = G2.choose_move();
                        set_coordinate(input, origin, target);
                        game.azione(origin, target);
                        flag = false;
                    }
                } catch (invalid_argument &e) {
                    flag = true;
                    cout<< *e.what() << endl;
                    cout << "eccezione"<<endl;
                }
            }while(flag);
        }
        std::cout << "worka";
    }
    return 0;
}



/*while(true){
        if(game->is_turno_g1()){
                cout<<"è il turno del giocatore 1, fare la mossa";
                cin>>input;
                set_coordinate(input,origin,target);
        }
        else{
            g2.
        }
    }
} catch (std::exception e) {

}*/


/*
void Game::play()
    {
        if(!is_bot_game) std::cout << "Use the command XX XX to print a snapshot of the chessboard." << std::endl;
        this->log_file.open("./game_log.txt"); // opens the log file
        do
        {
            chessgame::PieceColor color = this->getCurrentPlayer()->getColor();
            std::cout << "\nTurn n.: " << this->n_moves + 1 << (color == chessgame::WHITE ? " - WHITE" : " - BLACK") << " moves." << std::endl;
            bool invalid_move = true;
            do
            {
                // player's move for its turn
                std::array<chessgame::Coordinates, 2> move = this->getCurrentPlayer()->think();
                if(move[0].symbol == "XX" && move[1].symbol == "XX") { // special command as by instructions
                    std::cout << this->board.snapshot() << std::endl;
                    continue;
                }
                invalid_move = !this->playerMove(move);
                if(!invalid_move) {
                    chessgame::Piece* p = this->board.get_piece(move[1]);
                    if(p != nullptr) {
                        std::cout << "-> Moved: " << p->getSymbol() << " from " << move[0].symbol << " to " << move[1].symbol << std::endl;
                    }
                    else std::cout << "ATTENTION: moved from a void tile!" << std::endl; // for debugging purpose
                }
            } while (invalid_move); // this cycle keeps going until a valid move has been entered

            // resets seed generator if bot player
            if(!this->getCurrentPlayer()->is_human)
                dynamic_cast<chessgame::Bot*>(this->getCurrentPlayer())->resetBotSeed();

            this->n_moves++;
            this->stall_counter++;

            std::cout << "********************** End of turn **********************" << std::endl;

            this->current_turn = !this->current_turn; // alternates turns
        } while (!isGameOver());
        // snapshot of the state of the chessboard at the end of the game
        std::cout << this->board.snapshot() << std::endl;
        this->log_file.close(); // closes the log file
    }


*/

/*Giocatore* G1;
    if(scelta_bot_game){
        Computer appo_computer = Computer();
        G1 = &appo_computer;
    }else{
        Giocatore appo_giocatore = Giocatore();
        G1 = &appo_giocatore;
    }*/

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

void set_coordinate(const string& input, string &origin, string &target) {
    vector<string> coordinate = split(input);
    origin = coordinate[0];
    target = coordinate[1];
}