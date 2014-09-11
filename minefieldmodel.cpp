#include "minefieldmodel.h"

MinefieldModel::MinefieldModel(QObject *parent, const int rows, const int columns) :
    QAbstractTableModel(parent)
{
    this->resize(rows, columns);
}

void MinefieldModel::resize(const int rows, const int columns)
{
    minefields_ = Grid::Grid<Minefield>(rows, columns);
}

//void MinefieldModel::addMinefield(const Minefield &minefield)
//{
//     beginInsertRows(QModelIndex(), rowCount(), rowCount());
//    // Overload the << operator (same as set function).
//    minefields_ << minefield;
//    endInsertRows();
//}

int MinefieldModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return minefields_.rowSize();
}

int MinefieldModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return minefields_.columnSize();
}

int MinefieldModel::noOfMinefields() const
{
    return minefields_.size();
}

QVariant MinefieldModel::data(const QModelIndex &index, int role) const
{
//    if (role == Qt::DisplayRole)
//    {
//        // minefields_.get(x,y) needs to be implemented.
//        // return minefields_.at(index.row(),index.column());
//    }
//    if (index.row() < 0 || index.row() >= minefields_.count())
//        return QVariant();

    ;

    if (role == HasMineRole)
    {
        return minefields_.at(index.row(),index.column()).hasMine();
    }
    else if (role == IsVisitedRole)
    {
        return minefields_.at(index.row(),index.column()).isVisited();
    }
    else if (role == IsLockedRole)
    {
        return minefields_.at(index.row(),index.column()).isLocked();
    }
    else if (role == NoOfNeighbouringMinesRole)
    {
        return minefields_.at(index.row(),index.column()).noOfNeighbouringMines();
    }
    return QVariant();
}

QHash<int, QByteArray> MinefieldModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[HasMineRole] = "hasMine";
    roles[IsVisitedRole] = "isVisited";
    roles[IsLockedRole] = "isLocked";
    roles[NoOfNeighbouringMinesRole] = "noOfNeighbouringMines";
    return roles;
}
