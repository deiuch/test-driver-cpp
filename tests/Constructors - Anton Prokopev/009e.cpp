#include <assert.h>


class Q {
 public:
  Q(Q &q) = delete;
  Q(int i) {};
};


int main() {

  Q q1(1);
  Q q2(q1);
}