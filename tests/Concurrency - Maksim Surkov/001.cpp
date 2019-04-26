//basic threads working
#include <thread>

void a(int a)
{
    a = a * a; // something useless
}

int main()
{
    std::thread th1(a, 1);
    std::thread th2(a, 2);
    th1.join();
    th2.detach();
    // no termination of program with error
}
