// rvalue iter

#include <cassert>
#include <initializer_list>

int main()
{
	int result = 0;
	for (auto& val : {1,2,3,4,5})
		result += ++val;
	assert(result == 15);
}