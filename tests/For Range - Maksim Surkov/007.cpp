// modification in usage

#include <cassert>
#include <vector>

std::vector<int> a{1};

int main()
{
	for (auto val : a)
		a.push_back(val);
	assert(a.size() == 2);
}