#include "People.h"
#include <cstdarg>
#include <string>

void People::setBirthday(int day, int month, int year) {
	if (month > 12) throw "Unkorrect month";
	if (day > 31 || (day > 28 && month == 2)) throw "Unkorrect day";
	this->day = day;
	this->month = month;
	this->year = year;
}

People::People(std::string name,
	std::string secondName,
	uint16_t number,
	Sex sex,
	int day,
	int month,
	int year,
	int height,
	int weight,
	std::string sity) :
	name(name), 
	secondName(secondName),
	number(number),
	sex(sex),
	height(height), 
	weight(weight),
	sity(sity) {
	setBirthday(day, month, year);
}

std::string People::setInformation(std::string info) {
	information = info;
	return this->information;
}

void People::addHobbies(Hobby hobby) {
	bool flag{ false };
	for (const auto& obj : hobbies) if (obj == hobby) flag = true;
	if (flag) return;
	hobbies.push_back(hobby);
}

void People::addBadHobbies(BadHabbits badHabbit) {
	bool flag{ false };
	for (const auto& obj : badHabbits) if (obj == badHabbit) flag = true;
	if (flag) return;
	badHabbits.push_back(badHabbit);
}

void People::addRequiredHobbies(Hobby hobby) {
	bool flag{ false };
	for (const auto& obj : requiredHobbies) if (obj == hobby) flag = true;
	if (flag) return;
	requiredHobbies.push_back(hobby);
}

void People::addRequiredBadHobbies(BadHabbits badHabbit) {
	bool flag{ false };
	for (const auto& obj : requiredBadHabbits) if (obj == badHabbit) flag = true;
	if (flag) return;
	requiredBadHabbits.push_back(badHabbit);
}

bool People::operator==(const People& obj) {
	if (this->number == obj.number) return true;
	return false;
}