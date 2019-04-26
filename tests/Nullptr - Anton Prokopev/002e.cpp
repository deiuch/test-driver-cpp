#include <cstddef>

class C {
};

int main() {
  std::nullptr_t ptr;
  C *c = new C();
  ptr = c;
}