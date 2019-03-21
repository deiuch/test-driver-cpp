/**
 * Test for deleting candidate function for specific type
 * 
 * Done by Turenko Dmitry
*/
int test_prohibit_type() {
    class C {
    public:
        int make_action(int x) { return x * x; }
        int make_action(double x) = delete;
    };

    C c;
    int a = 5;
    c.make_action(a);
    double d = 5.5;
    c.make_action(d);

    return 0;
}

int main() {
    return test_prohibit_type();
}