/**
  @file 002e.cpp

  @brief Negative testing of constexpr variable declarations.

  @author Bulat Khabirov
*/

#include <string>

int getSomeInt() { return 5; }

// getSomeInt is not a constexpr
constexpr int five = getSomeInt();

// std::string is not a literal type
constexpr std::string str = "Hello!";

// not immediately initialized
constexpr int lazyFour;

int main() {
    static_assert(str == "Hello!");
    static_assert(five = 5);

    lazyFour = 4;
    static_assert(lazyFour == 4);

    return 0;
}
