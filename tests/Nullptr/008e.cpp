#include <cstddef>

template<class F, class A>
void fwd(F f, A a) {
  f(a);
}

void g(int i) {
}

int main() {
  g(NULL);
  g(nullptr);

  fwd(g, nullptr);
  //Not found g(long) or g(long int)
  fwd(g, NULL);
}