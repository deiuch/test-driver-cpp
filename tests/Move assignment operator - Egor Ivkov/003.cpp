//Author: Egor Ivkov
//copy assignment is used instead of move in its absence

#include <string>

struct A
{
	bool copyAssignSucceded;
	std::string s;
	A() : s("test") { }
	A(const A& o) : s(o.s), copyAssignSucceded(false) {}
	A(A&& o) : s(std::move(o.s)) { }
	A& operator=(const A& other)
	{
		copyAssignSucceded = true;
		s = other.s;
		return *this;
	}
};

A f(A a) { return a; }

int main()
{
	A a1, a2;
	a1 = std::move(a2);
	return a1.copyAssignSucceded ? 0 : 1;
}