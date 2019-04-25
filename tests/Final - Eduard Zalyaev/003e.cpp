/**
 * Test overriding of the final functions
 * Final functions cannot be overriden
 * Done by Eduard Zalyaev
*/

struct A
{
	virtual int foo() { return -1; }
};

struct B : A
{
	int foo() final { return 42; }
};

struct C :B
{
	int foo() override { return 24; }
};

int main()
{
	B b = B();
	C c = C();
	return !(b.foo() == 42 && c.foo() == 24);
}