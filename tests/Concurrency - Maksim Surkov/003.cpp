//basic threads working
#include <cassert>
#include <thread>
#include <mutex>

using namespace std::literals::chrono_literals;

int main()
{
	std::string a = "";
	std::mutex m;
	auto fun = [&](std::string part)
	{
		m.lock();
		std::this_thread::sleep_for(1s);
		for(int i=0;i<10;++i)
			a += part;
		m.unlock();
	};
	std::thread th1(fun, "a");
	std::this_thread::sleep_for(1ms);
	std::thread th2(fun, "b");
	std::this_thread::sleep_for(1ms);
	std::thread th3(fun, "c");
	std::this_thread::sleep_for(1ms);
	th1.join(); th2.join(); th3.join();

	assert(a == "aaaaaaaaaabbbbbbbbbbcccccccccc");
}
