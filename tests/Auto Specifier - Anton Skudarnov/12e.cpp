auto foo(auto v1, auto v2) -> decltype(v1 + v2);
int foo(auto v1, bool v2);



int main()
{
	foo(“C++ is cool ? ”, true);
}