/**
 * Test for swap operation between two shared pointers and reset
 * 
 * Done by Turenko Dmitry
*/
#include <memory>

int test_() {
    std::shared_ptr<int> s1(new int(5));
    std::shared_ptr<int> s2(new int(7));
    int *init_s1 = s1.get(), *init_s2 = s2.get();

    s1.swap(s2);
    if (init_s1 != s2.get() || init_s2 != s1.get()) return 1;

    s1.reset();
    if (s1 != nullptr || init_s1 != s2.get()) return 1;

    return 0;
}

int main() {
    return test_();
}