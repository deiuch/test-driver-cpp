// termination is called
#include <thread>

void a()
{
    1; // something useless
}

int main()
{
    std::thread th1(a);
}
