/**
 * Test nested template packs
 *
 * "A parameter pack whose name appears within the pattern of a pack expansion is expanded
 * by that packexpansion. An appearance of the name of a parameter pack is only expanded by 
 * the innermost enclosingpack expansion. The pattern of a pack expansion shall name one or more parameter
 * packs that are notexpanded by a nested pack expansion. All of the parameter packs expanded by a pack expansion 
 * shall havethe same number of arguments specified"
 *
 * Done by Eduard Zalyaev
*/
#include <iostream>
template<typename ...args1>
struct A1 {
	template<typename ...args2 >
	struct A2
	{
		static void printer(args1 ...a1, args2 ...a2)
		{
			((std::cout << a1 << " "), ...);
			((std::cout << a2 << " "), ...);
		}
	};

};


int main()
{
	A1<char*, char*, char*, char*>::A2<char*, char*, char*, char*>::printer("I", "A", "M", "B", "O", "R", "E", "D");
	A1<char*>::A2<char*, char*>::printer("W", "O", "W");
	
	return 0;
}