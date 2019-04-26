// pass as function

#include <functional>

template<typename T>
T call(std::function<T(void)> fun)
{
    return fun();
}

int main()
{
    std::function<int(void)> lambda = []() -> int {return 5 - 5;};
    return call(lambda);
}