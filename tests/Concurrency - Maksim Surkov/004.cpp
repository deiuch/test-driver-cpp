//basic threads working
#include <cassert>
#include <thread>
#include <future>

using namespace std::literals::chrono_literals;

void completer(std::promise<int>* prom)
{
	std::this_thread::sleep_for(1s);
	prom->set_value(5);
}

int main()
{
	std::promise<int> p;
	std::future<int> f = p.get_future();
	std::thread th(completer, &p);
	assert(f.get() == 5);
	th.join();

}
