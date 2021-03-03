#include "Common.h"

MenuContainer::MenuContainer(std::string const& text) : _strText(text), _vecMenuItems()
{
	_boolExitMenu = false;
	_iHighlightedIndex = 0;
	_hOutputConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	_hInputConsole = GetStdHandle(STD_INPUT_HANDLE);
}

void MenuContainer::execute()
{
	KEY_EVENT_RECORD key{};

	while (key.wVirtualKeyCode != VK_RETURN) {
		system("cls");
		std::cout << _strText << "\n";
		util::for_each_iterator(_vecMenuItems.begin(), _vecMenuItems.end(), 0, [&](int index, std::unique_ptr<MenuItem> const& item) {
			if (_iHighlightedIndex == index) {
				SetConsoleTextAttribute(_hOutputConsole, BACKGROUND_BLUE | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_INTENSITY);
				std::cout << "\t" << item->item_text() << "\n";
				SetConsoleTextAttribute(_hOutputConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			}
			else {
				std::cout << "\t" << item->item_text() << "\n";
			}
			});
		while (!input_validator::get_control_char(key, _hInputConsole));
		if (key.wVirtualKeyCode == VK_DOWN) {
			if (_iHighlightedIndex < (int)_vecMenuItems.size() - 1) _iHighlightedIndex++;
		}
		else if (key.wVirtualKeyCode == VK_UP) {
			if (_iHighlightedIndex > 0) _iHighlightedIndex--;
		}
	}

	if ((int)_vecMenuItems.size() > _iHighlightedIndex && _iHighlightedIndex >= 0) {
		_vecMenuItems[_iHighlightedIndex]->execute();
	}
	else {
		std::cout << "Not a valid option, please try again.\n";
		util::pause();
	}
}

void MenuContainer::add_menu_item(std::unique_ptr<MenuItem> item) {
	_vecMenuItems.push_back(std::move(item));
}

GeneralMenuItem::GeneralMenuItem(std::string output, ClassContainer* ptrClassContainer)
{
	_output = output;
	_ptrClassContainer = ptrClassContainer;
}

void AddPerson::execute() {
	Person person;

	system("cls");
	std::cout << "Enter person age: ";
	person.set_age(input_validator::validate_int());

	std::cout << "Enter person name: ";
	person.set_name(input_validator::validate_string());

	_ptrClassContainer->get_people_manager()->add_person(person);
	std::cout << "Person successfully added\n";
	util::pause();
}

void ViewCosts::execute() {
	system("cls");
	std::cout << "Not yet implemented\n";
	util::pause();
}

MenuExit::MenuExit(std::string output, MenuContainer* menuContainer) : GeneralMenuItem(output, nullptr) {
	_menu_container = menuContainer;
}

void MenuExit::execute() {
	_menu_container->set_exit_menu(true);
}