/**
  @file 004.cpp

  @brief Positive testing of constexpr function declarations.

  @author Bulat Khabirov
*/

// global constexpr function
constexpr int sum(int a, int b) {
    return a + b;
}

// constexpr function as a class member
class A {
public:
    constexpr int getFive() { return 5; }
};

// void is a literal type since c++17
void constexpr doSomething() {
    // do something ...
    return;
}

int main() {
    static_assert(sum(2, 2) == 4);
    static_assert(sum(3, 3) == 6);

    A a;
    static_assert(a.getFive() == 5);

    doSomething();

    return 0;
}
