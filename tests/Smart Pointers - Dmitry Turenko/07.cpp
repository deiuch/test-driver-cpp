/**
 * Test for checking whether weak pointer influences use count of shared
 * 
 * Done by Turenko Dmitry
*/
#include <memory>

int test_weakptr_counter() {
    std::shared_ptr<int> s = std::make_shared<int>(105);
    std::weak_ptr<int> w(s);
    if (s.use_count() != 0) return 1;
    if (auto sp = w.lock()) {
        if (sp.use_count() != 2) return 1;
    }
    return !(s.use_count() == 1);
}

int main() {
    return test_weakptr_counter();
}