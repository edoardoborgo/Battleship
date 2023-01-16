#include <iostream>
#include "../include/gioco.h"
#include "../include/corazzata.h"
#include "../include/supporto.h"


using namespace std;

vector<string> split(string mossa){
    int i = 0;
    string aux;
    vector<string> coordinate;
    while(mossa[i] != '\n'){
        if(mossa[i] != 32){
            aux += mossa[i];
        }
        else{
            coordinate.push_back(aux);
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

int main(int argc, char* argv[]){
    //problemi: 1)parametri tramite reference, 2)corazzata non ha un operator= che restituisce la reference all'oggetto (forse)
    battaglia_navale::Coordinate x = battaglia_navale::Coordinate(1,'A');
    battaglia_navale::Coordinate y = battaglia_navale::Coordinate(1,'A');
    Corazzata c1(x,y);

    Corazzata c2(battaglia_navale::Coordinate(1,'A'), battaglia_navale::Coordinate(1,'A'));

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

    /*
     ----------------------------------------------------------------------------------------------------------
     capisco che tipo di gioco è
     ----------------------------------------------------------------------------------------------------------
     */

    if (argv[1][0] == 'p') {
        g1 = new Giocatore();
    } else {
        g1 = new Computer();
        bot = true;
    }

    Gioco *game = new Gioco(bot, g1, g2);

    /*
     ----------------------------------------------------------------------------------------------------------
     inserimento delle navi
     ----------------------------------------------------------------------------------------------------------
     */
    std::vector<Nave *> navi;

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 3; ++j) {
            string prua, poppa;
            cout << "inserisci le coordinate di prua e poppa della corazzata n " + j;
            cin >> input;
            set_coordinate(input, prua, poppa);
            battaglia_navale::Coordinate x = battaglia_navale::Coordinate(prua );
            battaglia_navale::Coordinate y = battaglia_navale::Coordinate(poppa);
            navi.push_back(Corazzata(x,y));
            g1->add_nave(Corazzata(x,y));

        }
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

}



