#include "../include/giocatore.h"
#include "../include/corazzata.h"
#include "../include/supporto.h"
#include "../include/sottomarino.h"

Giocatore::Giocatore() {
    srand(time(nullptr) + rand());
}

bool Giocatore::is_posizionabile(Nave *nave) {
    bool flag = true;
    std::vector<Nave::Tupla> corazza_input = nave->get_corazza();
    for (int i = 0; i < corazza_input.size() && flag; i++) {
        for (int j = 0; j < navi.size() && flag; j++) {
            std::vector<Nave::Tupla> corazza_test = navi[j]->get_corazza();
            for (int k = 0; k < navi[j]->get_corazza().size() && flag; k++) {
                if (corazza_input[i].coord == corazza_test[k].coord)
                    flag = false;
            }
        }
    }
    return flag;
}

void Giocatore::add_nave(Nave *nave) { //TODO initializer list
    //so già che mi viene passata una nave perchè le condizioni di nave vengono controllate nel costruttore
    //controllo che non si sovrapponga ad altre navi usando la funzione is_posizionabile che mi dice se il posizionamento è andato a buon fine o no
    if (navi.size() < 8) {
        //le navi sono già state tutte aggiunte
        if (is_posizionabile(nave)) {
            //posizionamento corretto, aggiungo la nave
            navi.push_back(nave);
        } else {
            //posizionamento scorretto, lancio un'eccezione da gestire alla chiamata della funzione; la nave viene eliminata e ricreata nel main
            throw std::invalid_argument("Aggiunta di nave non andata a buon fine.");
        }
    }
}

void Giocatore::set_risultato(battaglia_navale::Coordinate coord, char stato) {
    griglia_attacco.set_risultato(coord, stato);
}

std::vector<Nave *> Giocatore::get_navi() {
    return navi;
}

void Giocatore::cancella_avvistamenti() {
    griglia_attacco.battaglia_navale::Griglia::cancella_avvistamenti();
}

std::vector<std::vector<char>> Giocatore::get_griglia_attacco() {
    return griglia_attacco.get_griglia();
}

std::vector<std::vector<char>> Giocatore::get_griglia_difesa() {
    std::vector<std::vector<char>> appo_tabellone;
    int righe = 12;
    int colonne = 12;
    char c = ' ';
    for (int col = 0; col < colonne; col++) {
        std::vector<char> v_righe;
        for (int row = 0; row < righe; row++) {
            v_righe.push_back(c);
        }
        appo_tabellone.push_back(v_righe);
    }

    for (int i = 0; i < navi.size(); i++) {
        if (!navi[i]->is_affondata()) {
            std::vector<Nave::Tupla> corazza = navi[i]->get_corazza();
            for (int j = 0; j < corazza.size(); j++) {
                int x_coord = corazza[j].coord.get_x();
                int y_coord = corazza[j].coord.get_y();
                appo_tabellone[x_coord][y_coord] = corazza[j].stato;
            }
        }
    }
    return appo_tabellone;
}

std::string Computer::choose_move() {
    //variabile che indica il valore per passare dal valore int al char corrispondente nella tabella ascii
    const int to_ascii_number = 48;
    //variabile che indica
    const int to_ascii_upper_case = 65;
    //random tra 0 e 7, %8 genera 8 numeri a partire da zero

    //scegli nave e poi scegli la mossa a seconda della nave
    std::vector<Nave *> appo_navi = get_navi();
    Nave *nave_scelta;
    do {
        nave_scelta = appo_navi[rand() % 8];
    } while (nave_scelta->is_affondata());
    //recupero coord centrale della nave i-esima
    battaglia_navale::Coordinate coord_origin = nave_scelta->get_coordinata_centro();
    //origin casuale da vector navi
    std::string mossa = "";
    mossa += (char)(coord_origin.get_y()+to_ascii_upper_case);
    if (coord_origin.get_x()<10){
        mossa+="0";
        mossa += (char)(coord_origin.get_x()+to_ascii_number);
    }else{
        mossa += std::to_string(coord_origin.get_x());
    }
    //target casuale
    mossa += " ";
    int carattere2 = rand()%12;
    int numero2 = rand()%12;
    mossa += (char)(carattere2+to_ascii_upper_case);
    if (numero2<10){
        mossa+="0";
        mossa += (char)(numero2+to_ascii_number);
    }else{
        mossa += std::to_string(numero2);
    }
    return mossa;
}


void Computer::crea_nave(int dimensione) {
    const int to_ascii_number = 48;
    const int to_ascii_upper_case = 65;

    int x;
    char y;
    battaglia_navale::Coordinate prua, poppa;
    bool orizzontale;
    bool flag = true;
    Nave *n;
    do {
        try {
            if (dimensione == 1) {
                x = rand() % 12;
                y = rand() % 12 + 'A';
                prua = battaglia_navale::Coordinate(x, y);
                auto* s = new Sottomarino(prua);
                n = s;
            } else if (dimensione == 3 || dimensione == 5) {
                orizzontale = rand() % 2;
                if (orizzontale) {
                    x = rand() % (12 - dimensione);
                    y = rand() % 12 + to_ascii_upper_case;
                    prua = battaglia_navale::Coordinate(x, y);
                    poppa = battaglia_navale::Coordinate(x + dimensione - 1, y);
                } else {
                    y = rand() % (12 - dimensione) + to_ascii_upper_case;
                    x = rand() % 12;
                    prua = battaglia_navale::Coordinate(x, y);
                    poppa = battaglia_navale::Coordinate(x, y + dimensione - 1);
                }

                if (dimensione == 5) {
                    auto* c = new Corazzata(prua, poppa);
                    n = c;
                } else {
                    auto* s = new Supporto(prua, poppa);
                    n = s;
                }
            }
            add_nave(n);
            flag = false;
        } catch (std::invalid_argument e) {
            std::cout << "ripeti" << std::endl;
            flag = true;
        }
    } while (flag);

}