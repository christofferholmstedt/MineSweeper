#include "boardmodel.h"
#include <QDebug>

BoardModel::BoardModel(Board * board) :
    QAbstractListModel(), board_(board)
{
}

/**
 * @brief BoardModel::squareCount
 * @return Total number of squares in the underlying data structure.
 */
int BoardModel::squareCount() const
{
    return board_->size();
}

/**
 * @brief BoardModel::rowCount
 * @param parent = 0
 * @return Number of rows which is number of squares as this is modeled as a list and not table.
 */
int BoardModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return squareCount();
}

/**
 * @brief BoardModel::columnCount
 * @param parent
 * @return Number of columns in the underlying data structure
 */
int BoardModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return board_->columnSize();
}

/**
 * @brief BoardModel::roleNames
 * @return The different roles (columns) made available in the view
 */
QHash<int, QByteArray> BoardModel::roleNames() const
{
    QHash<int, QByteArray> roles;
        roles[Number] = "number";
    return roles;
}

/**
 * @brief BoardModel::data
 * @param index
 * @param role
 * @return The proper role (column) value for specific index requested from the view.
 */
QVariant BoardModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole)
        return QVariant();

    if (role == Number)
    {
        return board_->getSquare(indexToRow(index.row()),indexToColumn(index.row()))->getSquareNumber();
    }
    return QVariant();
}

/**
 * @brief BoardModel::indexToRow
 * @param index
 * @return Row index in underlying data structure when given index from the view
 *
 * To adhere to the QAbstractListModel interface BoardModel::rowCount() doesn't
 * give actual row count in the underlying structure but the total number of
 * squares in the underlying data structure.
 */
int BoardModel::indexToRow(const int index) const
{
    return floor(index / board_->rowSize());
}

/**
 * @brief BoardModel::indexToColumn
 * @param index
 * @return Column index in underlying data structure when given index from the view
 */
int BoardModel::indexToColumn(const int index) const
{
    return index % board_->columnSize();
}

