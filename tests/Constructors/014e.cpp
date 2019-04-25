#include <assert.h>
#include <initializer_list>

class R {
 public:
  R(std::initializer_list<double> args) {
  };
};

// Wrong type initialization
int main() {
  R r = {1, 2., 3, ""};
}