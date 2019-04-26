
#include <iostream>


//Check is it reference of value

int main()
{	
	auto v = { 1,2,3,4 };
	for (auto i : v) {
		if (typeid(int&) == typeid(i)) {
			return 0; //Yes it is
		}
		return 1;
	}
}