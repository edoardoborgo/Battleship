#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <thread>

using namespace std;

void leggi_mosse(){
  ifstream file;
  file.open("../log.txt");
  if (file.is_open()) {
    while (file) {
      std::string riga;
      file >> riga;
      std::cout << riga;
    }
  }
}

int replayMain(){
  leggi_mosse();
  return 0;
}