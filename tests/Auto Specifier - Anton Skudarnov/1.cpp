#include <typeinfo>

/*
The typeid expression is lvalue expression which refers to an object with static storage duration, of the polymorphic type const std::type_info or of some type derived from it.

Because it is an lvalue expression, which uses reference initialization to declare an initializer of std::type_info. <typeinfo> contains the definition for that object.
*/


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


