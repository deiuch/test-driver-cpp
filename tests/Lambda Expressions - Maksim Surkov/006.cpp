// value captured parameters mutability
#include <cassert>

int main()
{
    int value = 5;
    auto mutab = [value](int add) mutable {value+=add;return value;};

    int res = mutab(2);
    assert(value == 5 && res == 7);
}