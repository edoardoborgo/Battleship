//Edoardo Borgo

#include "../include/gioco.h"
#include <cstdlib>
#include <ctime>
#include <fstream>

void Gioco::start_casuale() {
    srand(time(nullptr) + rand());
    int numero_casuale = rand() % 100 + 1;
    if (numero_casuale % 2 == 0)
        turno_g1_ = true;
    else
        turno_g1_ = false;
}

void Gioco::cambio_turno() {
    turno_g1_ = !turno_g1_;
    if (is_bot_game()) {
        numero_turno_attuale++;
    }
}

Gioco::Gioco(bool scelta_bot_game, Giocatore *G1, Computer *G2) {
    //controllo della versione, non servono eccezioni per la versione passata perchè viene controllata nel main
    bot_game_=scelta_bot_game;
    //inizializzazione turno
    start_casuale();
    //inizializzazione giocatori
    G1_ = G1;
    G2_ = G2;
}

Gioco::Gioco(bool turno_G1, Giocatore *G1, Giocatore *G2){
    turno_g1_=turno_G1;
    G1_ = G1;
    G2_ = G2;
    salva_mosse_ = false;
}

Gioco::Gioco(bool turno_G1, Giocatore *G1, Giocatore *G2, std::string nome_file){
    G1_ = G1;
    G2_= G2;
    turno_g1_ = turno_G1;
    nome_file_ = nome_file;

    std::ofstream fout(nome_file_);
    if (is_turno_g1())
        fout << "G1\n";
    else
        fout << "G2\n";
    fout.close();
}

Gioco::Gioco(bool scelta_bot_game, Computer *G1, Computer *G2) {
  //controllo della versione, non servono eccezioni per la versione passata perchè viene controllata nel main
  bot_game_=scelta_bot_game;
  //inizializzazione turno
  start_casuale();

  //inizializzazione giocatori
  G1_ = G1;
  G2_ = G2;

  //inizializzazione log
  //apre e svuota il file o lo crea se non esiste
  std::ofstream fout(nome_file_);

  if (is_turno_g1())
    fout << "true\n";
  else
    fout << "false\n";
  fout.close();
}

bool Gioco::check_input(std::string input){
  int lunghezza=0;
  for(int i=0; i < input.length(); i++){
    lunghezza++;
  }
  if(lunghezza==1){
    if(input[0]=='0'){
      return false;
    }else{
      //il numero non è zero
      return true;
    }
  }else if(lunghezza==2){
    if(input[0]=='0'){
      if(input[1]!='0'){
        return true;
      }else{
        return false;
      }
    }else{
      //il numero non è zero
      if(input[0]=='1'){
        if(input[1]=='0' || input[1]=='1' || input[1]=='2'){
          return true;
        }else{
          return false;
        }
      }else{
        return false;
      }
    }
  }else{
    return false;
  }
}

std::string Gioco::format(std::string input){
  //calcolo la lunghezza di input
  int lunghezza=0;
  for(int i=0; input[i]!='\0'; i++){
    lunghezza++;
  }
  if(lunghezza==3){
    //to upper case
    if(input[0]>=97 && input[0]<=108){
      input[0]=input[0]-32;
    }
    std::string appo = &input[1];
    if(check_input(appo)){
      return input;
    }else{
      throw std::invalid_argument("giorgio");
    }
  }else if(lunghezza==2){
    std::string appo = &input[1];
    std::string risultato;
    if(check_input(appo)){
      risultato=input[0]+"0"+input[1];
      return risultato;
    }else{
      throw std::invalid_argument("filippo");
    }
  }else{
    throw std::invalid_argument("marco");
  }
}

void Gioco::azione(const std::string& origin,const std::string& target) {
    if (numero_turno_attuale < numero_massimo_turni) {
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

        //formattazione mosse e salvataggio
        const std::string& f_origin = origin;
        const std::string& f_target = target;

        if ((f_origin.length() != 3 && f_origin.length() != 2) && (f_target.length() != 3 && f_target.length() != 2)) {
            //lancio una eccezione, nel main viene chiesto di reinserire origin e target
        } else {
            //controllo mosse speciali altrimenti invoco la funzione azione di origin chiamata da giocatore attivo
            if (f_origin == "AA" && f_target == "AA") {
                //cancella gli avvistamenti sonar, cioè le Y
                giocatore_attaccante->cancella_avvistamenti();
                cambio_turno();
                set_log((f_origin +" "+ f_target));
            } else if (f_origin == "XX" && f_target == "XX") {
                print_griglie(giocatore_attaccante);
            } else {
                //controllo che in origin di giocatore attaccante ci sia una nave
                std::vector<Nave *> navi = giocatore_attaccante->get_navi();
                bool trovato = false;
                Nave *nave_scelta;

                /*std::string num;
                for (int j = 1; j < origin.length(); j++)
                    num += origin[j];*/
                battaglia_navale::Coordinate appo(origin);
                battaglia_navale::Coordinate appo2(target);
                for (int i = 0; i < navi.size() && !trovato; i++) {
                    if (navi[i]->get_coordinata_centro() == appo) {
                        nave_scelta = navi[i];
                        trovato = true;
                    }
                }
                if (!trovato) {
                    //non ci sono navi in origin
                    //TODO eccezione, nave non trovata, nel main viene chiesto di reinserire origin e target
                    throw std::invalid_argument("nave non trovata");
                } else {
                    //nave origin trovata
                    battaglia_navale::Coordinate coord(target);
                    nave_scelta->azione(giocatore_attaccante, giocatore_difensore, coord);
                    cambio_turno();
                    set_log((appo.to_string()+" "+appo2.to_string()));
                }
            }
        }
    } else {
        throw  Gioco_finito();
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
            std::cout << "    1   2   3   4   5   6   7   8   9  10   11  12  ";
            std::cout << "  ";
            std::cout << "    1   2   3   4   5   6   7   8   9  10   11  12  " << std::endl;
            std::cout << "  -------------------------------------------------";
            std::cout << "  ";
            std::cout << "  -------------------------------------------------" << std::endl;

            std::cout << row << ' ' << '|';
            for (int colonne = 0; colonne < 12; colonne++) {
                std::cout << " " << griglia_attacco[colonne][righe] << " " << '|';
            }
            std::cout << "   ";
            std::cout << row << ' ' << '|';
            for (int colonne = 0; colonne < 12; colonne++) {
                std::cout << " " << griglia_difesa[colonne][righe] << " " << '|';
            }
            std::cout << std::endl;
        } else if (righe == 11) {
            std::cout << row << ' ' << '|';
            for (int colonne = 0; colonne < 12; colonne++) {
                std::cout << " " << griglia_attacco[colonne][righe] << " " << '|';
            }
            std::cout << "   ";
            std::cout << row << ' ' << '|';
            for (int colonne = 0; colonne < 12; colonne++) {
                std::cout << " " << griglia_difesa[colonne][righe] << " " << '|';
            }
            std::cout << std::endl;

            std::cout << "  -------------------------------------------------";
            std::cout << "   ";
            std::cout << "  -------------------------------------------------" << std::endl;
        } else {
            std::cout << row << ' ' << '|';
            for (int colonne = 0; colonne < 12; colonne++) {
                std::cout << " " << griglia_attacco[colonne][righe] << " " << '|';
            }
            std::cout << "   ";
            std::cout << row << ' ' << '|';
            for (int colonne = 0; colonne < 12; colonne++) {
                std::cout << " " << griglia_difesa[colonne][righe] << " " << '|';
            }
            std::cout << std::endl;
        }
        row++;
    }
}

bool Gioco::is_turno_g1() const {
    return turno_g1_;
}

bool Gioco::is_bot_game() const {
    return bot_game_;
}

bool Gioco::check(std::string parametro) {
        int i=0;
        int primo_carattere;

        if((parametro[i] == 65 || parametro[i] == 88) || (parametro[i] == 97 || parametro[i] == 120)) {
            primo_carattere = parametro[i];
            if (primo_carattere == 65 || primo_carattere == 88) {
                if (parametro[i + 1] == (primo_carattere + 32) && parametro[i + 1] == primo_carattere)
                    return true;
                else
                    return false;
            } else {
                if (parametro[i + 1] == (primo_carattere - 32) && parametro[i + 1] == primo_carattere)
                    return true;
                else
                    return false;
            }
        }else
            return false;
}

void Gioco::set_log(std::string mosse) {
    if(salva_mosse_){
        std::string filename("log.txt");
        std::fstream fout;
        fout.open(filename, std::ios_base::app);
        if (fout.good()) {
            int i = 0;
            while (mosse[i] != '\0') {
                fout << mosse[i];
                i++;
            }
            fout << "\n";
            fout.close();
        }
    }
}

bool Gioco::is_game_over(){
  if(numero_turno_attuale == numero_massimo_turni){
    //funzione che scrive all'interno del log
    return true;
  }
  std::vector<Nave*> appo_check_navi = this->get_giocatore_attuale()->get_navi();
  int navi_vive = appo_check_navi.size();
  for (auto & i : appo_check_navi){
    if (i->is_affondata()){
      navi_vive--;
    }
  }
  if(navi_vive == 0){
    return true;
  }else {
    return false;
  }
}

Giocatore* Gioco::get_giocatore_attuale(){
  if(is_turno_g1()){
    return G1_;
  } else {
    return G2_;
  }
}

Gioco::~Gioco()
{
    delete G1_;
    delete G2_;
}