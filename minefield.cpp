#include "minefield.h"
#include <cstdlib>

Minefield::Minefield()
{
    isLocked_ = false;
    isVisited_ = false;
    noOfNeighbouringMines_ = 0;

    int randomNumber = std::rand() % 2;
    if (randomNumber == 0)
    {
        hasMine_ = false;
    }
    else
    {
        hasMine_ = true;
    }
}

void Minefield::setHasMine(const bool hasMine)
{
   hasMine_ = hasMine;
}

bool Minefield::hasMine() const
{
    return hasMine_;
}

bool Minefield::isLocked() const
{
    return isLocked_;
}

bool Minefield::isVisited() const
{
    return isVisited_;
}

int Minefield::noOfNeighbouringMines() const
{
    return noOfNeighbouringMines_;
}
