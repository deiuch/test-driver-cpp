#include <cstddef>
#include <type_traits>
#include <assert.h>

int main() {
  assert(std::is_null_pointer<decltype(nullptr)>::value);
  int v = std::is_null_pointer<int*>::value;
  assert(!v);

  v = std::is_pointer<decltype(nullptr)>::value;
  assert(!v);
}