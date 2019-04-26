/**
  @file 007.cpp

  @brief Testing of if-constexpr.

  @author Bulat Khabirov
*/

// old way
template<int  N>
constexpr int fibonacci() {return fibonacci<N-1>() + fibonacci<N-2>(); }
template<>
constexpr int fibonacci<1>() { return 1; }
template<>
constexpr int fibonacci<0>() { return 0; }

// new way via if-constexpr
template<int N>
constexpr int fibonacciNew()
{
    if constexpr (N>=2)
        return fibonacci<N-1>() + fibonacci<N-2>();
    else
        return N;
}

int main() {
    static_assert(fibonacci<3>() == fibonacciNew<3>());
    return 0;
}
