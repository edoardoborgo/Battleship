#include "../include/coordinata.h"

battaglia_navale::Coordinate::Coordinate(const int x, const char y){
    if(controllo(x,y)){
        x_ = x;
        y_ = y-65;
    }
}
bool battaglia_navale::Coordinate::operator==(const battaglia_navale::Coordinate &coord){
    if(x_==coord.x_ && y_==coord.y_)
        return true;
    else
        return false;
}

bool battaglia_navale::Coordinate::operator>=(const battaglia_navale::Coordinate &coord){
    if(x_ >= coord.x_ && y_>=coord.y_)
        return true;
    else
        return false;
}

bool battaglia_navale::Coordinate::operator<=(const battaglia_navale::Coordinate &coord){
    if(x_ <= coord.x_ && y_<=coord.y_)
        return true;
    else
        return false;
}

bool controllo(const int x, const char y)
{
    if(x>= 0 && x<=11 && y-65 >= 0 && y-65 <= 11)
    {
        return true;
    }else{
        //TODO eccezione da gestire nel main
        return false;
    };
}