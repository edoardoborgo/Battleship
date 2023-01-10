#include "../include/coordinata.h"

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