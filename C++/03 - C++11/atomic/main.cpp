
#include <iostream>
#include <thread>
#include <atomic>

using namespace std;

atomic<int> x = 0;
atomic<int> y = 0;

void writing() {

	this_thread::sleep_for(chrono::milliseconds(1));
	x.store(2000);
	y.store(11);

}

void reading() {

	cout << "y:" << y.load() << " ";
	cout << "x:" << x.load() << endl;

}

int main() {

	thread t1(writing);
	t1.join();

	thread t2(reading);
	t2.join();

	system("pause");

}