class Base {
 public:
  int a;
  bool f;

  Base(int value) : a(value) {}
  Base(int value, bool flag) : a(value), f(flag) {}
};


//class Derived : public Base {
// public:
//  //constructor does nothing except forwarding to base constructor
//  Derived(int value) : Base(value) {}
//};

class Derived : public Base {
 public:
  using Base::Base;
};

int main() {

  Derived d1(1), d2(12, true);
}