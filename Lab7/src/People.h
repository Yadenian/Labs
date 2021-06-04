#pragma once

#include <string>
#include <vector>

enum class Sex {
	Man,
	Woman
};

enum class Hobby {
	Reading,
	Singing,
	ListeningToMusic,
	Photography,
	Drowing,
	Needlework,
	Cooking
};

enum class BadHabbits {
	Smoking,
	Drinking,
	Drug,
	Gluttony
};

class People
{
private:
	void setBirthday(int day, int month, int year);

public:
	std::string name;
	std::string secondName;
	uint16_t number;
	Sex sex;
	int day;
	int month;
	int year;
	int height;
	int weight;
	std::string sity;
	std::string information;
	std::vector<Hobby> hobbies;
	std::vector<BadHabbits> badHabbits;
	std::vector<Hobby> requiredHobbies;
	std::vector<BadHabbits> requiredBadHabbits;

	People(std::string name,
		std::string secondName,
		uint16_t number,
		Sex sex,
		int day,
		int month,
		int year,
		int height,
		int weight,
		std::string sity);

	std::string setInformation(std::string info);
	void addHobbies(Hobby hobby);
	void addBadHobbies(BadHabbits badHabbit);
	void addRequiredHobbies(Hobby hobby);
	void addRequiredBadHobbies(BadHabbits badHabbit);

	bool operator==(const People& obj);
};
