/**
 * Test defines basic usage of `override` identifier
 * 
 * Test should compile and return 0 in correct scenario
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