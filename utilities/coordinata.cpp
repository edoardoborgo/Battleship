#include <stdexcept>
#include "../include/coordinata.h"

battaglia_navale::Coordinate::Coordinate(const int x, const char y) {
    if (controllo(x) && controllo(y - 65)) {
        x_ = x;
        y_ = y - 65;
    }
    else
        throw std::invalid_argument("coordinate not valid");
}

battaglia_navale::Coordinate::Coordinate(std::string coordinata) {
    if(toupper(coordinata[0]) > 64 && toupper(coordinata[0]) < 77 ){
        y_ = toupper(coordinata[0]) - 65;
    }
    else if((int)coordinata[1] < 1)
    {
        if((int)coordinata[2] < 3){
            x_ = (int)coordinata[2] +10;
        }
    }
    else if((int) coordinata[1] > 1 && (int) coordinata[1] < 10)
    {
        x_ == (int) coordinata[1];
    }
}

bool battaglia_navale::Coordinate::operator==(const battaglia_navale::Coordinate &coord) {
    if (x_ == coord.x_ && y_ == coord.y_)
        return true;
    else
        return false;
}

bool battaglia_navale::Coordinate::operator>=(const battaglia_navale::Coordinate &coord) {
    if (x_ >= coord.x_ && y_ >= coord.y_)
        return true;
    else
        return false;
}

bool battaglia_navale::Coordinate::operator<=(const battaglia_navale::Coordinate &coord) {
    if (x_ <= coord.x_ && y_ <= coord.y_)
        return true;
    else
        return false;
}

bool battaglia_navale::Coordinate::controllo(const int var) {
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


