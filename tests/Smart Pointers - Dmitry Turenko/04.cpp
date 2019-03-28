/**
 * Test for counter and uniqueness of shared pointers
 * 
 * Done by Turenko Dmitry
*/
#include <memory>

int test_shared_counter() {
    std::shared_ptr<int> v = std::make_shared<int>(15);
    if (!v.unique() || v.use_count() != 1) return 1;
    std::shared_ptr<int> t = v;
    return !(!v.unique() && v.use_count() == 2);
}

int main() {
    return test_shared_counter();
}