#include "board.h"

Board::Board(const int rows, const int columns)
{
    board_.resize(rows, columns);
}

int Board::size() const
{
    return board_.size();
}

int Board::rowSize() const
{
    return board_.rowSize();
}

int Board::columnSize() const
{
    return board_.columnSize();
}
