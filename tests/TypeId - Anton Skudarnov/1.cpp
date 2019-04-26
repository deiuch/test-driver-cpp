#include <list>
#include <iostream>



int& foo2(std::list<int>& l)
{
	return l.front();
}


int main()
{
	std::list<int> l = { 1,2,3 };

	int& r2 = foo2(l);

	if (typeid(r2) == typeid(int) && typeid(r2) == typeid(int&) && !std::is_same<int, int&>::value)
	{
		return 1;
	}
	return 0;
}
