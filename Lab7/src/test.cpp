#include "People.h"
#include "MarriageAgency.h"
#include <cassert>

int checkSimilatity(std::vector<std::pair<People*, People*>> a, std::vector<std::pair<People*, People*>> b) {
	if (a.size() != b.size()) return -1;
	for (const auto obj : a) {
		for (const auto obj : b) {
			if (a != b) return -1;
		}
	}
	return 0;
}

int main() {
	MarriageAgency agency;

	People first{ "Ivan", "Ivanovich", 1, Sex::Man, 1, 1, 2000, 180, 80, "Minsk" };
	assert(first.setInformation("First people") == "First people");

	People second{ "Gahya", "Ivanovna", 2, Sex::Woman, 1, 1, 2000, 180, 80, "Minsk" };

	agency.addPeople(&first);
	agency.addPeople(&second);

	assert(checkSimilatity(agency.showPossiblePairs(), 
		std::vector<std::pair<People*, People*>>{std::pair<People*, People*>{&first, &second}}) == 0);

	first.addRequiredHobbies(Hobby::Cooking);

	assert(checkSimilatity(agency.showPossiblePairs(),
		std::vector<std::pair<People*, People*>>{}) == 0);

	second.addHobbies(Hobby::Cooking);

	assert(checkSimilatity(agency.showPossiblePairs(),
		std::vector<std::pair<People*, People*>>{std::pair<People*, People*>{&first, & second}}) == 0);

	second.addRequiredHobbies(Hobby::Drowing);

	assert(checkSimilatity(agency.showPossiblePairs(),
		std::vector<std::pair<People*, People*>>{}) == 0);

	first.addHobbies(Hobby::Drowing);

	assert(checkSimilatity(agency.showPossiblePairs(),
		std::vector<std::pair<People*, People*>>{std::pair<People*, People*>{&first, & second}}) == 0);

	first.addRequiredBadHobbies(BadHabbits::Drinking);
	second.addBadHobbies(BadHabbits::Drinking);

	assert(checkSimilatity(agency.showPossiblePairs(),
		std::vector<std::pair<People*, People*>>{}) == 0);

	second.addRequiredBadHobbies(BadHabbits::Gluttony);
	first.addBadHobbies(BadHabbits::Gluttony);

	assert(checkSimilatity(agency.showPossiblePairs(),
		std::vector<std::pair<People*, People*>>{}) == 0);

	People third{ "Petr", "Ivanovich", 3, Sex::Man, 1, 1, 2000, 180, 80, "Minsk" };
	People fourth{ "Ira", "Ivanovich", 4, Sex::Woman, 1, 1, 2000, 180, 80, "Minsk" };

	agency.addPeople(&third);
	agency.addPeople(&fourth);

	assert(checkSimilatity(agency.showPossiblePairs(),
		std::vector<std::pair<People*, People*>>{std::pair<People*, People*>{&third, &fourth}}) == 0);

	agency.makePair(3, 4);

	assert(checkSimilatity(agency.showPossiblePairs(),
		std::vector<std::pair<People*, People*>>{}) == 0);



	return 0;
}