
#ifndef BATTLESHIP_EXCEPTIONS_H
#define BATTLESHIP_EXCEPTIONS_H

#include <exception>

class Gioco_finito : public std::exception {
public:
    Gioco_finito():std::exception() {};
};

class Nave_non_posizionabile : public std::exception {
public:
    Nave_non_posizionabile():std::exception() {};
};

class Coordinata_non_valida : public std::exception {
public:
    Coordinata_non_valida():std::exception() {};
};

#endif //BATTLESHIP_EXCEPTIONS_H
/*
flag = false;
do{
try {
// Block of code to try
throwable
flag = false;
exception; // Throw an exception when a problem arise
}
catch (std::exception Coordinata_non_valida e) {
flag = true;
}
catch (std::exception Nave_non:posizionabile e) {
flag = true;
}
}while(flag);
*/