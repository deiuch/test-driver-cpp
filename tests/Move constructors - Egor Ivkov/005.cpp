//Author: Egor Ivkov
//moving class contents for non-class members - as you see it is not quite logical - int remains the same

#include <string>

class A {
private:
	int data;
public:
	A(int data) : data(data) {};
	A(A&& other) = default;

	int getData() const {
		return data;
	}
};

int main()
{
	int data = 10;
	A a(data);
	A b(std::move(a));

	return (a.getData() == 10) && (b.getData() == 10) ? 0 : 1;
}