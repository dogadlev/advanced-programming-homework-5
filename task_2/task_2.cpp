#include <iostream>
#include <exception>

template <class T>
class Table
{
public:
    Table(unsigned int _rowNum, unsigned int _colNum)
    {
        if (_rowNum <= 0 || _colNum <= 0)
        {
            throw std::runtime_error("Wrong inputs! Input numbers should be positive.");
        }
        else
        {
            rowNum = _rowNum;
            colNum = _colNum;
            tab = new T *[rowNum];
            for (unsigned int i = 0; i < rowNum; ++i)
            {
                tab[i] = new T[colNum]();
            }
        }
    }

    ~Table()
    {
        for (unsigned int i = 0; i < rowNum; ++i)
        {
            delete[] tab[i];
        }
        delete[] tab;
    }

    T *operator[](unsigned int index)
    {
        if (index < 0 && index >= colNum)
        {
            throw std::runtime_error("Column index is out of range.");
        }
        else
        {
            return tab[index];
        }
    }

    T operator[](unsigned int index) const
    {
        if (index < 0 && index >= rowNum)
        {
            throw std::runtime_error("Row index is out of range.");
        }
        else
        {
            return (*tab)[index];
        }
    }

private:
    T **tab;
    unsigned int rowNum{0};
    unsigned int colNum{0};
};

int main(int argc, char **argv)
{
    try
    {
        Table<int> test(1, 2);
        test[0][0] = 4;
        test[0][1] = 5;
        std::cout << test[0][2];
        return 0;
    }
    catch (const std::runtime_error &e)
    {
        std::cout << e.what() << std::endl;
    }
}