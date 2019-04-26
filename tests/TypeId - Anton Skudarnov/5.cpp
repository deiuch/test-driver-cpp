#include <typeinfo>
int main()
{


	int i = 0;
	const int&& j = 1;
	const std::type_info& ti1 = typeid(i);
	const std::type_info& ti2 = typeid(j);

	if (ti1.hash_code() == ti2.hash_code()) { return 0; }

	return 1;
}