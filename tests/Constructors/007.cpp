#include <assert.h>


class X {
 public:
  int a = 3;

  X() {}
};


int main() {

  X x;
  assert(x.a == 3);
}