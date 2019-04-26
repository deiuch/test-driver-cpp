/**
  @file 001.cpp

  @brief Testing valid constexpr variable declarations.

  @author Bulat Khabirov
*/

/// Literal type
class A {
public:
    int m;
    constexpr A(const int x): m(x) {}
};

// valid constexpr variable declarations that should be compile-time evaluated
static constexpr int const& staticInt = 100;
constexpr char constLetter = 'a';
constexpr A customLiteralType = A(5);

/// Template constants should be constexpr, because templates
template<int n>
struct constN
{
    /// For testing purposes, will fail to compile when n != 5
    int getN() {
        static_assert(n == 5);
        return n;
    }
};

int main() {
    // using static_assert to ensure compile-time evaluation
    static_assert(staticInt == 100);
    static_assert(constLetter == 'a');
    static_assert(customLiteralType.m == 5);

    constN<5> constTemplate;
    constTemplate.getN();

    return 0;
}
