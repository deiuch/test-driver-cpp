/**
 * Test final specifier on nonvirtual function
 * Nonvirtual functions cannot be declared as final
 * Done by Eduard Zalyaev
*/

struct A
{
	virtual int foo() { return -1; }
	int boo() final { return 2020; }
};


int main()
{
	A a = A();
	return !(a.boo() == 2020 && a.foo()==-1);
}