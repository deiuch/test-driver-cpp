auto f() {

}


int main()
{	
	if (typeid(f()) == typeid(void)) {
		return 0;
	}
	return 1;
}
