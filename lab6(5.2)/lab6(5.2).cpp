

#include <fstream>
#include <string>
#include "Header.h"

int main()
{
	std::ifstream fin;
	std::ofstream fout;
	std::string text, sentence;
	fin.open("input.txt");
	fout.open("output.txt");
	while (std::getline(fin, sentence)) {
		text += sentence;
		text.push_back(' ');
	}
	std::string words = get_words(text);
	fout << words;
	fin.close();
	fout.close();
	return 0;
}



