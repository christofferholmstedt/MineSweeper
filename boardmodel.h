#ifndef BOARDMODEL_H
#define BOARDMODEL_H

#include <QAbstractListModel>
#include "board.h"

class BoardModel : public QAbstractListModel
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

    enum BoardModelRoles {
        SquareIndex = Qt::UserRole + 1,
        HasMine,
        IsVisited,
        IsLocked,
        NoOfMines
    };

signals:
    void squareCountChanged();
    void columnCountChanged();
    void rowCountChanged();

public slots:
    void squareClickedSlot(const int index, const bool leftMouseButton);

protected:
     QHash<int, QByteArray> roleNames() const;

private:
    Board * board_;

    int indexToRow(const int index) const;
    int indexToColumn(const int index) const;
};

#endif // BOARDMODEL_H
