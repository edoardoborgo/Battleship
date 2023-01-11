#include <vector>
#include <iostream>

using namespace std;

int main(){
  int righe = 12;
  int colonne = 12;
  std::vector<std::vector<char>> tabellone;
  char c = ' ';
  for (int col = 0; col < colonne; col++) {
    std::vector<char> v_righe;
    for (int row = 0; row < righe; row++) {
      v_righe.push_back(c);
    }
    tabellone.push_back(v_righe);
  }

  cout << "-------------------------" << endl;
  for (int i = 0; i < tabellone.size(); i++){
    cout << '|';
      for(int j = 0; j < tabellone[i].size(); j++){
        cout << tabellone[i][j] << '-';
      }
    cout << endl;
  }
  cout << "-------------------------" << endl;
}