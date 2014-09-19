#ifndef SQUARE_H
#define SQUARE_H

class Square
{
public:
    Square();
    Square(const int squareIndex);

    int getSquareIndex() const;
    int getNoOfMines() const;
    bool getHasMine() const;
    bool getIsVisited() const;
    bool getIsLocked() const;

    void setIsVisited(const bool value);
    void setSquareIndex(const int squareIndex);
    void setIsLocked(const bool value);
    void setNoOfMines(const int noOfMines);
    void addOneMine();

private:
    int squareIndex_;
    int noOfMines_;
    bool hasMine_;
    bool isVisited_;
    bool isLocked_;

};

#endif // SQUARE_H
