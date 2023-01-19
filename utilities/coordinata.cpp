//Mattia Rosa
#include <stdexcept>
#include "../include/coordinata.h"

// y viene passato come char perchè convertito dopo
battaglia_navale::Coordinate::Coordinate( int x,  char y) {
    if (controllo(x) && controllo(y - 65)) {
        x_ = x;
        y_ = (int)(y - 65);
    }
    else
        throw std::invalid_argument("coordinate not valid");
}

battaglia_navale::Coordinate::Coordinate(std::string coordinata) {
    if(toupper(coordinata[0]) > 64 && toupper(coordinata[0]) < 77 ){
        y_ = toupper(coordinata[0]) - 65;
    }
    else
        throw std::invalid_argument("y non valida");
    std::string tmp = coordinata.substr(1,coordinata.length());
    x_=std::stoi(tmp) - 1; //tira eccezione se error
    if(x_<0||x_>11) throw std::invalid_argument("x non valida");
}

bool battaglia_navale::Coordinate::operator==(const battaglia_navale::Coordinate &coord) const {
    if (x_ == coord.x_ && y_ == coord.y_)
        return true;
    else
        return false;
}

bool battaglia_navale::Coordinate::operator>=(const battaglia_navale::Coordinate &coord) const{
    if (x_ >= coord.x_ && y_ >= coord.y_)
        return true;
    else
        return false;
}

bool battaglia_navale::Coordinate::operator<=(const battaglia_navale::Coordinate &coord) const {
    if (x_ <= coord.x_ && y_ <= coord.y_)
        return true;
    else
        return false;
}

bool battaglia_navale::Coordinate::controllo(int var) {
    if (var >= 0 && var <= 11)
        return true;
    else
        return false;
}

void battaglia_navale::Coordinate::set_y(int y) {
    if (controllo(y)) {
        y_ = y;
    } else {
        throw std::invalid_argument("Coordinata non accettabile");
    }
}

void battaglia_navale::Coordinate::set_x(int x) {
    if (controllo(x)) {
        x_ = x;
    } else {
        throw std::invalid_argument("Coordinata non accettabile");
    }
}

// Viene trasformata la coordinata nella stringa di template A01
std::string battaglia_navale::Coordinate::to_string() const{
    std::string aux;
    aux+= (std::to_string(y_ + 65));
    if(x_< 9)
    {
        aux+="0";
    }
    aux += std::to_string(x_ + 1);
    return aux;
}


