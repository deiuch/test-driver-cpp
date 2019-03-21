/**
 * Test for basic behavior of 'default' specifier
 * Should compile and return 0
 * 
 * Done by Turenko Dmitry
*/
int test_default_behavior() {
    class C {
    public:
        int x;
        C() = default;
        C(int x): x(x) {}
    };

    C c2;
    C c{5};
    c2 = c;
    
    return 0;
}

int main() {
    return test_default_behavior();
}