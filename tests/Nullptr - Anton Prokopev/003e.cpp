#include <cstddef>

void f(int *i) {}
void f(double *i) {}
void f(int i) {}

// Ambiguous call
int main() {
  f(nullptr);
}