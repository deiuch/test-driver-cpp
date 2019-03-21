/**
 * Test defines trial to override non-virtual function
 * 
 * Test should not compile
*/
struct B {
    int foo() {
        return 125;
    }
};

struct D: B {
    int foo() override {
        return 75;
    }
};

int main() {
    B b; D d;
    b.foo();
    d.foo();
    return 0;
}