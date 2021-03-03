#pragma once

class ClassContainer
{
	PeopleManager* _ptrPeopleManager;
	LocationManager* _ptr_location_manager;
public:
	ClassContainer(PeopleManager* ptrPeopleManager, LocationManager* ptr_location_manager);
	PeopleManager* get_people_manager() { return _ptrPeopleManager; }
	LocationManager* get_location_manager() { return _ptr_location_manager; }
};

