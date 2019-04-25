//Author: Egor Ivkov
//lvalue assignment to rvalue reference 
struct A {
public:
	int check() const {
		return 0;
	}
};

int main()
{
	A a;
	A&& aref = a;
	return aref.check();
}