#include <iostream>
#include <exception>

template <class T>
class Row
{
public:
    Row() = default;

    Row(size_t _cellsQ) : row(new T[_cellsQ]()), cellsQ(_cellsQ) {}

    Row(const Row &other) = delete;

    ~Row() { delete[] row; }

    T &operator[](size_t index)
    {
        if (index >= cellsQ)
        {
            throw std::runtime_error("Wrong index for column!");
        }
        return row[index];
    }

    Row &operator=(const Row &other) = default;

private:
    T *row = nullptr;
    size_t cellsQ{0};
};

template <class T>
class Table
{
public:
    Table() = default;

    Table(size_t _rowsQ, size_t _colsQ)
    {
        if (_rowsQ == 0 || _colsQ == 0)
        {
            throw std::runtime_error("Wrong inputs. Input numbers should be positive.");
        }
        else
        {
            rowsQ = _rowsQ;
            colsQ = _colsQ;
            tab = new Row<T>[rowsQ];
            for (size_t i = 0; i < rowsQ; ++i)
            {
                tab[i] = Row<T>(colsQ);
            }
        }
    }

    Table(const Table &other) = default;

    ~Table()
    {
        delete[] tab;
    }

    Row<T> &operator[](size_t index)
    {
        if (index >= rowsQ)
        {
            throw std::runtime_error("Wrong index for row!");
        }
        return tab[index];
    }

    Table &operator=(const Table &other) = default;

    void size() const
    {
        std::cout << "Table contains " << rowsQ << " row(s) and " << colsQ << " collumn(s)." << std::endl;
    }

private:
    Row<T> *tab = nullptr;
    size_t rowsQ{0};
    size_t colsQ{0};
};

int main(int argc, char **argv)
{
    try
    {
        auto test = Table<int>(1, 2);
        test[0][0] = 4;
        std::cout << test[0][0] << std::endl;
        test.size();

        return 0;
    }
    catch (const std::runtime_error &e)
    {
        std::cout << e.what() << std::endl;
    }
}