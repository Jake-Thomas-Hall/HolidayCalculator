#pragma once
class Person
{
	int _age;
	std::string _name;
public:
	Person();
	Person(int iAge, std::string strName);

	int get_age() { return _age; }
	void set_age(int iAge) { _age = iAge; }
	std::string get_name() { return _name; }
	void set_name(std::string strName) { _name = strName; }
};

