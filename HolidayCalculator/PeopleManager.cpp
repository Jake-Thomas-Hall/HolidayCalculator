#include "Common.h"

void PeopleManager::add_person(Person& objPerson) {
	_vecPeople.push_back(objPerson);
}

size_t PeopleManager::get_count() {
	return _vecPeople.size();
}

bool PeopleManager::isFamily() {
	int children_count = 0;
	int adult_count = 0;

	for (Person person : _vecPeople) {
		if (person.get_age() <= 16) children_count++;
		else if (person.get_age() > 16) adult_count++;
	}

	return children_count == 2 && adult_count == 2;
}