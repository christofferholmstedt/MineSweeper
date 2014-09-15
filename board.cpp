#include "board.h"

Board::Board(Square square, const int rows, const int columns) :
             square_(square)
{
   board_ = Grid::Grid<Square>(rows, columns);
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

Board * Board::getBoard()
{
    return this;
}
