/**
 * Test for move semantics of unique_ptr
 * 
 * Done by Turenko Dmitry
*/
#include <memory>

int test_unique_ptr_move() {
    std::unique_ptr<int> v = std::make_unique<int>(5);
    std::unique_ptr<int> v_copy = std::move(v);
    return !(!v && *v_copy == 5);
}

int main() {
    return test_unique_ptr_move();
}