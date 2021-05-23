#pragma once

#include <queue>
#include <set>
#include <iostream>

template <typename T>
std::priority_queue<T> edit(std::priority_queue<T>& f_queue, std::priority_queue<T>& s_queue)
{
	std::set<T> s;
	std::priority_queue<T> new_queue;
	while (!f_queue.empty()) {
		s.insert(f_queue.top());
		f_queue.pop();
	}
	while (!s_queue.empty()) {
		s.insert(s_queue.top());
		s_queue.pop();
	}
	for (auto it : s) {
		new_queue.push(it);
	}
	return new_queue;
}

template <typename T>
void print(std::priority_queue<T> q)
{
	while (!q.empty()) {
		std::cout << q.top() << "\t";
		q.pop();
	}
}