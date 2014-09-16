#ifndef SQUARE_H
#define SQUARE_H

class Square
{
public:
    Square();
    Square(const int squareIndex);

    int getSquareIndex() const;
    void setSquareIndex(const int squareIndex);

private:
    int squareIndex_;

};

#endif // SQUARE_H
