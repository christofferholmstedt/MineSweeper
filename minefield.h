#ifndef MINEFIELD_H
#define MINEFIELD_H

#include <QString>

class Minefield
{
public:
    Minefield();

    void setHasMine(const bool hasMine);
    bool hasMine() const;
    bool isLocked() const;
    bool isVisited() const;
    int noOfNeighbouringMines() const;

private:
    bool hasMine_;
    bool isLocked_;
    bool isVisited_;
    int noOfNeighbouringMines_;

};

#endif // MINEFIELD_H
