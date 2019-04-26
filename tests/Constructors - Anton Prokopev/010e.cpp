#include <assert.h>


class Q {
 public:
  Q() = delete;
};

// Delete inherited constructor
class QDerived : Q {
};


int main() {
  QDerived q1;
}