#ifndef MINEFIELDMODEL_H
#define MINEFIELDMODEL_H

#include <QAbstractListModel>

#include "minefield.h"

class MinefieldModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit MinefieldModel(QObject *parent = 0);

    enum MinefieldRoles {
        TypeRole = Qt::UserRole + 1,
        SizeRole
    };

    void addMinefield(const Minefield &minefield);

    int rowCount(const QModelIndex &parent = QModelIndex()) const;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

signals:

public slots:

protected:
    QHash<int, QByteArray> roleNames() const;

private:
    QList<Minefield> minefields_;
};

#endif // MINEFIELDMODEL_H
