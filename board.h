#ifndef BOARD_H
#define BOARD_H

#include "square.h"
#include "lib/grid.h"

class Board
{
public:
    Board(Square square, const int rows, const int columns);

    int size() const;
    int rowSize() const;
    int columnSize() const;
    Board * getBoard();

private:
    Square square_;

    Grid::Grid<Square> board_;

};

#endif // BOARD_H
