/**
* WorkQueue.cpp
* ProducerConsumer2
*
* Created by Anastasiia Egorova on 2020-03-16
*
* I certify that this work is solely my own and complies with
* NBCC Academic Integrity Policy (policy 1111)
*
* DESCRIPTION
* Initialization of WorkQueue functions 
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

#include "WorkQueue.h"

WorkQueue::WorkQueue()
{
}

void WorkQueue::push(int n)
{
	std::lock_guard<std::mutex> guard(mtx);
	jobs.push_back(n);
}

int WorkQueue::pop()
{
	//not here
	//std::lock_guard<std::mutex> guard(mtx);

	while (true) {

		mtx.lock();
		//critical section
		if (jobs.size() == 0) {
			mtx.unlock();
			//end critical section

			std::this_thread::yield();
		}
		//critical section
		else {
			int r = jobs.front();
			jobs.pop_front();
			mtx.unlock();
			//end critical section
			return r;
		}
	}
}

int WorkQueue::size()
{
	std::lock_guard<std::mutex> guard(mtx);
	return jobs.size();
}
