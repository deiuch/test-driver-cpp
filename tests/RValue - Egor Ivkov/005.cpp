//Author: Egor Ivkov
//taking rvalue reference of a lvalue transformed to rvalue
struct A {
public:
	int check() const {
		return 0;
	}
};

int main()
{
	A a;
	A&& aref = std::move(a);
	return aref.check();
}
