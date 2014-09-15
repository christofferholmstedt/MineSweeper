#include "square.h"

Square::Square()
{
    squareNumber_ = 42;
}

Square::Square(const int squareNumber) :
    squareNumber_(squareNumber)
{
}

int Square::getSquareNumber() const
{
    return squareNumber_;
}

void Square::setSquareNumber(const int squareNumber)
{
    squareNumber_ = squareNumber;
}
