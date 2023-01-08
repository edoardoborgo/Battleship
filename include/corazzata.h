#include "nave.h"
#include "coordinata.h"
#include "giocatore.h"
#include "griglia.h"

#ifndef BATTLESHIP_CORAZZATA_H
#define BATTLESHIP_CORAZZATA_H

#include

class Corazzata : public Nave {
private:
    char simbolo_ = 'C';
    int dimensione = 5;
public:
    Corazzata(battaglia_navale::Coordinate &prua, battaglia_navale::Coordinate &poppa); //costruttore con array di bool da 5
    bool azione(Giocatore::player difensore, battaglia_navale::Coordinate &target); //recupero griglia del difensore, controllo se c'è una nave, se true diminuisco corazza e stampo 'X', se false 'O'
    void set_corazza();
};

#endif //BATTLESHIP_CORAZZATA_H

/*
#ifndef PIECE_H
#define PIECE_H

#include <vector>

//#include "Chessboard.h"
#include "Utilities.h"

namespace chessgame
{
    using std::vector;

    class Chessboard;
    class Piece
    {
        PieceColor color;
        char symbol;

    protected:
        Piece() = delete;
        Piece(PieceColor color, char symbol);

    public:
        char getSymbol();
        PieceColor getColor();
        virtual vector<Coordinates> getMoves(const Chessboard &board, const Coordinates &coord) = 0;
    };
}

#endif
*/