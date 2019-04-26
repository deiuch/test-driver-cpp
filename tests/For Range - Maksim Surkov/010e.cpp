//incorrect iter type

#include <cassert>

const int a[] = {1,2,3};

int main()
{
	int result = 0;
	for (int& val : a)
		result += val;
	assert(result == 15);
}