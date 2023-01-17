#include <iostream>
#include "../include/gioco.h"
#include "../include/corazzata.h"
#include "../include/supporto.h"
/*
using namespace std;

vector<string> split(string mossa){
    int i = 0;
    string aux;
    vector<string> coordinate;
    while(mossa[i] != '\n'){
        if(mossa[i] != 32){
            aux += mossa[i];
        } else {
            coordinate.push_back(aux);
            //aux = ""; (?)
        }
        i++;
    }
    return coordinate;
}

void set_coordinate(string input,string &origin,string &target)
{
    vector<string> coordinate = split(input);
    origin = coordinate[0];
    target = coordinate[1];
}

if(argc != 2) return 0;
    char p1 = argv[1][0];
    char p2 = argv[1][1];
    bool is_bot_game = false;
    if(!(p1 == 'p' || p1 == 'c') || p2 != 'c') {
        std::cout << "Invalid argument. Pleasy use 'pc' or 'cc'.";
        return 0;
    }
    else if(p1 == 'c') is_bot_game = true;
    gameplay::Game game {is_bot_game};
    game.play();
    return 0;
}
 */
int main(int argc, char** argv){
    Corazzata c1 =Corazzata();
    std::cout<<"dim:"<<c1.get_dimensione();
    std::cout<<"worka";

    /*Giocatore *G1;
    Computer C1 = Computer();
    G1 = &C1;*/

    /*
     ----------------------------------------------------------------------------------------------------------
     capisco che tipo di gioco è
     ----------------------------------------------------------------------------------------------------------
     */

    /*if(argc != 2){ return 0;}
    char p1 = argv[1][0];
    char p2 = argv[1][1];
    bool scelta_bot_game=false;

    if(!(p1 == 'c' || p1 == 'p') || p2 !='c') {
        std::cout << "Invalid Argument. Per favore inserisci 'pc' o 'cc'.";
        return 0;
    }
    else if(p1 == 'c') {
        scelta_bot_game = true;
    }

    Giocatore *G2;
    if(scelta_bot_game){
        Computer appo_computer = Computer();
        G2 = &appo_computer;
    }else{
        Giocatore appo_giocatore = Giocatore();
        G2 = &appo_giocatore;
    }
    Gioco(scelta_bot_game, G1, G2);

    while(true){

    }*/

    /*Corazzata c2(battaglia_navale::Coordinate(1,'A'), battaglia_navale::Coordinate(1,'A'));

    Corazzata c2 = Corazzata(x,y);
    Nave* ptr = &c1;

    ptr->get_francesco();

    if(argc != 2 ){
        return 0;
    }

    bool bot = false;
    Giocatore *g1;
    Giocatore *g2 = new Computer();
    string input;
    bool check = false;


     ----------------------------------------------------------------------------------------------------------
     inserimento delle navi
     ----------------------------------------------------------------------------------------------------------

    std::vector<Nave *> navi;
    string input;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 3; ++j) {
            string prua, poppa;
            cout << "inserisci le coordinate di prua e poppa della corazzata n " + j;
            cin >> input;
            set_coordinate(input, prua, poppa);
            battaglia_navale::Coordinate x = battaglia_navale::Coordinate(prua );
            battaglia_navale::Coordinate y = battaglia_navale::Coordinate(poppa);
            navi.push_back(Corazzata(x,y));
            g1->add_nave(navi[i]);

        }
    }
     */





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

}

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



