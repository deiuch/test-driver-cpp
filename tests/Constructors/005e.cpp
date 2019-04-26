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
  using Base::Base;
  explicit Derived(int x) : Base(1) { this->a = x; }
};

int main() {

  // Call with parameter set to 5. Test override of constructor
  Derived d1(5);
  assert(d1.a == 1);
}