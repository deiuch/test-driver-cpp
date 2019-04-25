/**
 * Test for what is inside empty smart pointer
 * 
 * Done by Turenko Dmitry
*/

#include <memory>
#include <iostream>

int test_unique_ptr_pass() {
    std::unique_ptr<int> x;
    return x != nullptr;
}

int main() {
    return test_unique_ptr_pass();
}