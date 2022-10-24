#include <iostream>
#include <vector>

class get_sum
{
public:
    get_sum(std::vector<int> &_tmp) : tmp(_tmp) {}
    void operator()()
    {
        for (auto elm : tmp)
            sum += elm;
        std::cout << "[OUT]: get_sum() = " << sum << std::endl;
    }

private:
    int sum = 0;
    std::vector<int> &tmp;
};

class get_count
{
public:
    get_count(std::vector<int> &_tmp) : tmp(_tmp) {};
    void operator()()
    {
        for (auto elm : tmp)
            if (elm % 3 == 0)
                ++count;
        std::cout << "[OUT]: get_count() = " << count << std::endl;
    }

private:
    int count = 0;
    std::vector<int> &tmp;
};

int main(int argc, char **argv)
{
    std::vector<int> tmp{4, 1, 3, 6, 25, 54};

    std::cout << "[IN]: ";
    for (auto elm : tmp)
        std::cout << elm << " ";
    std::cout << std::endl;

    (get_sum(tmp))();
    (get_count(tmp))();

    return 0;
}