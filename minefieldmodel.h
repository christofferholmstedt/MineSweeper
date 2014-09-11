#ifndef MINEFIELDMODEL_H
#define MINEFIELDMODEL_H

#include <QAbstractListModel>

#include "minefield.h"
#include "lib/grid.h"

class MinefieldModel : public QAbstractTableModel
{
    Q_OBJECT
    Q_PROPERTY(int noOfMinefields READ noOfMinefields NOTIFY noOfMinefieldsChanged)

public:
    explicit MinefieldModel(QObject *parent = 0, const int rows = 3, const int columns = 3);

    enum MinefieldRoles {
        HasMineRole = Qt::UserRole + 1,
        IsVisitedRole,
        IsLockedRole,
        NoOfNeighbouringMinesRole,
    };

//    void addMinefield(const Minefield &minefield);

    int rowCount(const QModelIndex &parent = QModelIndex()) const;

    int columnCount(const QModelIndex &parent = QModelIndex()) const;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

    int noOfMinefields() const;
signals:
    void noOfMinefieldsChanged();

public slots:

protected:
    QHash<int, QByteArray> roleNames() const;

private:
    void resize(const int rows, const int columns);

    int noOfMinefields_;
    Grid::Grid<Minefield> minefields_;
    // std::vector<std::vector<Minefield> > minefields_;
    // QList<Minefield> minefields_;
};

#endif // MINEFIELDMODEL_H
