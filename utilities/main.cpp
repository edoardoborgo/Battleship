/*#include <vector>
#include <iostream>

using namespace std;

int main(){
  int righe = 12;
  int colonne = 12;
  std::vector<std::vector<char>> tabellone;
  char c = '-';
  for (int col = 0; col < colonne; col++) {
    std::vector<char> v_righe;
    for (int row = 0; row < righe; row++) {
      v_righe.push_back(c);
    }
    tabellone.push_back(v_righe);
  }

  char row = 65;
  cout << "  --------------------------------------------------" << endl;
  for (int i = 0; i < tabellone.size(); i++){
    cout << row << ' ' << '|';
      for(int j = 0; j < tabellone[i].size(); j++){
        cout << " " << tabellone[i][j] << " " << '|';
      }
    cout << endl;
    row++;
  }
  cout << "  --------------------------------------------------" << endl;
  cout << "    1   2   3   4   5   6   7   8   9  10   11  12  " << endl;
  
}
*/

#include <iostream>
#include <vector>

std::string choose_move(){
    srand(time(NULL)+rand());
    const int to_ascii_number = 48;
    const int to_ascii_upper_case = 65;
    //random tra 0 e 7, %8 genera 8 numeri a partire da zero

    //scegli nave e poi scegli la mossa a seconda della nave

    //recupero coord centrale della nave i-esima
    std::string mossa = "";
    int carattere = rand()%12;
    int numero = rand()%100;
    mossa += (char)(carattere+to_ascii_upper_case);
    if (numero<10){
        mossa+="0";
        mossa += (char)(numero+to_ascii_number);
    }else{
        mossa += std::to_string(numero);
    }
    mossa += " ";
    int carattere2 = rand()%12;
    int numero2 = rand()%100;
    mossa += (char)(carattere2+to_ascii_upper_case);
    if (numero2<10){
        mossa+="0";
        mossa += (char)(numero2+to_ascii_number);
    }else{
        mossa += std::to_string(numero2);
    }
    //mossa += "K";
    return mossa;
}

int main()
{
    for(int i=0; i<10; i++){
        std::cout << choose_move() << std::endl;
    }

    return 0;
}