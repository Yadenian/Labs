#include <fstream>
#include <string>
#include <cassert>
#include "Header.h"

void test()
{
	std::ifstream fin;
	std::string text;
	std::string sentence;
	fin.open("test.txt");
	while (std::getline(fin, sentence)) {
		text += sentence;
		text.push_back(' ');
	}
	std::string words = get_words(text);
	std::string test_words = "disgrace pained quickly subdued young ";
	assert(test_words == words);	
}

#undef main

int main()
{
	test();
	return 0;
}
