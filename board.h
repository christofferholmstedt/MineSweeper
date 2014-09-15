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

private:
    Square square_;

    GridOfSquares board_;
};

#endif // BOARD_H
