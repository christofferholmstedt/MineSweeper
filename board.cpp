#include "board.h"
#include <QDebug>

Board::Board(const int rows, const int columns)
{
    resize(rows, columns);
}

void Board::resize(const int rows, const int columns)
{
    grid_.resize(rows, columns);

    int counter = 0;
    for (int i = 0; i < rows; i++)
    {
       for (int j = 0; j < columns; j++)
       {
          grid_.getSquare(i, j)->setSquareIndex(counter);
          counter++;
       }
    }

    updateNoOfMines();
    newGame();
}

void Board::newGame()
{
    isGameOver_ = false;
}

void Board::updateNoOfMines()
{
    for (int i = 0; i < rowSize(); i++)
    {
        for (int j = 0; j < columnSize(); j++)
        {
            // Top corner
            if (j < (columnSize() - 1))
            {
                // Square to the right of current square
                if (grid_.getSquare(i, j + 1)->getHasMine())
                {
                    grid_.getSquare(i, j)->addOneMine();
                }
            }
            // Square down-right of the current square
            if (i < (rowSize() - 1) &&
                j < (columnSize() - 1))
            {
                if (grid_.getSquare(i + 1, j + 1)->getHasMine())
                {
                    grid_.getSquare(i, j)->addOneMine();
                }
            }
            // Square top-right of the current square
            if (i > 0 &&
                j < (columnSize() - 1))
            {
                if (grid_.getSquare(i - 1, j + 1)->getHasMine())
                {
                    grid_.getSquare(i, j)->addOneMine();
                }

            }
            // Square top of the current square
            if (i > 0)
            {
                if (grid_.getSquare(i - 1, j)->getHasMine())
                {
                    grid_.getSquare(i, j)->addOneMine();
                }

            }
            // Square bottom of the current square
            if (i < (rowSize() - 1))
            {
                if (grid_.getSquare(i + 1, j)->getHasMine())
                {
                    grid_.getSquare(i, j)->addOneMine();
                }

            }
            // Square bottom-left of the current square
            if (i < (rowSize() - 1) &&
                j > 0)
            {
                if (grid_.getSquare(i + 1, j - 1)->getHasMine())
                {
                    grid_.getSquare(i, j)->addOneMine();
                }

            }
            // Square left of the current square
            if (j > 0)
            {
                if (grid_.getSquare(i, j - 1)->getHasMine())
                {
                    grid_.getSquare(i, j)->addOneMine();
                }

            }
            // Square top-left of the current square
            if (i > 0 &&
                j > 0)
            {
                if (grid_.getSquare(i - 1, j - 1)->getHasMine())
                {
                    grid_.getSquare(i, j)->addOneMine();
                }

            }
        }
    }

}

void Board::setIsGameOver(bool value)
{
    isGameOver_ = value;
}

bool Board::getIsGameOver() const
{
    return isGameOver_;
}

int Board::size() const
{
    return grid_.size();
}

int Board::rowSize() const
{
    return grid_.rowSize();
}

int Board::columnSize() const
{
    return grid_.columnSize();
}

Square * Board::getSquare(const int row, const int column)
{
    return grid_.getSquare(row, column);
}
