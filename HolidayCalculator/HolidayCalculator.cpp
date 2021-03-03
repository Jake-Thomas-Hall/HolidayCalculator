#include "Common.h"

int main()
{
	PeopleManager objPeopleManager;
	ClassContainer objClassContainer = ClassContainer(&objPeopleManager);

	MenuContainer objMenuContainer = MenuContainer("Test navigation menu.\nChoose one of the below options.\n");
	objMenuContainer.add_menu_item(std::unique_ptr<MenuItem>(new AddPerson("Add Person", &objClassContainer)));
	objMenuContainer.add_menu_item(std::unique_ptr<MenuItem>(new ViewCosts("View costs", &objClassContainer)));
	objMenuContainer.add_menu_item(std::unique_ptr<MenuItem>(new MenuExit("Exit menu", &objMenuContainer)));

	while (!objMenuContainer.get_exit_menu()) {
		system("cls");
		objMenuContainer.execute();
	}
}

