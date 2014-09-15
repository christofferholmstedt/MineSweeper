#include "square.h"

Square::Square()
{
    number_ = 42;
}

Square::Square(const int number) :
    number_(number)
{
}

int Square::getNumber() const
{
    return number_;
}

void Square::setNumber(const int number)
{
    number_ = number;
}

//Square Square::clone()
//{

//}
