/**
 * Test for checking array creation using unique_ptr
 * 
 * Done by Turenko Dmitry
*/
#include <memory>

int test_unique_ptr_arr() {
    std::unique_ptr<int[]> arr(std::make_unique<int[]>(5));
    std::unique_ptr<int[]> arr2(new int[5]{1, 2, 3, 4, 5});
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        sum += arr2[i];
    }
    return !(sum == 15);
}

int main() {
    return test_unique_ptr_arr();
}