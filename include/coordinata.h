//file creato da Giovanni Giancola 2041830

#ifndef BATTLESHIP_COORDINATA_H
#define BATTLESHIP_COORDINATA_H

#include <string>

namespace battaglia_navale{

    class Coordinate{
    public:
        int x;
        int y;
        std::string nome;

        Coordinate()
            : x{-1}, y{-1}
        {

        }

        Coordinate(const int x_nave, const int y_nave)
            :x{x_nave}, y{y_nave}
        {

        }

    };

}

#endif //BATTLESHIP_COORDINATA_H

/*
        class Coordinates
            public:
                int x;
                int y;
                std::string symbol;

            @brief Construct a new Coordinates object, initializing it to (-1, -1) as default (Invalid pair)

    Coordinates() : Coordinates(-1, -1) {};

     * @brief Construct a new Coordinates object
     *
     * @param x
     * @param y

    Coordinates(int x, int y);

    Coordinate c = new Coordinate("e");
    Coordinate c1 = new Coordinate(5, 7);
    c(C);

     * @brief Construct a new Coordinates object
     *
     * @param symbol chessboard coordinates representation

    Coordinates(std::string symbol);

     * @brief Construct a new Coordinates object (copy constructor)
     *
     * @param coord

    Coordinates(const Coordinates &coord)
    {
        this->x = coord.x;
        this->y = coord.y;
        this->symbol = coord.symbol;
    }

     * @brief Assignment operator overloading
     *
     * @param coord
     * @return Coordinates&

    Coordinates &operator=(const Coordinates &coord)
    {
        this->x = coord.x;
        this->y = coord.y;
        this->symbol = coord.symbol;
        return *this;
    }

     * @brief "Equal to" operator overloading
     *
     * @param other_coord
     * @return true
     * @return false

    bool operator==(const Coordinates &other_coord) const
    {
        return this->x == other_coord.x && this->y == other_coord.y;
    }

     * @brief "Different than" operator overloading
     *
     * @param other_coord
     * @return true
     * @return false

    bool operator!=(const Coordinates &other__coord) const
    {
        return !(*this == other__coord);
    }
    // increment and decrement operators disabled
    Coordinates &operator++() = delete;
    Coordinates &operator--() = delete;
};
}
*/