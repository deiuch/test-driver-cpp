/**
 * Test for basic support of all smart pointers
 * 
 * Done by Turenko Dmitry
*/
#include <memory>

class C { };

int test_smart_pointers_creation() {
    std::unique_ptr<C> unique(new C());
    std::shared_ptr<C> shared(new C());
    std::weak_ptr<C> weak(shared);

    std::unique_ptr<C> unique2 = std::make_unique<C>();
    std::shared_ptr<C> shared2 = std::make_shared<C>();
    std::weak_ptr<C> weak2 = shared2;
    return 0;
}

int main() {
    return test_smart_pointers_creation();
}