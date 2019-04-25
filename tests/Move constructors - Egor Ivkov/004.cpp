//Author: Egor Ivkov
//move constructor has higher priority than copy const constructor for rvalue references

#include <string>

class A {
private:
	std::string data;
public:
	bool moveCtorCalled;
	A(const std::string& data) : data(data), moveCtorCalled(false) {}
	A(A&& other) : data(std::move(other.data)), moveCtorCalled(true) {}
	A(const A& a) : data(a.data), moveCtorCalled(false) {}
	std::string getData() const {
		return data;
	}
};

int main()
{
	std::string data = "data";
	A a(data);
	A b(std::move(a));
	return b.moveCtorCalled ? 0 : 1;
}