#include "gridofsquares.h"

GridOfSquares::GridOfSquares()
{
}

int GridOfSquares::size() const
{
    // TODO: Fix type mismatch size_t to int.
    return rowSize() * columnSize();
}

int GridOfSquares::rowSize() const
{
    // TODO: Fix type mismatch size_t to int.
    return rows_.size();
}

int GridOfSquares::columnSize() const
{
    // TODO: Fix type mismatch size_t to int.
    return rows_.at(0).size();
}

void GridOfSquares::resize(const int rows, const int columns)
{
    // TODO: Remove QUICK FIXES and reset the board with new squares properly from
    // Board::newGame when restarting a game.
    rows_.resize( 1 ); // QUICK FIX to reset model when restarting
    rows_.resize( rows );
    for (auto &iterator : rows_)
    {
        iterator.resize( 1 ); // QUICK FIX to reset model when restarting
        iterator.resize( columns );
    }
    // TODO: Delete old values and populate with new in each square.
}

Square * GridOfSquares::getSquare(const int row, const int column)
{
    return &rows_.at(row).at(column);
}
