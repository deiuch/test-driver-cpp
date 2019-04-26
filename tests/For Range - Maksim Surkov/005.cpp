//structured binding c++17

#include <cassert>
#include <vector>
#include <tuple>

auto a = {
    std::make_tuple(1,2),
    std::make_tuple(3,4),
    std::make_tuple(5,6)};

int main()
{
    int result_a = 0;
    int result_b = 0;
    for (auto [first, second] : a)
    {
        result_a+=first;
        result_b+=second;
    }
    assert(result_a == 9);
    assert(result_b == 12);
}