#include "minefieldmodel.h"

MinefieldModel::MinefieldModel(QObject *parent) :
    QAbstractTableModel(parent)
{
   this->minefields_(3,3);
}

//void MinefieldModel::addMinefield(const Minefield &minefield)
//{
//    beginInsertRows(QModelIndex(), rowCount(), rowCount());
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
    if (role == Qt::DisplayRole)
    {
        // minefields_.get(x,y) needs to be implemented.
        return minefields_[index.row()][index.column()];
    }
//    if (index.row() < 0 || index.row() >= minefields_.count())
//        return QVariant();

//    const Minefield &minefield = minefields_[index.row()];

//    if (role == HasMineRole)
//    {
//        return minefield.hasMine();
//    }
//    else if (role == IsVisitedRole)
//    {
//        return minefield.isVisited();
//    }
//    else if (role == IsLockedRole)
//    {
//        return minefield.isLocked();
//    }
//    else if (role == NoOfNeighbouringMinesRole)
//    {
//        return minefield.noOfNeighbouringMines();
//    }
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
