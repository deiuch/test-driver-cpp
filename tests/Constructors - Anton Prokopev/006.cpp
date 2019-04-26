#include <assert.h>

class Base {
 public:
  int a;
  bool f;

  explicit Base(int value) : a(value), f(false) {}
  Base(int value, bool flag) : a(value), f(flag) {}
};

class Derived : public Base {
 public:
  explicit Derived(int x) : Base(1) { this->a = x; }
};

int main() {

  // Call not existed constructor
  Derived d1(5), d2(12, true);
}