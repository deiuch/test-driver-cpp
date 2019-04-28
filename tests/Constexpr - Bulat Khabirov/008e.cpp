/**
  @file 008e.cpp

  @brief Testing infinite recursion in constexpr.

  @author Bulat Khabirov
*/

// infinite recursion
constexpr int getInt() {
    return getInt();
}

// should compile
// but crash in runtime
int main() {
    int x = getInt();
    return 0;
}
