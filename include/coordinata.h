//file creato da Giovanni Giancola 2041830

#ifndef BATTLESHIP_COORDINATA_H
#define BATTLESHIP_COORDINATA_H

namespace battaglia_navale {

    class Coordinate {
    private:
        int x_;
        int y_;

    public:
        Coordinate(){}

        //TODO controllo
        Coordinate(const int x, const char y);

        //TODO definizione inline?
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
    };

}

#endif //BATTLESHIP_COORDINATA_H