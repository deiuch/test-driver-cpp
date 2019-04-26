// capture by value/ref

#include <cassert>

int main()
{
    double d = 5.5;
    int i = 2;
    [&d,&i]() { ++d;++i;}();
    assert(d==6.5 && i == 3);

    [&](){ ++d; ++i;}();
    assert(d==7.5 && i==4);

}