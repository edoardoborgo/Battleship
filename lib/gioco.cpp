#include "../include/gioco.h"
#include <cstdlib>
#include <ctime>
#include <fstream>

void Gioco::start_casuale() {
    srand(time(NULL) + rand());
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
    if (scelta_bot_game)
        bot_game_ = true;
    else if (!scelta_bot_game)
        bot_game_ = false;

    //inizializzazione turno
    start_casuale();

    //inizializzazione giocatori
    G1_ = G1;
    G2_ = G2;
}

Gioco::Gioco(bool scelta_bot_game, Computer *G1, Computer *G2) {
  //controllo della versione, non servono eccezioni per la versione passata perchè viene controllata nel main
  if (scelta_bot_game)
    bot_game_ = true;
  else if (!scelta_bot_game)
    bot_game_ = false;

  //inizializzazione turno
  start_casuale();

  //inizializzazione giocatori
  G1_ = G1;
  G2_ = G2;

  //inizializzazione log
  //apre e svuota il file o lo crea se non esiste
  //DA FARE: catch eccezioni scrittura
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
      risultato=input[0]+'0'+input[1];
      return risultato;
    }else{
      throw std::invalid_argument("filippo");
    }
  }else{
    throw std::invalid_argument("marco");
  }
}

void Gioco::azione(std::string origin, std::string target) {
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

        //formattazione mosse e salvataggio, controllare il return
        const std::string& f_origin = origin;
        const std::string& f_target = target;

        //controlli sui parametri: qua o sul main?
        if ((f_origin.length() != 3 && f_origin.length() != 2) && (f_target.length() != 3 && f_target.length() != 2)) {
            //lancio una eccezione, nel main viene chiesto di reinserire origin e target
        } else {
            //controllo mosse speciali altriementi invoco la funzione azione di origin chiamata da giocatore attivo
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
                    throw std::invalid_argument("giovanni");
                } else {
                    //nave origin trovata
                    std::string num;
                    num.push_back(origin[1]);
                    num.push_back(origin[2]);
                    battaglia_navale::Coordinate coord(stoi(num), target[0]);
                    nave_scelta->azione(giocatore_attaccante, giocatore_difensore, coord);
                    cambio_turno();
                    set_log((appo.to_string()+" "+appo2.to_string()));
                }
            }
        }
    } else {
        //catch
        throw new Gioco_finito();
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
            std::cout << "  ";
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

bool Gioco::is_turno_g1() {
    return turno_g1_;
}

bool Gioco::is_bot_game() {
    return bot_game_;
}

void Gioco::check(std::string parametro) {
    for (int i = 0; i < parametro.length(); i++) {
        if (i == 0) {
            if (!(parametro[0] >= 65 && parametro[0] <= 90)) {
                //TODO eccezione da gestire nel main
            }
        } else {
            if (!(parametro[i] >= 48 && parametro[i] <= 57)) {
                //TODO eccezione da gestire nel main
            }
        }
    }
    std::string num;
    num.push_back(parametro[1]);
}

void Gioco::set_log(std::string mosse) {
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
        fout.close();
    }

    /*char filename[ ] = "Text1.txt";

    fstream uidlFile(filename, std::fstream::in | std::fstream::out | std::fstream::app);


    if (uidlFile.is_open())
    {
        uidlFile << filename<<"\n---\n";
        uidlFile.close();
    }
    else
    {
        cout << "Cannot open file";
    }*/
/*
 *  string filePath = "/somedir/log_"+getCurrentDateTime("date")+".txt";

    ofstream ofs(filePath.c_str(), std::ios_base::out | std::ios_base::app );
    ofs << now << '\t' << logMsg << '\n';
    ofs.close();
 * */
}

bool Gioco::is_game_over(){
  if(numero_turno_attuale == numero_massimo_turni){
    //funzione che scrive all'interno del log
    std::cout << "Il gioco di bot ha raggiunto il numero massimo di mosse senza finire le navi, ricominciare" << std::endl;
    return true;
  }
  std::vector<Nave*> appo_check_navi = this->get_giocatore_attuale()->get_navi();
  int navi_vive = appo_check_navi.size();
  for (int i = 0; i < appo_check_navi.size(); i++){
    if (appo_check_navi[i]->is_affondata()){
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