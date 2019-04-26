/**
  @file 006.cpp

  @brief Negative testing of constexpr constructor declarations.

  @author Bulat Khabirov
*/

#include <string>

// class with non-literal properties but constexpr constructor
class Rectangle {
    int h, w;
    std::string name;
public:
    // A constexpr constructor
    constexpr Rectangle (int h, int w) : h(h), w(w) {}

    constexpr int getArea ()  { return h * w; }
};

// constexpr constructor that does not initialize all members
class Rectangle2 {
    int h, w;
public:
    // A constexpr constructor
    constexpr Rectangle2 (int h) : h(h) {}

    constexpr int getArea ()  { return h * w; }
};

int main() {
    constexpr Rectangle rect(10, 20);
    constexpr Rectangle2 rect2(10);

    return 0;
}
