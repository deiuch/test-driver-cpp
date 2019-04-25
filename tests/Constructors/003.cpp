class Z
{
 public:
  int j;
  bool flag;

  Z() : Z(5) {}

  explicit Z(int n) : Z(n, false) {}

  Z(int n, bool b) : j(n), flag(b) {}
};

int main() {
  Z z;
}

