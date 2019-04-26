/**
 * Test for variadic template definition:
 * "Template parameter pack is a template parameter that accepts zero or more template arguments."
 * Done by Eduard Zalyaev
*/

template<typename ...Args>
struct Tester {};

int main()
{
	Tester<> a;
	Tester<int> b;
	Tester<int, float> c;
	Tester<0> d; //0 is not a type
	return 0;
}	