#include <assert.h>

class Q {
 public:
  Q() = delete;
  explicit Q(int i) {}
};

// Delete inherited constructor and restore it with custom ctr
class QDerived : Q {
 public:
  QDerived(): Q(1) {};
};

int main() {
  QDerived q1;
}