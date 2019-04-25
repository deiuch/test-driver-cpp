//Author: Egor Ivkov
//rvalue assignment to rvalue reference 
struct A {
public:
	int check() const {
		return 0;
	}
};

int main()
{
	A a;
	A&& aref = A();
	return aref.check();
}