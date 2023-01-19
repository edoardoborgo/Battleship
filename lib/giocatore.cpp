//Edoardo Borgo

#include "../include/giocatore.h"
#include "../include/corazzata.h"
#include "../include/supporto.h"
#include "../include/sottomarino.h"
#include <fstream>

Giocatore::Giocatore() {
    //inizializzazione del seme per la generazione casuale
    srand(time(nullptr) + rand());
}

bool Giocatore::is_posizionabile(Nave *nave) {
    bool flag = true;
    //controllo se le coordinate che compongono la nave si sovrappongono alle coordinate di altre navi già posizionate
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

void Giocatore::add_nave(Nave *nave) {
    //so già che mi viene passata una nave perchè le condizioni di nave vengono controllate nel costruttore
    if (navi.size() < 8) {
        //controllo che non si sovrapponga ad altre navi usando la funzione is_posizionabile che mi dice se il posizionamento è andato a buon fine o no
        if (is_posizionabile(nave)) {
            //posizionamento corretto, aggiungo la nave
            navi.push_back(nave);
        } else {
            //posizionamento scorretto, lancio un'eccezione da gestire alla chiamata della funzione, la nave viene eliminata e ricreata nel main.
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

std::vector<std::vector<char>>& Giocatore::get_griglia_attacco() {
    return griglia_attacco.get_griglia();
}

void Giocatore::affonda_nave(battaglia_navale::Coordinate coord){
    std::vector<Nave::Tupla> corazza;
    for(int i = 0; i < navi.size(); i++){
        corazza = navi[i]->get_corazza();
        for(auto & j : corazza){
            if(coord==j.coord){
                delete navi[i];
                auto nave_da_eliminare = navi.begin()+i;
                navi.erase(nave_da_eliminare);
            }
        }
    }
}

std::vector<std::vector<char>> Giocatore::get_griglia_difesa() {
    std::vector<std::vector<char>> appo_tabellone;
    int righe = 12;
    int colonne = 12;
    char c = ' ';
    //inizializzazione del tabellone
    for (int col = 0; col < colonne; col++) {
        std::vector<char> v_righe;
        for (int row = 0; row < righe; row++) {
            v_righe.push_back(c);
        }
        appo_tabellone.push_back(v_righe);
    }
    //scorro le navi, se non sono affondate inserisco nelle posizioni occupate da essa il suo carattere identificativo
    for (auto & i : navi) {
        if (!i->is_affondata()) {
            std::vector<Nave::Tupla> corazza = i->get_corazza();
            for (auto & j : corazza) {
                int x_coord = j.coord.get_x();
                int y_coord = j.coord.get_y();
                appo_tabellone[x_coord][y_coord] = j.stato;
            }
        }
    }
    return appo_tabellone;
}


std::string Computer::choose_move() {
    //variabile che indica lo shift per passare dal valore int al corrispondente char nella tabella ascii
    const int to_ascii_number = 48;
    //variabile che indica lo shift per passare dal carattere minuscolo al corrispondente carattere maiuscolo nella tabella ascii
    const int to_ascii_upper_case = 65;

    std::vector<Nave *> appo_navi = get_navi();
    Nave *nave_scelta;
    //scelgo randomicamente una nave, nel caso sia affondata ne scelgo un'altra
    do {
        //rand()%8: genera numeri tra 0 e 7
        nave_scelta = appo_navi[rand() % 8];
    } while (nave_scelta->is_affondata());
    //recupero la coordinata centrale della nave i-esima
    battaglia_navale::Coordinate coord_origin = nave_scelta->get_coordinata_centro();
    //aggiungo +1 per tornare al range di numeri utilizzati nella stampa delle griglie
    coord_origin.set_x(coord_origin.get_x()+1);
    //generazione della mossa string
    std::string mossa = "";
    mossa += (char)(coord_origin.get_y()+to_ascii_upper_case);
    //se il valore x di coordinata origin è minore 10 inserisco un carattere '0' per formattare l'output e poi inserisco il numero
    if (coord_origin.get_x()<10){
        mossa+="0";
        mossa += (char)(coord_origin.get_x()+to_ascii_number);
    }else{
        //se non è necessaria formattazione inserisco il numero senza caratteri speciali
        mossa += std::to_string(coord_origin.get_x());
    }
    //generazione di coordinata target casuale
    mossa += " ";
    int carattere2 = rand()%12;
    //aggiungo +1 per tornare al range di numeri utilizzati nella stampa delle griglie
    int numero2 = rand()%12+1;
    mossa += (char)(carattere2+to_ascii_upper_case);
    //se il valore x di coordinata target è minore 10 inserisco un carattere '0' per formattare l'output e poi inserisco il numero
    if (numero2<10){
        mossa+="0";
        mossa += (char)(numero2+to_ascii_number);
    }else{
        //se non è necessaria formattazione inserisco il numero senza caratteri speciali
        mossa += std::to_string(numero2);
    }
    return mossa;
}


void Computer::crea_nave(int dimensione) {
    //variabile che indica lo shift per passare dal valore int al corrispondente char nella tabella ascii
    const int to_ascii_number = 48;
    //variabile che indica lo shift per passare dal carattere minuscolo al corrispondente carattere maiuscolo nella tabella ascii
    const int to_ascii_upper_case = 65;

    int x;
    char y;
    battaglia_navale::Coordinate prua{}, poppa{};
    bool orizzontale;
    bool flag = true;

    Nave *n;
    do {
        try {
            //condizione per generare una nave in base al parametro lunghezza
            if (dimensione == 1) {
                //generazione sottomaribo
                x = rand() % 12;
                //generazione char tra 'A' e 'N'
                y = rand() % 12 + 'A';
                prua = battaglia_navale::Coordinate(x, y);
                auto* s = new Sottomarino(prua);
                n = s;
            } else if (dimensione == 3 || dimensione == 5) {
                //generazione supporto/corazzata
                //randomizzo il parametro orizzontale generando un numero casuale e controllando se è pari o dispari tramite il resto della divisione intera
                orizzontale = rand() % 2;
                if (orizzontale) {
                    //limito la generazione del parametro x in base alla lunghezza della nave da posizionare
                    x = rand() % (12 - dimensione);
                    y = rand() % 12 + to_ascii_upper_case;
                    prua = battaglia_navale::Coordinate(x, y);
                    poppa = battaglia_navale::Coordinate(x + dimensione - 1, y);
                } else {
                    //limito la generazione del parametro y in base alla lunghezza della nave da posizionare
                    y = rand() % (12 - dimensione) + to_ascii_upper_case;
                    x = rand() % 12;
                    prua = battaglia_navale::Coordinate(x, y);
                    poppa = battaglia_navale::Coordinate(x, y + dimensione - 1);
                }
                //a seconda della dimensione richiesta genero la relativa nave
                if (dimensione == 5) {
                    auto* c = new Corazzata(prua, poppa);
                    n = c;
                } else {
                    auto* s = new Supporto(prua, poppa);
                    n = s;
                }
            }
            //tramite add_nave controllo se la nave è posizionabile: se le coordinate della nave sono libere la nave viene aggiunta
            add_nave(n);
            //tramite set_log inserisco la mossa origin target nel file di log
            set_log(prua.to_string() + " " + poppa.to_string());
            flag = false;
        } catch (std::invalid_argument &e) {
            //nel caso in cui venga lanciata un'eccezione rieseguo il ciclo
            flag = true;
        }
    } while (flag);
}

Giocatore::~Giocatore(){
    for (auto & i : navi) {
        delete i;
    }
}

void Giocatore::set_log(std::string mosse) {
    //non controllo la lunghezza del comando passato perchè essendo già stato utilizzato per azione sono sicuro che sia accettabile
    std::string filename("../log.txt");
    std::fstream fout;
    fout.open(filename, std::ios_base::app);
    if (fout.good()) {
        int i = 0;
        while (mosse[i] != '\0') {
            fout << mosse[i];
            i++;
        }
        fout << "\n";
    }
    fout.close();
}