//Author: Egor Ivkov
//moving class contents in implicit move constructor

#include <string>

class A {
private:
	std::string data;
public:
	A(const std::string& data) : data(data) {};
	//A(A&& other) : data(std::move(other.data)) {}

	std::string getData() const {
		return data;
	}
};

int main()
{
	std::string data = "data";
	A a(data);
	A b(std::move(a));
	return (a.getData() == std::string("")) && (b.getData() == data) ? 0 : 1;
}