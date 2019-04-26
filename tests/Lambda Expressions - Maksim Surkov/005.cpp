// this capture ref/val

#include <cassert>
#include <functional>

struct My
{
    int def = 15;
    std::function<int(int)> fun = [this](int add){return this->def+=add;};
};

int main()
{
    My my{};
    int res1 = my.fun(5);
    assert(my.def == 20);
}