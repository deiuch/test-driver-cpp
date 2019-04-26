


const int&& foo() {
	return 1;
};
auto i = foo(); //  i будет иметь тип int
decltype(auto) i2 = foo(); //  i2 будет иметь тип const int&&

int main()
{


	if (typeid(i) == typeid(i2)) {
		return 1;
	}
