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
	auto r1 = foo(l);
	auto r2 = foo2(l);
	auto r3 = foo3(l);
	auto r4 = foo(l);

	if (typeid(r1) == typeid(int) && typeid(r2) == typeid(int) &&
		typeid(r3) == typeid(int) && typeid(r4) == typeid(int)) 
	{
		return 1;
	}
	return 0;
}