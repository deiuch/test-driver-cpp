/**
 * Test defines basic usage of `override` identifier
 * 
 * Done by Turenko Dmitry
*/
struct B {
    virtual int foo() { return 125; }
};

struct D : B {
    virtual int foo() override { return 75; }
};

int test_override() {
    B b; D d;
    return !(b.foo() == 125 && d.foo() == 75);
}

int main() {
    return test_override();
}