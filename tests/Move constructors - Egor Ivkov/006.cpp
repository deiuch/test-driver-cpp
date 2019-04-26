//Author: Egor Ivkov
//move const constructor (strange ctor) - can't move contents from one class to another, they stay in both

#include <string>

class A {
private:
	std::string data;
public:
	A(const std::string& data) : data(data) {};
	A(const A&& other) : data(std::move(other.data)) {}

	std::string getData() const {
		return data;
	}
};

int main()
{
	std::string data = "data";
	A a(data);
	A b(std::move(a));
	return (a.getData() == data) && (b.getData() == data) ? 0 : 1;
}