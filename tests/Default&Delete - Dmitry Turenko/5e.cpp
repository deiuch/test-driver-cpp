/**
 * Test for restrict instantiation with convertible types
 * 
 * Done by Turenko Dmitry
*/

template<typename T>
int f(T) = delete;
int f(int x) { return x * x + 1; }

int test_prohibit_some_template_inst() {
    int t = 5;
    f(t);
    f(double(t));
    return 0;
}

int main() {
    return test_prohibit_some_template_inst();
}