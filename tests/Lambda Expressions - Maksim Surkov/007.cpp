// generic lambda

#include <cassert>

auto less_than = []<class T>(T a, auto&& b) { return a < b; };

int main()
{
    bool res = less_than(1,2);
    assert(res);
}