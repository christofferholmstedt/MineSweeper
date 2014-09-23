#include <cstdlib>

#include "square.h"
#include <QDebug>

Square::Square()
{
    squareIndex_ = -1;
    isVisited_ = false;
    isLocked_ = false;
    noOfMines_ = 0;

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

bool Square::getIsVisited() const
{
    return isVisited_;
}

void Square::setIsVisited(const bool value)
{
    isVisited_ = value;
}

bool Square::getIsLocked() const
{
    return isLocked_;
}

void Square::setIsLocked(const bool value)
{
    isLocked_ = value;
}

int Square::getNoOfMines() const
{
    return noOfMines_;
}

void Square::setNoOfMines(const int noOfMines)
{
    noOfMines_ = noOfMines;
}

void Square::addOneMine()
{
    noOfMines_ = noOfMines_ + 1;
}
