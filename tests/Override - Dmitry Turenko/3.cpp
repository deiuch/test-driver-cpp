/**
 * Test defines usage of `override` identifier in romb-like
 * dependency diagram
 * 
 * Test should compile and return 0 in correct scenario
*/

struct B {
    virtual int foo() {
        return 125;
    }
};

struct D: B {
    int foo() override {
        return 75;
    }
};

struct C: B {
    int foo() override {
        return 105;
    }
};

struct F: D, C {
    int foo() override {
        return 17;
    }
};

int main() {
    B b; D d; C c; F f;
    return !(b.foo() == 125 && d.foo() == 75 && c.foo() == 105 && f.foo() == 17);
}