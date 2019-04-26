// check basic bind functionality
#include <cassert>
#include <functional>

int fun(int a)
{
    return a;
}

int main()
{
    auto binded = std::bind(fun, 5);
    int result = binded();
    assert(result == 5);
}