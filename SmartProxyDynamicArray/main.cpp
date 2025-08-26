
#include <iostream>
#include <thread>
#include <chrono>

#include "DynamicArray.h"
#include "SyncDynamicArray.h"
SyncDynamicArray<int> data{ 1,2,3,4,5 };

void AddData(std::size_t count) {
	using namespace std::chrono_literals;
	for (int i = 0; i < count; ++i) {
		std::this_thread::sleep_for(1ms);
		data.Add(i);
	}
}

int main() {
	std::thread t1{ AddData, 10 };
	std::thread t2{ AddData, 10 };
	t1.join();
	t2.join();
	for (int i = 0; i < data.Size(); ++i) {
		std::cout << data[i] << ' ';
	}
}

