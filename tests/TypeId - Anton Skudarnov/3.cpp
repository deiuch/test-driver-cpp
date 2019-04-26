
#include <typeinfo>
class A {};

class B :A {};

class D {};

class C :A, D {};


int main()
{
	A a;
	B b;
	C c;
	D d;

	if (typeid(a) == typeid(b) && typeid(b) == typeid(c) && typeid(c) == typeid(d)) {
		return 1;
	}

	return 0;
}
