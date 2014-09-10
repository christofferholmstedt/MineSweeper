#ifndef MINEFIELDMODEL_H
#define MINEFIELDMODEL_H

#include <QAbstractListModel>

#include "minefield.h"

class MinefieldModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(int noOfMinefields READ noOfMinefields NOTIFY noOfMinefieldsChanged)

public:
    explicit MinefieldModel(QObject *parent = 0);

    enum MinefieldRoles {
        HasMineRole = Qt::UserRole + 1,
        IsVisitedRole,
        IsLockedRole,
        NoOfNeighbouringMinesRole,
    };

    void addMinefield(const Minefield &minefield);

    int rowCount(const QModelIndex &parent = QModelIndex()) const;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

    int noOfMinefields() const;
signals:
    void noOfMinefieldsChanged();

public slots:

protected:
    QHash<int, QByteArray> roleNames() const;

private:
    QList<Minefield> minefields_;
};

#endif // MINEFIELDMODEL_H
