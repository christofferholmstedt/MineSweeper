#include "boardmodel.h"

BoardModel::BoardModel(Board * board) :
    QAbstractTableModel(), board_(board)
{
}

int BoardModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return board_->rowSize();
}

int BoardModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return board_->columnSize();
}

QVariant BoardModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole)
        return QVariant();

    if (role == Number)
    {
        return board_->getSquare(index.row(), index.column()).getSquareNumber();
    }
}

QHash<int, QByteArray> BoardModel::roleNames() const
{
    QHash<int, QByteArray> roles;
        roles[Number] = "number";
    return roles;
}
