#include "minefield.h"

Minefield::Minefield(const bool hasMine)
                     : hasMine_(hasMine)
{
    isLocked_ = false;
    isVisited_ = false;
    noOfNeighbouringMines_ = 0;
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
