#include "Common.h"

int main()
{
	PeopleManager objPeopleManager;
	LocationManager objLocationManager;
	objLocationManager.add_location(Location("Florida", 1300, 4));
	objLocationManager.add_location(Location("Paris", 600, 2));
	objLocationManager.add_location(Location("Milan", 950, 2));
	objLocationManager.add_location(Location("Tokyo", 1800, 4));
	ClassContainer objClassContainer = ClassContainer(&objPeopleManager, &objLocationManager);

	MenuContainer objMenuContainer = MenuContainer("Test navigation menu.\nChoose one of the below options.\n");
	objMenuContainer.add_menu_item(std::unique_ptr<MenuItem>(new AddPerson("Add Person", &objClassContainer)));
	objMenuContainer.add_menu_item(std::unique_ptr<MenuItem>(new ViewCosts("View costs", &objClassContainer)));
	objMenuContainer.add_menu_item(std::unique_ptr<MenuItem>(new MenuExit("Exit menu", &objMenuContainer)));

	while (!objMenuContainer.get_exit_menu()) {
		system("cls");
		objMenuContainer.execute();
	}
}

