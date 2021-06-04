#include "MarriageAgency.h"
#include <iostream>

void MarriageAgency::showPair(std::pair<People*, People*> pair) {
	std::cout << "===============PAIR===============" << std::endl;
	std::cout.setf(std::ios::left);
	std::cout.width(25);
	std::cout << "Man:" << "Woman:" << std::endl;
	std::cout.width(25);
	std::cout << ("Name: " + pair.first->name);
	std::cout << ("Name: " + pair.second->name) << std::endl;
	std::cout.width(25);
	std::cout << ("Second Name: " + pair.first->secondName);
	std::cout << ("Second Name: " + pair.second->secondName) << std::endl;
	std::cout.width(25);
	std::cout << ("Sity: " + pair.first->sity);
	std::cout << ("Sity: " + pair.second->sity);
	std::cout << std::endl;
}

bool MarriageAgency::checkSimilarity(const People& m, const People& w) {
	bool flag{ false };
	for (auto& i : m.requiredHobbies) {
		for (auto& j : w.hobbies) {
			if (i == j) {
				flag = true;
				break;
			}
		}
		if (!flag) return false;
	}

	for (auto& i : m.requiredBadHabbits) {
		for (auto& j : w.badHabbits) {
			if (i == j) return false;
		}
	}

	flag = false;
	for (auto& i : w.requiredHobbies) {
		for (auto& j : m.hobbies) {
			if (i == j) {
				flag = true;
				break;
			}
		}
		if (!flag) return false;
	}

	for (auto& i : w.requiredBadHabbits) {
		for (auto& j : m.badHabbits) {
			if (i == j) return false;
		}
	}

	return true;
}

size_t MarriageAgency::indexByNumber(uint16_t num, Sex sex) {
	size_t i{ 0 };
	if (sex == Sex::Man) {
		for (auto obj : men) {
			if (obj->number == num) break;
			++i;
		}
	}
	else {
		for (auto obj : women) {
			if (obj->number == num) break;
			++i;
		}
	}
	return i;
}

MarriageAgency::MarriageAgency() {}

void MarriageAgency::addPeople(People* people) {
	if (people->sex == Sex::Man) men.push_back(people);
	else women.push_back(people);
}

std::vector<std::pair<People*, People*>> MarriageAgency::showPossiblePairs() {
	std::vector<std::pair<People*, People*>> vec{};
	for (auto m : men) {
		for (auto w : women) {
			if (checkSimilarity(*m, *w)) {
				std::pair<People*, People*> tempPair{ m, w };
				showPair(tempPair);
				vec.push_back(tempPair);
			}
		}
	}
	return vec;
}

int MarriageAgency::makePair(uint16_t mansNumber, uint16_t womansNumber) {
	size_t i{ 0 };
	size_t j{ 0 };

	try {
		i = indexByNumber(mansNumber, Sex::Man);
		j = indexByNumber(womansNumber, Sex::Woman);
	}
	catch (std::string str) {
		std::cout << str;
		return -1;
	}

	archive.push_back(std::pair<People*, People*>{men[i], women[j]});
	men.erase(men.begin() + i);
	women.erase(women.begin() + j);
	return 0;
}

void MarriageAgency::deletePeople(uint16_t number, Sex sex) {
	size_t i{ indexByNumber(number, sex) };
	if (sex == Sex::Man) men.erase(men.begin() + i);
	else 	women.erase(women.begin() + i);
}