/**
 * Test compile type variadic tuple template instantiation
 * and getter function
 * Done by Eduard Zalyaev
*/
template<typename...Args>
struct Tuple;

template<typename Head, typename...Tail>
struct Tuple <Head, Tail...> : Tuple<Tail...> 
{ 
	Tuple(Head h, Tail ...tail) : Tuple<Tail ... >(tail...), head(h) { };
	typedef Tuple<Tail...> base_type; 
	typedef Head value_type; 
	base_type& base = static_cast<base_type&>(*this); 
	Head head;
};

template<>
struct Tuple<> { };

//Using struct wrappers in order to be able to define partial specializations
template<int N, typename Head, typename ...Tail>
struct getter
{
	typedef typename getter<N - 1, Tail...>::return_type return_type; //Get return type from recursive template call
	static return_type get(Tuple<Head, Tail...> t)
	{
		return getter<N - 1, Tail...>::get(t);
	}
};

template<typename Head, typename ...Tail>
struct getter<0, Head, Tail...>  //Base case for template recursion
{
	typedef typename Tuple<Head, Tail...>::value_type return_type;
	static return_type get(Tuple<Head, Tail...> t)
	{
		return t.head;
	}
};

template<int N, typename Head, typename... Tail>
typename getter<N, Head, Tail...>::return_type
get(Tuple<Head, Tail...> t)//Function wrapper for convenience
{
	return getter<N, Head, Tail...>::get(t);
}

int main()
{
	Tuple<int, char, bool> a(1, 'X', false);
	return !(get<0>(a)==1 && get<1>(a) =='X' && get<2>(a) == false);
}
