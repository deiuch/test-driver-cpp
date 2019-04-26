// no bind args
#include <cassert>
#include <functional>

int fun()
{
    return 5;
}

int main()
{
    auto binded = std::bind(fun);
    int result = binded();
    assert(result == 5);
}