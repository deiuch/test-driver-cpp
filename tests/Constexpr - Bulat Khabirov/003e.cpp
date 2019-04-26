/**
  @file 003e.cpp

  @brief Negative testing of constexpr function declarations.

  @author Bulat Khabirov
*/

#include <string>

int x = 5;
constexpr int sum(int a, int b) {
    // reading a non-constant
    if (x == 5)
        return a + b;
    return a + b;
}

// another way to pass a non const
constexpr void twice(int &a) {
    a *= 2;
    return;
}

// throw keyword in constexpr function body
constexpr int throwExcept() noexcept(false) {
    throw 1; // though try-catch is now allowed in c++20, we may not throw
    return 0;
}

// declaration of uninitialized varible in constexpr function body
constexpr int uninitializedDefinitions() {
    int x;
    return 0;
}

// stateful function
constexpr int nextX() {
    static int x = -1;

    x++;
    return x;
}

// non-literal arguments
constexpr bool isInnopolis(std::string str) {
    return str == "Innopolis";
}

// non-literal variable declarations
constexpr bool declareStrAndReturnTrue() {
    std::string str = "test";
    return true;
}

int getFive() { return 5; }
// constexpr function using a simple function
constexpr int sumFive(int a) { return getFive() + a; }

int main() {
    static_assert(sum(3, 2) == 5);
    static_assert(uninitializedDefinitions() == 0);
    static_assert(throwExcept() == 0);
    static_assert(nextX() == 0);
    static_assert(sumFive(1) == 6);
    static_assert(isInnopolis("Innopolis"));
    static_assert(declareStrAndReturnTrue());

    int x = 5;
    twice(x);
    static_assert(x == 10);

    return 0;
}
