#include "gridofsquares.h"

GridOfSquares::GridOfSquares()
{
}

int GridOfSquares::size() const
{
    return rowSize() * columnSize();
}

int GridOfSquares::rowSize() const
{
    return rows_.size();
}

int GridOfSquares::columnSize() const
{
    return rows_.at(0).size();
}

void GridOfSquares::resize(const int rows, const int columns)
{
    rows_.resize( rows );
    for (auto &iterator : rows_)
    {
        iterator.resize( columns );
    }
    // TODO: Delete old values and populate with new in each square.
}

Square GridOfSquares::getSquare(const int row, const int column) const
{
    return rows_.at(row).at(column);
}
