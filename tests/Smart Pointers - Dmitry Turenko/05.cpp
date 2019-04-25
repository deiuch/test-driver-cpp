/**
 * Test for move operatrion for unique_ptr
 * 
 * Done by Turenko Dmitry
*/
#include <memory>
#include <iostream>

int test_unique_move() {
    std::unique_ptr<int> v = std::make_unique<int>(5);
    std::shared_ptr<int> s { std::move(v) };
    return !(v == nullptr);
}

int main() {
    return test_unique_move();
}