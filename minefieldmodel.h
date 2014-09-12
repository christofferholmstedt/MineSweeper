#ifndef MINEFIELDMODEL_H
#define MINEFIELDMODEL_H

#include <QAbstractListModel>

#include "minefield.h"

class MinefieldModel : public QAbstractTableModel
{
    Q_OBJECT
    Q_PROPERTY(int noOfMinefields READ noOfMinefields NOTIFY noOfMinefieldsChanged)

public:
    explicit MinefieldModel(const int rows, const int columns);
    // explicit MinefieldModel(QObject *parent = 0, const int rows = 3, const int columns = 3);

    enum MinefieldRoles {
        HasMineRole = Qt::UserRole + 1,
        IsVisitedRole,
        IsLockedRole,
        NoOfNeighbouringMinesRole,
    };

//  void addMinefield(const Minefield &minefield);
//    void MinefieldModel::addMinefield(const std::vector<Minefield> &minefields);

    void resize(const int rows, const int columns);
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    void debugContent() const;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

    int noOfMinefields() const;

signals:
    void noOfMinefieldsChanged();

public slots:

protected:
    QHash<int, QByteArray> roleNames() const;

private:

    int noOfMinefields_;
    std::vector<std::vector<Minefield> > minefields_;

    // QList<Minefield> minefields_;
    // Grid::Grid<Minefield> minefields_;
};

#endif // MINEFIELDMODEL_H
