//file creato da Giovanni Giancola 2041830
#include <string>

#ifndef BATTLESHIP_COORDINATA_H
#define BATTLESHIP_COORDINATA_H

namespace battaglia_navale {

    class Coordinate {
    private:
        int x_;
        int y_;

    public:
        Coordinate(){}

        Coordinate(const int x, const char y);

        Coordinate(std::string coordinata);

        bool operator==(const battaglia_navale::Coordinate &coord);

        bool operator>=(const battaglia_navale::Coordinate &coord);

        bool operator<=(const battaglia_navale::Coordinate &coord);

        bool controllo(const int x);

        int get_x() const {
            return x_;
        }

        int get_y() const {
            return y_;
        }

        void set_x(int x);

        void set_y(int y);

        battaglia_navale::Coordinate &operator=(battaglia_navale::Coordinate nuova_coordinata)
        {
            this->x_ = nuova_coordinata.get_x();
            this->y_ = nuova_coordinata.get_y();
            return *this;
        }
    };
}

#endif //BATTLESHIP_COORDINATA_H