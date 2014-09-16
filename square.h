#ifndef SQUARE_H
#define SQUARE_H

class Square
{
public:
    Square();
    Square(const int squareIndex);

    int getSquareIndex() const;
    bool getHasMine() const;
    bool getIsVisited() const;

    void setIsVisited(const bool value);
    void setSquareIndex(const int squareIndex);

private:
    int squareIndex_;
    bool hasMine_;
    bool isVisited_;

};

#endif // SQUARE_H
