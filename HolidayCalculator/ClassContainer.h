#pragma once
#include "Common.h"

class ClassContainer
{
	PeopleManager* _ptrPeopleManager;
public:
	ClassContainer(PeopleManager* ptrPeopleManager);
	PeopleManager* get_people_manager() { return _ptrPeopleManager; }
};

