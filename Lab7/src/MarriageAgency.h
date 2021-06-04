#pragma once
#include "People.h"
#include <vector>

class MarriageAgency {
private:
	std::vector<People*> men;
	std::vector<People*> women;
	std::vector<std::pair<People*, People*>> archive;

	void showPair(std::pair<People*, People*> pair);
	bool checkSimilarity(const People& m, const People& w);
	size_t indexByNumber(uint16_t num, Sex sex);
public:
	MarriageAgency();
	
	void addPeople(People* people);
	std::vector<std::pair<People*, People*>> showPossiblePairs();
	int makePair(uint16_t firstNumber, uint16_t secondNumber);
	void deletePeople(uint16_t number, Sex sex);
};
