/**
  @file 005.cpp

  @brief Positive testing of constexpr constructor declarations.

  @author Bulat Khabirov
*/

//  A class with constexpr constructor and function
class Rectangle {
    int h, w;
public:
    // A constexpr constructor
    constexpr Rectangle (int h, int w) : h(h), w(w) {}

    constexpr int getArea ()  { return h * w; }
};

//  driver program to test function
int main() {
    constexpr Rectangle rect(10, 20);
    int rectArea = rect.getArea();
    assert(rectArea == 10*20);

    return 0;
}
