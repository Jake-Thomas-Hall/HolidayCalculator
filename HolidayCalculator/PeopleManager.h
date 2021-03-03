#pragma once

class PeopleManager
{
	std::vector<Person> _vecPeople;
public:
	PeopleManager() {}
	void add_person(Person& objPerson);
	size_t get_count();
	std::vector<Person>* get_vec_people_ptr() { return &_vecPeople; }
	bool isFamily();
};

