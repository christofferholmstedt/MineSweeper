#include "minefieldmodel.h"
#include <iostream>

MinefieldModel::MinefieldModel(QObject *parent, const int rows, const int columns) :
    QAbstractTableModel(parent)
{
    for (int i = 0; i < rows; i++)
    {
        std::vector<Minefield> tempVec;

        for (int j = 0; j < columns; j++)
        {
            Minefield tempMinefield;
            tempVec.push_back(tempMinefield);
        }
        this->minefields_.push_back(tempVec);
    }
}
//void MinefieldModel::addMinefield(const std::vector<Minefield> &minefields)
//{
//     beginInsertRows(QModelIndex(), rowCount(), rowCount());
//    // Overload the << operator (same as set function).
//    minefields_.push_back(minefields);
//    endInsertRows();
//}

int MinefieldModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    std::cout << "rowCount: " << minefields_.size() << std::endl;
    return minefields_.size();
}

int MinefieldModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    std::cout << "columnCount: " << minefields_.at(0).size() << std::endl;
    return minefields_.at(0).size();
}

int MinefieldModel::noOfMinefields() const
{
    std::cout << "cols: " << columnCount() << " rows: " << rowCount() << std::endl;
    return this->columnCount() * this->rowCount();
}

void MinefieldModel::debugContent() const
{
    for (int i = 0; i < rowCount(); i++)
    {
        for (int j = 0; j < columnCount(); j++)
        {
            std::cout << minefields_.at(i).at(j).hasMine();
        }
         std::cout << std::endl;
    }
}

QVariant MinefieldModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole)
        return QVariant();

//     if (index.row() < 0 || index.row() >= int(minefields_.size()))
//        return QVariant();


    std::cout << "x: " << index.row() << " y: " << index.column() << std::endl;

    if (role == HasMineRole)
    {
        return minefields_[index.row()][index.column()].hasMine();
    }
    else if (role == IsVisitedRole)
    {
        return minefields_[index.row()][index.column()].isVisited();
    }
    else if (role == IsLockedRole)
    {
        return minefields_[index.row()][index.column()].isLocked();
    }
    else if (role == NoOfNeighbouringMinesRole)
    {
        return minefields_[index.row()][index.column()].noOfNeighbouringMines();
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
