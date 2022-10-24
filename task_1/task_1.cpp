#include <iostream>
#include <vector>

template <class T>
void square(T &a)
{
    a *= a;
}

template <>
void square(std::vector<int> &vector)
{
    for (size_t i = 0; i < vector.size(); ++i)
        vector[i] *= vector[i];
}

void printVector(const std::vector<int> &vector)
{
    for (size_t i = 0; i < vector.size() - 1; ++i)
        std::cout << vector[i] << ", ";
    std::cout << vector[vector.size() - 1];
    std::cout << std::endl;
}

int main(int argc, char **argv)
{
    int a{4};
    std::cout << "[IN]: " << a << std::endl;
    square(a);
    std::cout << "[OUT]: " << a << std::endl;

    std::vector<int> vector{-1, 4, 8};
    std::cout << "[IN]: ";
    printVector(vector);
    square(vector);
    std::cout << "[OUT]: ";
    printVector(vector);

    return 0;
}