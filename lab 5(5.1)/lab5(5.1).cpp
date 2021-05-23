

#include <iostream>
#include <queue>
#include "mylib.h"

int main()
{
	int f_size;
	int s_size;
	int value;
	std::priority_queue<int> f_queue;
	std::priority_queue<int> s_queue;
	std::cout << "Enter the size of the first queue : ";
	std::cin >> f_size;
	std::cout << "Enter the first queue : ";
	for (int i = 0; i < f_size; ++i) {
		std::cin >> value;
		f_queue.push(value);
	}
	std::cout << "Enter the size of the second queue : ";
	std::cin >> s_size;
	std::cout << "Enter the second queue : ";
	for (int i = 0; i < s_size; ++i) {
		std::cin >> value;
		f_queue.push(value);
	}
	std::priority_queue<int> edit_queue = edit(f_queue, s_queue);
	print(edit_queue);
	return 0;
}


