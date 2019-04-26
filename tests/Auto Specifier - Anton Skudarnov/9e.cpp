#include <iostream>

constexpr auto auto() {
	return 1;
}

typedef decltype(auto()) auto;
const auto auto = auto();

template<typename auto>
constexpr auto auto() {
	return auto;
}

template <typename auto, typename auto, typename... auto>
constexpr auto auto() {
	return auto + auto<auto, auto...>();
}

int main() {
	constexpr auto auto = auto<auto, auto, auto, auto, auto, auto>();
	constexpr auto auto = auto<auto, auto, auto, auto, auto, auto, auto>();
	return auto * auto;
}