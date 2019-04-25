
//Author: Egor Ivkov
//rvalue assignment to reference on const
struct A {
public:
	int check() const {
		return 0;
	}
};

int main()
{
	A a;
	const A& aref = A();
	return aref.check();
}