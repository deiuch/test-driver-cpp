
//Author: Egor Ivkov
//rvalue assignment to non const reference
struct A {
public:
	int check() const {
		return 0;
	}
};

int main()
{
	A a;
	A& aref = A();
	return aref.check();
}