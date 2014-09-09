#include "minefield.h"

Minefield::Minefield(const QString &type, const QString &size)
    : type_(type), size_(size)
{

}

QString Minefield::type() const
{
    return type_;
}

QString Minefield::size() const
{
    return size_;
}
