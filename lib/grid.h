#ifndef GRID_H
#define GRID_H

// Some notes
// Using int instead of size_t. This is so type conversion/cast is not
// necessary when using together with QAbstract(Item|List|Table)Model in Qt 5.

namespace Grid {

    template <typename T> class Grid
    {
    public:
        Grid();
        Grid(int rows, int cols);

        T at(const int rows, const int cols) const;
        T& operator=(const T &other);
        int size() const;
        int columnSize() const;
        int rowSize() const;


    private:
        std::vector<std::vector<T>> rows_;

    };


    template <typename T> T& Grid<T>::operator=(const T &other)
    {
        return other;
    }


    template <typename T> Grid<T>::Grid(int rows, int cols)
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
               rows_.at(i).at(j) = T();
            }
        }
    }

    template <typename T> T Grid<T>::at(const int rows, const int cols) const
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
               return rows_.at(i).at(j);
            }
        }
    }

    template <typename T>  int Grid<T>::columnSize() const
    {
        if (!rows_.empty())
        {
            return rows_[0].size();
        }
        return 0;
    }

    template <typename T>  int Grid<T>::rowSize() const
    {
        return rows_.size();
    }

    template <typename T>  int Grid<T>::size() const
    {
        // If the Grid can have different number of columns it's not a grid anymore so
        // this is per definition strange.
        // If there are always the same amount of rows and same amount of columns
        // it easier just to multiply those values.
        // int total = 0;
        //    for (std::vector<T>::iterator row = rows_.begin(); row != rows_.end(); ++row)
        //    {
        //        for (std::vector<T>::iterator column = *row.begin(); column != *row.end(); ++column)
        //        {
        //            total++;
        //        }
        //    }

        return rowSize() * columnSize();
    }

}
#endif // GRID_H
