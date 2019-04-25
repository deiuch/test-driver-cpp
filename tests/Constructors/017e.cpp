#include <assert.h>
#include <initializer_list>

class R {
 public:
  R(std::initializer_list<double> args) {};
};

// Wrong parenthesis
int main() {
  R r = [1, 3, 5];
}