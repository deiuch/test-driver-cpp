/**
 * Test for loop condition of conextualy convertible expression using templates
 * A is contextually convertible since bool op is defined
 * Done by Eduard Zalyaev
*/
template<typename T> struct A
{
	operator bool();
};

struct B
{
	operator bool()
	{
		return false;
	}
};

template<>
A<int>::operator bool() { return B(); }

int main()
{
	A<int> a = A<int>();
	for (;a;) return 1;
	return 0;
}

