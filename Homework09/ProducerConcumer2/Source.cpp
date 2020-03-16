/**
* Source.cpp
* ProducerConsumer2
*
* Created by Anastasiia Egorova on 2020-03-16
*
* I certify that this work is solely my own and complies with
* NBCC Academic Integrity Policy (policy 1111)
*
* DESCRIPTION
* main() function for Producer Consumer Homework
*
*  Copyright 2020
*  Permission to use, copy, modify, and/or distribute this software for
*  any purpose with or without fee is hereby granted, provided that the
*  above copyright notice and this permission notice appear in all copies.
*
*  THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
*  WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
*  MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
*  ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
*  WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
*  ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
*  OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*
*
*/

#include <iostream>
#include "WorkQueue.h"
#include <ctime>
#include <cstdlib>
#include <thread>
#include <vector>
#include <atomic>
#include <mutex>
#include <chrono>

std::atomic<bool> make_work = true;
WorkQueue jobs;
std::mutex cout_mutex;

void producer(int i) {
	while (make_work) {
		int r = rand() % 100;
		jobs.push(r);

		cout_mutex.lock();
		std::cout << "Producer " << i << " posted " << r << std::endl;
		cout_mutex.unlock();
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}

}

void consumer(int i) {
	if (make_work) {
		std::this_thread::yield();
	}
	else {
		while (jobs.size() > 0) {
			int n = jobs.pop();
			int sz = jobs.size();

			cout_mutex.lock();
			std::cout << sz << " Worker " << i << " performed " << n << std::endl;
			cout_mutex.unlock();
		}
	}
}

int main() {
	srand(time(0));

	std::vector<std::thread> producers;
	std::vector<std::thread> consumers;

	for (int i = 0; i < 5; ++i) {
		producers.push_back(std::thread(producer, i));
	}

	std::cin.get();												//producers stop to produce only after user press enter
	make_work = false;

	for (int i = 0; i < 3; ++i) {
		consumers.push_back(std::thread(consumer, i));
	}

	for (auto& t : producers) {
		t.join();
	}

	for (auto& t : consumers) {
		t.join();
	}

	std::cout << "\n\n" << jobs.size() << std::endl;
}