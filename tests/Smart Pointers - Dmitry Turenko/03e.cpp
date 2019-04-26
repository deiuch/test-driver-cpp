/**
 * Test for reassignment of unique_ptr
 * 
 * Done by Turenko Dmitry
*/
#include <memory>

void test_reassign_unique() {
    std::unique_ptr<int> v = std::make_unique<int>(10);
    std::unique_ptr<int> v_copy(v);
}