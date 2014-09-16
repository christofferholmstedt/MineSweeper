#include "square.h"

Square::Square()
{
    squareIndex_ = 42;
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
