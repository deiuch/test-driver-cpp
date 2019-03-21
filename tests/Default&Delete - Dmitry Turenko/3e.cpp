/**
 * Test for deleting inherited function
 * 
 * Done by Turenko Dmitry
*/
int test_delete_function() {
    class C {
    public:
        int f(int x) { return x * x; }
    };

    class D: C {
    public:
        int f(int x) = delete;
    };

    C c;
    c.f(10);
    D d;
    d.f(10);

    return 0;
}

int main() {
    return test_delete_function();
}