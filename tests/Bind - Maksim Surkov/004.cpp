// binding again
#include <cassert>
#include <functional>

using namespace std::placeholders;

int fun(int a, int b, int c)
{
    return a*100 + b*10 + c;;
}

int main()
{
    auto binded = std::bind(fun, 1, _1, _2);
    int result = std::bind(binded, 2, 3)();
    assert(result == 123);
}