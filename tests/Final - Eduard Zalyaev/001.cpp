/**
 * Test covers basic final specifier for a virtual function 
 * 
 * Done by Eduard Zalyaev
*/

struct A
{
	virtual int foo() {return -1;}
};

struct B : A
{
	int foo() final { return 42;}
};

int main()
{
	B b = B();
	return !(b.foo() == 42);
}