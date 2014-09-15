#ifndef BOARDMODEL_H
#define BOARDMODEL_H

#include <QAbstractItemModel>
#include "board.h"

class BoardModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit BoardModel(Board * board);

    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

    enum MinefieldRoles {
        Number = Qt::UserRole + 1
    };

signals:

public slots:

protected:
     QHash<int, QByteArray> roleNames() const;

private:
    Board * board_;
};

#endif // BOARDMODEL_H
