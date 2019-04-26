#include <assert.h>
#include <initializer_list>

class R {
 public:
  R(std::initializer_list<double> args) {
  };
};

int main() {
  R r({1, 2, 4.5});
}