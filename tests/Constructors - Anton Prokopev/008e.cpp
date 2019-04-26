#include <assert.h>


class X {
 public:
  int a = 3;

  // More explicit initialization?
  X() : a(2) {}
};


int main() {

  X x;
  assert(x.a == 3);
}