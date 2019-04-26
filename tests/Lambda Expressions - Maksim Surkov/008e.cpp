// const capture

#include <cassert>
#include <utility>

int main()
{   
    int a = 7;
    int result = [&b = std::as_const(a)]() { return ++b;}();
    assert(result == 7);
}