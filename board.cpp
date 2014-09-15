#include "board.h"

Board::Board(const int rows, const int columns)
{
    grid_.resize(rows, columns);
}

int Board::size() const
{
    return grid_.size();
}

int Board::rowSize() const
{
    return grid_.rowSize();
}

int Board::columnSize() const
{
    return grid_.columnSize();
}

Square Board::getSquare(const int row, const int column)
{
    return grid_.getSquare(row, column);
}
