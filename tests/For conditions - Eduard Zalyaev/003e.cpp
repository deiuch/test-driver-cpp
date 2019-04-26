/**
 * Test short circuit evaluation at compile time
 * For condition has to be evaluated as false and a should not be evaluated
 * Done by Eduard Zalyaev
*/

struct A {};

int main()
{
	A a = A();
	for (; (false && a) ;) return 1;
	return 0;
}

