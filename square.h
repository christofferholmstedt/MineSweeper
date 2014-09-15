#ifndef SQUARE_H
#define SQUARE_H

class Square
{
public:
    Square();
    Square(const int squareNumber);

    int getSquareNumber() const;
    void setSquareNumber(const int squareNumber);

private:
    int squareNumber_;
};

#endif // SQUARE_H
