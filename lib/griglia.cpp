#include "../include/griglia.h"

battaglia_navale::Griglia::Griglia() {
    //inizializzazione vector_char<vector_char>
    char c = ' ';
    for (int col = 0; col < colonne; col++) {
        std::vector<char> v_righe;
        for (int row = 0; row < righe; row++) {
            v_righe.push_back(c);
        }
        tabellone.push_back(v_righe);
    }
}

void battaglia_navale::Griglia::set_risultato(battaglia_navale::Coordinate coord, char stato) {
    tabellone[coord.get_x()][coord.get_y()] = stato;
}

void battaglia_navale::Griglia::print_griglia() {
    int num = 0;
    for (int i = 0; i < tabellone.size(); i++) {
        for (int j = 0; j < tabellone[i].size(); j++) {
            std::cout << tabellone[i][j] << '|';
        }
        std::cout << std::endl;
    }
}

std::vector<std::vector<char>> battaglia_navale::Griglia::get_griglia(){
    return tabellone;
}

void battaglia_navale::Griglia::cancella_avvistamenti(){
    for(int col=0; col<colonne; col++)
        for(int row=0; row<righe; row++)
            if(tabellone[col][row]=='Y')
                tabellone[col][row]=' ';
}