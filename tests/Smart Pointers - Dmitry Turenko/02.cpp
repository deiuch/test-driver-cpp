/**
 * Test for verifying that unique ptr will destroy 
 * underlying object, when scope will end
 * 
 * Done by Turenko Dmitry
*/
#include <memory>
#include <vector>
#include <iostream>

int C_exists;

int test_smp_scope() {
    C_exists = 0;
    class C {
    public:
        C() { C_exists++; };
        ~C() { C_exists--; }
    };

    {
        std::unique_ptr<std::vector<C>> unique = std::make_unique<std::vector<C>>(5);
    }
    return C_exists;
}

int main() {
    return test_smp_scope();
}