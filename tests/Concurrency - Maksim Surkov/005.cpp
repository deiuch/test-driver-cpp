//basic threads working
#include <cassert>
#include <algorithm>
#include <vector>
#include <execution>

int main()
{
	std::vector<int> a = { 3,1,4,2,5,6 };
	std::vector<int> b = { 3,1,4,2,5,6 };
	std::vector<int> c = { 3,1,4,2,5,6 };

	std::sort(std::execution::seq, a.begin(), a.end());
	std::sort(std::execution::par, b.begin(), b.end());
	std::sort(std::execution::par_unseq, c.begin(), c.end());

	assert(a == std::vector({ 1,2,3,4,5,6 }));
	assert(b == std::vector({ 1,2,3,4,5,6 }));
	assert(c == std::vector({ 1,2,3,4,5,6 }));
}
