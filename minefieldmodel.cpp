#include "minefieldmodel.h"

MinefieldModel::MinefieldModel(QObject *parent) :
    QAbstractListModel(parent)
{
}

void MinefieldModel::addMinefield(const Minefield &minefield)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    minefields_ << minefield;
    endInsertRows();
}

int MinefieldModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return minefields_.count();
}

int MinefieldModel::noOfMinefields() const
{
    return minefields_.count();
}

QVariant MinefieldModel::data(const QModelIndex &index, int role) const
{
    if (index.row() < 0 || index.row() >= minefields_.count())
        return QVariant();

    const Minefield &minefield = minefields_[index.row()];

    if (role == HasMineRole)
    {
        return minefield.hasMine();
    }
    else if (role == IsVisitedRole)
    {
        return minefield.isVisited();
    }
    else if (role == IsLockedRole)
    {
        return minefield.isLocked();
    }
    else if (role == NoOfNeighbouringMinesRole)
    {
        return minefield.noOfNeighbouringMines();
    }
    // Start from here next time
    // This is probably wrong way of doing it.
    // how do I access number of items in model from qml?
    // http://qt-project.org/doc/qt-5/qml-qtqml-models-listmodel.html
    else if (role == NoOfRows)
    {
        return minefields_.count();
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
    roles[NoOfRows] = "noOfRows";
    return roles;
}