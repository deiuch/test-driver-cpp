// anonymous usage
//wrong return type
auto fun = []() -> auto {return 1; return "string"; return true;};

int main()
{
    return fun();
}