/**
 * Test final class inheritance.
 * Final classes cannot be derived from
 * Done by Eduard Zalyaev
*/

struct A final
{
	virtual int foo() { return -1; }
};

struct B : A
{
	int foo() final { return 42; }
};

int main()
{
	B b = B();
	return !(b.foo() == 42);
}