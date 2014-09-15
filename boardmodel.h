#ifndef BOARDMODEL_H
#define BOARDMODEL_H

#include <QAbstractItemModel>
#include "board.h"

class BoardModel : public QAbstractTableModel
{
    Q_OBJECT
    Q_PROPERTY(int squareCount READ squareCount NOTIFY squareCountChanged())
    Q_PROPERTY(int columnCount READ columnCount NOTIFY columnCountChanged())
    Q_PROPERTY(int rowCount READ rowCount NOTIFY rowCountChanged())

public:
    explicit BoardModel(Board * board);

    int squareCount() const;
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

    enum MinefieldRoles {
        Number = Qt::UserRole + 1
    };

signals:
    void squareCountChanged();
    void columnCountChanged();
    void rowCountChanged();

public slots:

protected:
     QHash<int, QByteArray> roleNames() const;

private:
    Board * board_;
};

#endif // BOARDMODEL_H
