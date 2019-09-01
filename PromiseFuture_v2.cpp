#include <iostream>
#include <thread>
#include <mutex>
#include <future>

using namespace std;


void f1(promise<int>& prom)
{
	cout << "Setting promise here.." << endl;
	prom.set_value(678);
	cout << "thread 1 exited" << endl;
}

int main()
{
	promise<int> prom;
	future<int> fut = prom.get_future();
	thread t1 = thread(f1, ref(prom));

	cout << "Received from thread: " << fut.get() << endl;

	if (t1.joinable())
		t1.join();

	return 0;
}