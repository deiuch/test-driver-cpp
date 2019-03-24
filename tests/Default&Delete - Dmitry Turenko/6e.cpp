/**
 * Test for restricting copy operator=
 * 
 * Done by Turenko Dmitry
*/
int test_restrict_operatot() {
    class C {
    public:
        C& operator= (const C&) = delete;     
    };

    C c1, c2;
    c2 = c1;
    
    return 0;
}

int main() {
    return 0;
}