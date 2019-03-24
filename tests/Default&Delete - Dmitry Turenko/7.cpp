/**
 * Test defaulting default constructior outside of class definition
 * 
 * Done by Turenko Dmitry
*/

class Test { 
public:
    Test(); 
};

Test::Test() = default;

int test_outside_default() {
    Test t;
    return 0;
}

int main() {
    return test_outside_default();
}