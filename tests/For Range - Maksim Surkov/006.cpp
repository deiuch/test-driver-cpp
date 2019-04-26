//deconst

#include <cassert>
#include <vector>

int a[]{1,1,1};

int main()
{
	for (const int& val : a)
		++const_cast<int&>(val);
	assert(a[0] == 2);

}