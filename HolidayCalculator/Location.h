#pragma once

class Location
{
	std::string _name;
	double _cost_per_person;
	int _min_members;
public:
	Location();
	Location(std::string str_name, double d_cost_per_person, int i_min_members);

	std::string get_name() { return _name; }
	double get_cost_per_person() { return _cost_per_person; }
	int get_min_members() { return _min_members; }
};

