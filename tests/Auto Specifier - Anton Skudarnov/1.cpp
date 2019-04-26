#include <typeinfo>

auto f() {
	return 1;
}

int main()
{
	f();
	if (typeid(f()) == typeid(1)) {
		return 0;
	}
	return 1;
}