// init value c++20

#include <cassert>

int a[] = { 1,2,3,4,5 };

int main()
{
	int result = 0;
	[[likely]] for (int a[] = {2,2,2}; int val : a)
		result += val;
	assert(result == 6);
}