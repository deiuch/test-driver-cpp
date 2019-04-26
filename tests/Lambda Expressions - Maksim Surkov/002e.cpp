// no implicit capture

int main()
{
    int a = 0;
    auto fun = [](){return a;};
    return fun();
}