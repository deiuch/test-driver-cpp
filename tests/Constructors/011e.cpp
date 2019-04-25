#include <assert.h>

class Q {
 public:
  Q() = delete;
};

// Delete inherited constructor and restore  with default ctr
class QDerived : Q {
 public:
  // The definition can be either remove or default
  QDerived() = default;
};

int main() {
  QDerived q1;
}