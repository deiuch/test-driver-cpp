
#include <initializer_list>
#include <typeinfo>
int main()
{
	auto b = { 1,2 };

	if (typeid(b) == typeid(std::initializer_list<int>)) {
		return 0;
	}

	return 1;
}