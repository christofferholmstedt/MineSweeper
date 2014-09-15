#ifndef SQUARE_H
#define SQUARE_H

class Square
{
public:
    Square();
    Square(const int number);

    int getNumber() const;
    void setNumber(const int number);
//    Square clone();

private:
    int number_;
};

#endif // SQUARE_H
