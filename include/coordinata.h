//file creato da Giovanni Giancola 2041830

#ifndef BATTLESHIP_COORDINATA_H
#define BATTLESHIP_COORDINATA_H

namespace battaglia_navale {

    class Coordinate {
    private:
        int x_;
        char y_;
    public:
        Coordinate()
                : x_{-1}, y_{} {}

        Coordinate(const int x, const char y)
                : x_{x}, y_{y} {}

        //TODO definizione inline?
        bool operator==(const battaglia_navale::Coordinate &coord);

        int get_x() const {
            return x_;
        }

        int get_y() const {
            return y_;
        }

        //TODO controllo che i nuovi valori siano accettabili cioè interni alla griglia
        void set_x(int x){
            x_= x;
        }

        void set_y(int y){
            y_= y;
        }
    };

}

#endif //BATTLESHIP_COORDINATA_H