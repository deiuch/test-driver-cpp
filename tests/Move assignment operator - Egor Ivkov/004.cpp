//Author: Egor Ivkov
//self move - possible

#include <string>

struct A
{
	bool moveAssignSucceded;
	std::string s;
	A() : s("test") { }
	A(const A& o) : s(o.s), moveAssignSucceded(false) {}
	A(A&& o) : s(std::move(o.s)) { }
	A& operator=(const A& other)
	{
		moveAssignSucceded = false;
		s = other.s;
		return *this;
	}
	A& operator=(A&& other)
	{
		s = std::move(other.s);
		moveAssignSucceded = true;
		return *this;
	}
};

A f(A a) { return a; }

int main()
{
	A a1, a2;
	a1 = std::move(a1);
	return a1.s == "test" && a1.moveAssignSucceded ? 0 : 1;
}