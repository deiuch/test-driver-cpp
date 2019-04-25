//Author: Egor Ivkov
//no move constructor is generated as copy constructor is present (same would be for copy assignment, destructor and move assignment)

#include <string>

class A {
private:
	std::string data;
public:
	A(const std::string& data) : data(data) {};
	//A(A&& other) : data(std::move(other.data)) {}
	A(A& a) : data(a.data) {}
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