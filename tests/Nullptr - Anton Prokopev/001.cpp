#include <cstddef>

class C {
};

int main() {
  std::nullptr_t ptr;
  C *c = ptr;
}