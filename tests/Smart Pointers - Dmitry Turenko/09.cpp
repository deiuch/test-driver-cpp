/**
 * Test for checking work of polymorphism with uniqiue_ptr
 *
 * Done by Turenko Dmitry
 */
#include <memory>

struct Base {
    virtual int f() { return 0; }
    virtual ~Base() {}
};

struct Derived : Base {
    int f() override { return 1; }
    ~Derived() final {}
};

int test_poly() {
    std::unique_ptr<Base> b1 = std::make_unique<Base>();
    std::unique_ptr<Base> b2 = std::make_unique<Derived>();
    return !(b1->f() == 0 && b2->f() == 1);
}

int main() { return test_poly(); }