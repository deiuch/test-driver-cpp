//auto with reference

#include <cassert>
#include <vector>

std::vector<int> a {1,1,1};

int main()
{
	for (auto val : a) // will it be ref of value?
		++val;
	assert(a[0] == 1); // val is correct

	for (auto& val : a)
		++val;
	
	assert(a[0] == 2);
}