#ifndef MINEFIELD_H
#define MINEFIELD_H

#include <QString>

class Minefield
{
public:
    Minefield(const QString &type, const QString &size);

    QString type() const;
    QString size() const;

//    bool hasMine() const;
//    bool isLocked() const;
//    bool isVisited() const;

private:
    QString type_;
    QString size_;

};

#endif // MINEFIELD_H
