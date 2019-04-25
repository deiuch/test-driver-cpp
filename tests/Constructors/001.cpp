class T {
 public:
  T(double d) {}
};

class C {
  int s;
  T t;  //has a conversion operator to double

 public:

//the target constructor

  C(int i, T t1) : s(i), t(t1) {}

//three delegating ctors that call the target ctor

  C() : C(12, 4.5) {}

  C(int i) : C(i, 4.5) {}

  C(T &t1) : C(12, t1) {}

};

int main() {
  C c1= C();
  C c2 = C(2);
  T t(4.1);
  C c3 = C(t);
}


