// using plain arrays

#include <cassert>

int *a = new int[5];

int main()
{
	int result = 0;
	for (int val : a)
		result += val;
	assert(result == 15);
}
