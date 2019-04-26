#include <cstdint>
#include <iostream>
using typeid_t = uintptr_t;

template <typename T>
constexpr typeid_t type_id() noexcept
{
	return typeid_t(type_id<T>);
}

int main()
{
	::std::cout << ::std::integral_constant<typeid_t, type_id<float>()>{} << ::std::endl;

	return 0;
}