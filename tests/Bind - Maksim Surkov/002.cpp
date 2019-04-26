// check bind placeholders
#include <cassert>
#include <functional>

using namespace std::placeholders;

int fun(int a, int b, int c)
{
    return a*100 + b*10 + c;
}

int main()
{
    auto binded = std::bind(fun, _3, _2, _1);
    int result = binded(1,2,3);
    assert(result == 321);
}