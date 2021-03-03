#include "Common.h"

bool input_validator::get_control_char(KEY_EVENT_RECORD& keyRec, HANDLE& hConsole) {
	DWORD cc;
	INPUT_RECORD irec;

	if (hConsole == NULL)
	{
		return false; // console not found
	}

	for (; ; )
	{
		ReadConsoleInput(hConsole, &irec, 1, &cc);
		if (irec.EventType == KEY_EVENT && ((KEY_EVENT_RECORD&)irec.Event).bKeyDown)
		{
			keyRec = (KEY_EVENT_RECORD&)irec.Event;

			if (keyRec.wVirtualKeyCode == VK_UP) return true;
			if (keyRec.wVirtualKeyCode == VK_DOWN) return true;
			if (keyRec.wVirtualKeyCode == VK_RETURN) return true;
			if (keyRec.wVirtualKeyCode == VK_ESCAPE) return true;
			return false;
		}
	}
	return false;
}

int input_validator::validate_int() {
	std::string strInput;
	int iInput;

	while (true) {
		std::getline(std::cin, strInput);
		try {
			iInput = std::stoi(strInput);
			return iInput;
		}
		catch (std::exception) {
			std::cout << "Not a valid whole number: ";
		}
	}
}

int input_validator::validate_int(int maxSize) {
	std::string strInput;
	int iInput;

	while (true) {
		std::getline(std::cin, strInput);
		try {
			iInput = std::stoi(strInput);

			if (util::is_more_than(iInput, maxSize)) {
				std::cout << "To large, max size is " << std::setprecision(2) << maxSize << ": ";
			}
			else {
				return iInput;
			}
		}
		catch (std::exception) {
			std::cout << "Not a valid whole number: ";
		}
	}
}

int input_validator::validate_int(int minSize, int maxSize) {
	std::string strInput;
	int iInput;

	while (true) {
		std::getline(std::cin, strInput);
		try {
			iInput = std::stoi(strInput);

			if (!util::is_between(minSize, maxSize, iInput)) {
				std::cout << "Input not within valid range (" << minSize << " to " << maxSize << ") : ";
			}
			else {
				return iInput;
			}
		}
		catch (std::exception) {
			std::cout << "Not a valid number: ";
		}
	}
}

double input_validator::validate_double() {
	std::string strInput;
	double dInput;

	while (true) {
		std::getline(std::cin, strInput);
		try {
			dInput = std::stod(strInput);

			return dInput;
		}
		catch (std::exception) {
			std::cout << "Not a valid number: ";
		}
	}
}

double input_validator::validate_double_min(double minValue) {
	std::string strInput;
	double dInput;

	while (true) {
		std::getline(std::cin, strInput);
		try {
			dInput = std::stod(strInput);

			if (util::is_less_than_or_equal_to(dInput, minValue)) {
				std::cout << "Input cannot be " << minValue << " or less: ";
			}
			else {
				return dInput;
			}
		}
		catch (std::exception) {
			std::cout << "Not a valid number: ";
		}
	}
}

double input_validator::validate_double(double maxSize) {
	std::string strInput;
	double dInput;

	while (true) {
		std::getline(std::cin, strInput);
		try {
			dInput = std::stod(strInput);

			if (util::is_more_than(dInput, maxSize)) {
				std::cout << "To large, max size is " << std::setprecision(2) << maxSize << ": ";
			}
			else {
				return dInput;
			}
		}
		catch (std::exception) {
			std::cout << "Not a valid number: ";
		}
	}
}

double input_validator::validate_double(double minSize, double maxSize) {
	std::string strInput;
	double dInput;

	while (true) {
		std::getline(std::cin, strInput);
		try {
			dInput = std::stod(strInput);

			if (!util::is_between(minSize, maxSize, dInput)) {
				std::cout << "Input not within valid range (" << minSize << " to " << maxSize << ") : ";
			}
			else {
				return dInput;
			}
		}
		catch (std::exception) {
			std::cout << "Not a valid number: ";
		}
	}
}

std::string input_validator::validate_string() {
	std::string strInput;
	std::getline(std::cin, strInput);
	return strInput;
}

std::string input_validator::validate_string(int maxLength) {
	std::string strInput;

	while (true) {
		std::string strMessage = "Not a valid number";
		std::getline(std::cin, strInput);

		if (util::is_more_than(strInput.length(), (size_t)maxLength)) {
			strMessage = "To long, max length is " + std::to_string(maxLength);
			std::cout << strMessage << ", try again: ";
		}
		else {
			return strInput;
		}
	}
}