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

QVariant MinefieldModel::data(const QModelIndex &index, int role) const
{
    if (index.row() < 0 || index.row() >= minefields_.count())
        return QVariant();

    const Minefield &minefield = minefields_[index.row()];

    if (role == TypeRole)
    {
        return minefield.type();
    }
    else if (role == SizeRole)
    {
        return minefield.size();
    }
    return QVariant();
}

QHash<int, QByteArray> MinefieldModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[TypeRole] = "type";
    roles[SizeRole] = "size";
    return roles;
}
