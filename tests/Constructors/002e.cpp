class C {
 public:

  // cyclic constructors
  C() : C(12) {}

  C(int i) : C() {}
};

int main() {
  C c(5);
}

