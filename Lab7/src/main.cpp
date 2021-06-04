#include <iostream>
#include "People.h"
#include "MarriageAgency.h"

void addPerson(MarriageAgency& agency);
People* createPeople();

int main() {
	MarriageAgency agency{};

	int input{};
	do {
		std::cout << "Enter 1 to add a person to the database" << std::endl;
		std::cout << "Enter 2 to show possible pairs" << std::endl;
		std::cout << "Enter 3 to move pair to archive" << std::endl;
		std::cout << "Enter 4 to exit" << std::endl;

		std::cin >> input;
		switch (input)
		{
		case 1:
			addPerson(agency);
			break;
		case 2:
			agency.showPossiblePairs();
			break;
		case 3:
			int m;
			std::cout << "Enter mans number: ";
			std::cin >> m;
			int w;
			std::cout << "Enter womans number: ";
			std::cin >> w;
			agency.makePair(m, w);
			break;
		case 4:
			return 0;
			break;
		default:
			std::cout << "Unknown command please try again" << std::endl;
			std::cin.clear();
			std::cin.ignore(256, '\n');
			break;
		}
	} while (true);

	return 0;
}

void addPerson(MarriageAgency& agency) {
	agency.addPeople(createPeople());
}

People* createPeople() {
	std::string name{};
	std::cout << "Enter name: ";
	std::cin >> name;

	std::string secondName{};
	std::cout << "Enter secondName: ";
	std::cin >> secondName;

	uint16_t number{ 1 };
	while (true) {
		std::cout << "Enter number ( > 0 ): ";
		std::cin >> number;
		if (number == 0) {
			std::cout << "Incorrect input, please try again" << std::endl;
			std::cin.clear();
			std::cin.ignore(256, '\n');
			continue;
		}
		break;
	}

	Sex sex;
	while (true) {
		std::string temp{};
		std::cout << "Enter sex (man, woman): ";
		std::cin >> temp;
		if (temp == "man") sex = Sex::Man;
		else if (temp == "woman") sex = Sex::Woman;
		else {
			std::cout << "Incorrect input, please try again" << std::endl;
			std::cin.clear();
			std::cin.ignore(256, '\n');
			continue;
		}
		break;
	}

	int day{};
	int month{};
	int year{};
	while (true) {
		std::cout << "Enter day: ";
		std::cin >> day;
		std::cout << "Enter month: ";
		std::cin >> month;
		std::cout << "Enter year: ";
		std::cin >> year;

		if ((month > 12) || (day > 31 || (day > 28 && month == 2))) {
			std::cout << "Incorrect input, please try again" << std::endl;
			std::cin.clear();
			std::cin.ignore(256, '\n');
			continue;
		}
		break;
	}

	int height{};
	int weight{};
	std::cout << "Enter height: ";
	std::cin >> height;
	std::cout << "Enter weight: ";
	std::cin >> weight;

	std::string sity{};
	std::cout << "Enter sity: ";
	std::cin >> sity;

	People* tempPeople = new People{ name, secondName, number, sex, day, month, year, height, weight, sity };

	Hobby tempHobby;
	std::vector<Hobby> tempHobbyVector{};
	while (true) {
		std::string temp{};
		std::cout << "Enter hobby ( Reading, Singing, ListeningToMusic, Photography, Drowing, Needlework, Cooking) or anything else to exit: ";
		std::cin >> temp;
		if (temp == "Reading") tempHobbyVector.push_back(Hobby::Reading);
		else if (temp == "Singing") tempHobbyVector.push_back(Hobby::Singing);
		else if (temp == "ListeningToMusic") tempHobbyVector.push_back(Hobby::ListeningToMusic);
		else if (temp == "Photography") tempHobbyVector.push_back(Hobby::Photography);
		else if (temp == "Drowing") tempHobbyVector.push_back(Hobby::Drowing);
		else if (temp == "Needlework") tempHobbyVector.push_back(Hobby::Needlework);
		else if (temp == "Cooking") tempHobbyVector.push_back(Hobby::Cooking);
		else break;
	}

	for (const auto& obj : tempHobbyVector) {
		tempPeople->addHobbies(obj);
	}
	tempHobbyVector.clear();

	while (true) {
		std::string temp{};
		std::cout << "Enter required hobby ( Reading, Singing, ListeningToMusic, Photography, Drowing, Needlework, Cooking) or anything else to exit: ";
		std::cin >> temp;
		if (temp == "Reading") tempHobbyVector.push_back(Hobby::Reading);
		else if (temp == "Singing") tempHobbyVector.push_back(Hobby::Singing);
		else if (temp == "ListeningToMusic") tempHobbyVector.push_back(Hobby::ListeningToMusic);
		else if (temp == "Photography") tempHobbyVector.push_back(Hobby::Photography);
		else if (temp == "Drowing") tempHobbyVector.push_back(Hobby::Drowing);
		else if (temp == "Needlework") tempHobbyVector.push_back(Hobby::Needlework);
		else if (temp == "Cooking") tempHobbyVector.push_back(Hobby::Cooking);
		else break;
	}

	for (const auto& obj : tempHobbyVector) {
		tempPeople->addRequiredHobbies(obj);
	}

	BadHabbits tempBadHabbit;
	std::vector<BadHabbits> tempBadHabbitsVec{};

	while (true) {
		std::string temp{};
		std::cout << "Enter bad hobby ( Smoking, Drinking, Drug, Gluttony) or anything else to exit: ";
		std::cin >> temp;
		if (temp == "Smoking") tempBadHabbitsVec.push_back(BadHabbits::Smoking);
		else if (temp == "Drinking") tempBadHabbitsVec.push_back(BadHabbits::Smoking);
		else if (temp == "Drug") tempBadHabbitsVec.push_back(BadHabbits::Smoking);
		else if (temp == "Gluttony") tempBadHabbitsVec.push_back(BadHabbits::Smoking);
		else break;
	}

	for (const auto& obj : tempBadHabbitsVec) {
		tempPeople->addBadHobbies(obj);
	}
	tempBadHabbitsVec.clear();

	while (true) {
		std::string temp{};
		std::cout << "Enter required bad hobby ( Smoking, Drinking, Drug, Gluttony) or anything else to exit: ";
		std::cin >> temp;
		if (temp == "Smoking") tempBadHabbitsVec.push_back(BadHabbits::Smoking);
		else if (temp == "Drinking") tempBadHabbitsVec.push_back(BadHabbits::Smoking);
		else if (temp == "Drug") tempBadHabbitsVec.push_back(BadHabbits::Smoking);
		else if (temp == "Gluttony") tempBadHabbitsVec.push_back(BadHabbits::Smoking);
		else break;
	}

	for (const auto& obj : tempBadHabbitsVec) {
		tempPeople->addRequiredBadHobbies(obj);
	}

	return tempPeople;
}