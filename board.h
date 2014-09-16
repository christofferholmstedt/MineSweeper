#ifndef BOARD_H
#define BOARD_H

#include "square.h"
#include "gridofsquares.h"

class Board
{
public:
    Board(const int rows, const int columns);

    int size() const;
    int rowSize() const;
    int columnSize() const;
    Square * getSquare(const int row, const int column);
    void resize(const int rows, const int columns);

private:
    Square square_;

    GridOfSquares grid_;
};

#endif // BOARD_H
