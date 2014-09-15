#ifndef GRIDOFSQUARES_H
#define GRIDOFSQUARES_H

#include <vector>

#include "square.h"

class GridOfSquares
{
public:
    GridOfSquares();

    int size() const;
    int rowSize() const;
    int columnSize() const;
    void resize(const int rows, const int columns);
    Square getSquare(const int row, const int column) const;

private:
    std::vector<std::vector<Square> > rows_;

};


#endif // GRIDOFSQUARES_H
