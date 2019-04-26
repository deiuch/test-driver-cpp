#include <iostream>
#include <typeinfo>


auto f() {
	return;
}

int main()
{
	std::cout << f(); //This will cause compile error because of the void type
	if (typeid(f()) == typeid(void)) {
		return 0;
	}
	return 1;
}
