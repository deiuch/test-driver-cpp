// multiple captures

struct b
{
    void a()
    {
        int i = 0;
        [i, i] {}; // error
        [this, *this] {};
    }
};

int main()
{
    b some{};
    some.a();
}