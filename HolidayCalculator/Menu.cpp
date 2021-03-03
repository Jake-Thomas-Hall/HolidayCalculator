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
	if (_ptrClassContainer->get_people_manager()->get_count() < 1) {
		std::cout << "You cannot view costs until you add at least one person\n";
		util::pause();
		return;
	}

	KEY_EVENT_RECORD key{};
	HANDLE hOutputConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	HANDLE hInputConsole = GetStdHandle(STD_INPUT_HANDLE);
	std::vector<Location> vec_locations = *_ptrClassContainer->get_location_manager()->get_vec_locations_ptr();
	int i_highlighted_index = 0;

	while (key.wVirtualKeyCode != VK_RETURN && key.wVirtualKeyCode != VK_ESCAPE) {
		system("cls");
		std::cout << "Select available holiday packages\nPress ESC to cancel\n\n";
		util::for_each_iterator(vec_locations.begin(), vec_locations.end(), 0, [&](int index, Location item) {
			if (i_highlighted_index == index) {
				SetConsoleTextAttribute(hOutputConsole, BACKGROUND_BLUE | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_INTENSITY);
				std::cout << "\t Name: " << item.get_name() << " Cost Per Person: " << item.get_cost_per_person() << " Min Members: " << item.get_min_members() << "\n";
				SetConsoleTextAttribute(hOutputConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			}
			else {
				std::cout << "\t Name: " << item.get_name() << " Cost Per Person: " << item.get_cost_per_person() << " Min Members: " << item.get_min_members() << "\n";
			}
			});
		while (!input_validator::get_control_char(key, hInputConsole));
		if (key.wVirtualKeyCode == VK_DOWN) {
			if (i_highlighted_index < (int)vec_locations.size() - 1) i_highlighted_index++;
		}
		else if (key.wVirtualKeyCode == VK_UP) {
			if (i_highlighted_index > 0) i_highlighted_index--;
		}
	}

	if (key.wVirtualKeyCode == VK_ESCAPE) {
		return;
	}

	if (key.wVirtualKeyCode == VK_RETURN) {
		system("cls");
		Location selected_location = vec_locations.at(i_highlighted_index);
		std::vector<Person> vec_people = *_ptrClassContainer->get_people_manager()->get_vec_people_ptr();
		if (vec_people.size() < selected_location.get_min_members()) {
			std::cout << "You cannot go on holiday to this location, you need at least " << selected_location.get_min_members() << " people in your group.\n";
			util::pause();
			return;
		}

		double total = selected_location.get_cost_per_person() * vec_people.size();
		std::cout << "Total cost: " << total << "\n";
		std::cout << "Price per person: " << selected_location.get_cost_per_person() << "\n";

		if (_ptrClassContainer->get_people_manager()->isFamily()) {
			double discount_total = total * 0.8;
			std::cout << "Total with family discount: " << discount_total << "\n";
		}
		else {
			std::cout << "Your group does not qualify for family discount.\n";
		}

		util::pause();
	}
}

MenuExit::MenuExit(std::string output, MenuContainer* menuContainer) : GeneralMenuItem(output, nullptr) {
	_menu_container = menuContainer;
}

void MenuExit::execute() {
	_menu_container->set_exit_menu(true);
}