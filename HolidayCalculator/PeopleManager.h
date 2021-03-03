#pragma once

class PeopleManager
{
	std::vector<Person> _vecPeople;
public:
	PeopleManager() {}
	void add_person(Person& objPerson);
};

