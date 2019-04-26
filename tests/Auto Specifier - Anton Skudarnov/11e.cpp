
#include <list>
#include <iostream>


int foo(std::list<int>& l)
{
	return l.front();
}

int& foo2(std::list<int>& l)
{
	return l.front();
}

const int foo3(std::list<int>& l)
{
	return l.front();
}

const int& foo4(std::list<int>& l) {
	return l.front();
}

int main()
{
	std::list<int> l = { 1,2,3 };
	auto& r1 = foo(l); //initial value to non const must be an lvalue  //cannot convert from 'int' to 'int &'
	auto& r2 = foo2(l);
	auto& r3 = foo3(l); //initial value to non const must be an lvalue  //cannot convert from 'int' to 'int &'
	auto& r4 = foo4(l);

	if (typeid(r1) == typeid(int) && typeid(r2) == typeid(int) &&
		typeid(r3) == typeid(int) && typeid(r4) == typeid(int))
	{
		return 1;
	}
	return 0;
}
