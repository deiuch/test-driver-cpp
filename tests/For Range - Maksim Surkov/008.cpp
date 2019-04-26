// custom ranges

#include <cassert>
#include <algorithm>

class CustomArray
{
    int *data;
    int size;
public:
    CustomArray(int size, int def):size(size)
    {
        data = new int[size];
        std::fill_n(data, size, def);
    }
    int* begin()
    {
        return &data[0]; // first
    }
    int* end()
    {
        return &data[size]; // one past the last
    }
};

int main()
{
    CustomArray ca(10, 3);
    int result = 0;
    for(auto val : ca)
        result+=val;
    assert(result == 30);
}