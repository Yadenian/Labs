#include <string>
#include "set.h"
#include "Header.h"

std::string get_words(std::string text)
{
	std::string words, word;
	Set<std::string> ordered_strings;
	bool isWord = false;
	for (int i = 0; i < text.size(); ++i) {
		while ((text[i] > 64 && text[i] < 91) || (text[i] > 96 && text[i] < 123)) {
			word += text[i];
			isWord = true;
			++i;
		}
		if (isWord) {
			ordered_strings.insert(word);
			isWord = false;
			word.clear();
		}
	}
	for (auto it = ordered_strings.begin(); it != ordered_strings.end(); ++it) {
		if (is_need_word(*it)) {
			words += *it;
			words.push_back(' ');
		}
	}
	if (is_need_word(*ordered_strings.end())) {
		words += *ordered_strings.end();
		words.push_back(' ');
	}
	return words;
}

bool is_need_word(std::string word)
{
	if (word.size() < 3)
		return false;
	int counter = 0;
	for (int i = 0; i < word.size(); ++i) {
		switch (word[i])
		{
		case 'A':
			++counter;
			break;

		case 'a':
			++counter;
			break;

		case 'E':
			++counter;
			break;

		case 'e':
			++counter;
			break;

		case 'I':
			++counter;
			break;

		case 'i':
			++counter;
			break;

		case 'O':
			++counter;
			break;

		case 'o':
			++counter;
			break;

		case 'U':
			++counter;
			break;

		case 'u':
			++counter;
			break;

		case 'Y':
			++counter;
			break;

		case 'y':
			++counter;
			break;
		}
		if (counter == 3)
			return true;
	}
	return false;
}