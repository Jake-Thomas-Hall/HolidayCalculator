#include "Common.h"

Person::Person() {
	_age = 0;
	_name = "";
}

Person::Person(int iAge, std::string strName) {
	_age = iAge;
	_name = strName;
}