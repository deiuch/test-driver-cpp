/**
 * Test fold expressions
 *
 * Done by Eduard Zalyaev
*/
#include <iostream>
template<typename ...Args>
int sum(Args... args)
{
	int result = 0;
	return (result + ... + args);
}

template<typename ...Args>
int flusher(Args... args)
{
	std::cout << std::endl;
	(std::cout << ... << args); //No spaces
	std::cout << std::endl;
	((std::cout << args << " "), ...); //With spaces
	std::cout << std::endl;

	return 0;
}

template<typename ...Args>
int assign_sum(int& var,Args... args)
{
	(var += ... += args);
	return 0;
}



int main()
{
	int a = sum(1, 2, 3, 5, 6);
	
	int b = flusher(3, "a", 23.0);

	int c = 0;

	int d = assign_sum(c,24,32,15);
	std::cout << " asddsadas " <<a << " " << c << " " << d;
	return !(a == 17 && b==0 && c==71 && d == 0);
}