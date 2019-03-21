/**
 * Test for basic behavior of 'delete' specifier
 * Should not compile
 * 
 * Done by Turenko Dmitry
*/
int test_delete_behavior() {
    class C {
    public:
        C() = delete;
    };

    C c;
    
    return 0;
}

int main() {
    return test_delete_behavior();
}