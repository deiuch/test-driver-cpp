// mismatched binding
#include <cassert>
#include <functional>

int fun(int a, int b, int c)
{
    return a*100 + b*10 + c;;
}

int main()
{
    auto binded = std::bind(fun, 1);
    int result = binded(2, 3);
    assert(result == 123);
}