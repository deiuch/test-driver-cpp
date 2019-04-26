/**
 * Test for loop with convertible expression
 * No bool operator defined
 * Done by Eduard Zalyaev
*/

struct A{};

int main()
{
	for (; A a = A();) return 1;
	return 1;
}

