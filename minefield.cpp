#include "minefield.h"

Minefield::Minefield()
{
    hasMine_ = false;
    isLocked_ = false;
    isVisited_ = false;
    noOfNeighbouringMines_ = 0;
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
