#include <iostream>
#include "../include/gioco.h"
#include "../include/corazzata.h"
#include "../include/supporto.h"
#include "../include/sottomarino.h"

using namespace std;

vector<string> split(string mossa) {
  int i = 0;
  string aux;
  int ascii_space = 32;
  vector<string> coordinate;
  while (mossa[i] != '\n') {
    if (mossa[i] != ascii_space) {
      aux += mossa[i];
    } else {
      coordinate.push_back(aux);
      //aux = ""; (?)
    }
    i++;
  }
  return coordinate;
}

void set_coordinate(string input, string &origin, string &target) {
  vector<string> coordinate = split(input);
  origin = coordinate[0];
  target = coordinate[1];
}

int main(int argc, char **argv) {
  if (argc != 2) {
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
  battaglia_navale::Coordinate x, y;
  int dimensione_corazzata = 5;
  int dimensione_supporto = 3;
  int dimensione_sottomarino = 1;
  int numero_corazzate = 3;
  int numero_supporto = 3;
  int numero_sottomarino = 2;

  if (scelta_bot_game) {
    Computer G1 = Computer();
    Gioco game = Gioco(scelta_bot_game, &G1, &G2);


    //creo le navi del giocatore 2
    for (int c = 0; c < numero_corazzate; c++) {
      G2.crea_nave(dimensione_corazzata);
    }
    for (int s = 0; s < numero_supporto; s++) {
      G2.crea_nave(dimensione_supporto);
    }
    for (int e = 0; e < numero_sottomarino; e++) {
      G2.crea_nave(dimensione_sottomarino);
    }
    //creo le navi del giocatore 1
    for (int c = 0; c < numero_corazzate; c++) {
      G1.crea_nave(dimensione_corazzata);
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
    bool flag = false;
    Giocatore G1 = Giocatore();
    Gioco game = Gioco(scelta_bot_game, &G1, &G2);

    //creo le navi del giocatore 2
    for (int c = 0; c < numero_corazzate; c++) {
      G2.crea_nave(dimensione_corazzata);
    }
    for (int s = 0; s < numero_supporto; s++) {
      G2.crea_nave(dimensione_supporto);
    }
    for (int e = 0; e < numero_sottomarino; e++) {
      G2.crea_nave(dimensione_sottomarino);
    }
    std::vector<Nave *> navi(8);

    /*------------------------------------------------------------------------------------------------
     * INSERIMENTO DELLE NAVI CORAZZATE
     *------------------------------------------------------------------------------------------------*/
    int i = 0;
    for (int j = 0; j < numero_corazzate; ++j) {
      do {
        try {
          cout << "inserisci le coordinate di prua e poppa della corazzata n " + to_string(j) + "(lunghezza 5)";
          cin >> input;
          set_coordinate(input, prua, poppa);
          x = battaglia_navale::Coordinate(prua);
          y = battaglia_navale::Coordinate(poppa);
          Corazzata c = Corazzata(x, y);
          navi.push_back(&c);
          G1.add_nave(navi[i]);
        } catch (invalid_argument e) {
          flag = true;
          cout << "Coordinate errate della nave o coordinate occupate, reinserire la nave";
        }
        i++;
        flag = false;
      } while (flag);
    }
    /*------------------------------------------------------------------------------------------------
    * INSERIMENTO DELLE NAVI SUPPORTO
    ------------------------------------------------------------------------------------------------*/
    for (int j = 0; j < numero_supporto; ++j) {
      do {
        try {
          cout << "inserisci le coordinate di prua e poppa della nave da supporto n " + to_string(j) + "(lunghezza 5)";
          cin >> input;
          set_coordinate(input, prua, poppa);
          x = battaglia_navale::Coordinate(prua);
          y = battaglia_navale::Coordinate(poppa);
          Supporto c = Supporto(x, y);
          navi.push_back(&c);
          G1.add_nave(navi[i]);
        } catch (invalid_argument) {
          flag = true;
          cout << "Coordinate errate della nave o coordinate occupate, reinserire la nave";
        }
        i++;
        flag = false;
      } while (flag);
    }
    /*------------------------------------------------------------------------------------------------
  * INSERIMENTO DELLE NAVI SOTTOMARINO
  ------------------------------------------------------------------------------------------------*/
    for (int j = 0; j < numero_sottomarino; ++j) {
      do {
        try {
          cout << "inserisci le'unica coordinata di prua/poppa della nave da explorer n " + to_string(j)
              + "(lunghezza 1)";
          cin >> input;
          x = battaglia_navale::Coordinate(input);
          Sottomarino e = Sottomarino(x);
          navi.push_back(&e);
          G1.add_nave(navi[i]);
        } catch (invalid_argument) {
          flag = true;
          cout << "Coordinate errate della nave o coordinate occupate, reinserire la nave";
        }
        i++;
        flag = false;
      } while (flag);
    }
  }

  std::cout << "worka";


  /*------------------------------------------------------------------------------------------------
   * CREAZIONE DELLE NAVI
   -------------------------------------------------------------------------------------------------*/
  /*G1->crea_nave(5);
  G1->crea_nave(5);
  G1->crea_nave(5);*/
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
