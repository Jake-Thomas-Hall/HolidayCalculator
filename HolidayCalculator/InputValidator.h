#pragma once

namespace input_validator
{
	bool get_control_char(KEY_EVENT_RECORD& keyRec, HANDLE& hConsole);
	int validate_int();
	int validate_int(int maxSize);
	int validate_int(int minSize, int maxSize);
	double validate_double();
	double validate_double_min(double minValue);
	double validate_double(double maxSize);
	double validate_double(double minSize, double maxSize);
	std::string validate_string();
	std::string validate_string(int maxLength);
}