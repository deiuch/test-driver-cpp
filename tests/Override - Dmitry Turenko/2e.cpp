/**
 * Test defines error detection with `override` identifier
 * 
 * Test should not compile
*/
struct B {
    virtual int foo() {
        return 125;
    }
};

struct D: B {
    virtual long foo() override {
        return 75;
    }
};

int main() {
    B b; D d;
    b.foo();
    d.foo();
    return 0;
}