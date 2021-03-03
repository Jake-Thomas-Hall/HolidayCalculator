#include "Common.h"

Location::Location() {
	_name = "";
	_cost_per_person = 0;
	_min_members = 0;
}

Location::Location(std::string str_name, double d_cost_per_person, int i_min_members) {
	_name = str_name;
	_cost_per_person = d_cost_per_person;
	_min_members = i_min_members;
}
