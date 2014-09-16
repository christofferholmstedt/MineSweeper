#include <cstdlib>

#include "square.h"

Square::Square()
{
    squareIndex_ = -1;

    int pseudoRandomValue = rand() % 2;
    if (pseudoRandomValue == 0)
    {
        hasMine_ = false;
    }
    else
    {
        hasMine_ = true;
    }
}

Square::Square(const int squareIndex) :
    squareIndex_(squareIndex)
{
}

int Square::getSquareIndex() const
{
    return squareIndex_;
}

void Square::setSquareIndex(const int squareIndex)
{
    squareIndex_ = squareIndex;
}

bool Square::getHasMine() const
{
    return hasMine_;
}
