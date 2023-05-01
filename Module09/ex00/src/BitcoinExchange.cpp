#include "BitcoinExchange.hpp"

bool	is_number(const string& s)
{
	string::const_iterator it = s.begin();
	while (it != s.end() && std::isdigit(*it))
		++it;
	return (!s.empty() && it == s.end());
}

bool	isValidValue(string value)
{
	if (
		value.empty() || \
		value.find(' ') != string::npos
	)
		return (false);

	if (value.find('.') == string::npos) {
		if (!(0 <= std::stoi(value) <= 1000)) {
			std::cout << RED << "Error: ";
			std::cout << "Value not in range [0, 1000]" << std::endl;
			return (false);
		}
	}
	else {
		if (value.find('.') != string::npos) {
			std::cout << RED << "Error: ";
			std::cout << WHITE << "Bad value format";
			return (false);
		}
		if (!(0 <= std::stof(value) <= 1000)) {
			std::cout << RED << "Error: ";
			std::cout << "Value not in range [0, 1000]" << std::endl;
			return (false);
		}
	}

	return (true);
}

bool	isValidDate(string date)
{
	if (
		date.empty() || \
		date.size() != 10 || \
		date.find(' ') != string::npos || \
		date[4] != '-' || \
		date[7] != '-'
	)
		return (false);

	string	yearStr = date.substr(0, 4);
	string	monthStr = date.substr(5, 2);
	string	dayStr = date.substr(8, 2);

	if (!is_number(yearStr) || \
		!is_number(monthStr) || \
		!is_number(dayStr)
	)
		return (false);

	int		year = std::stoi(yearStr);
	int		month = std::stoi(monthStr);
	int		day = std::stoi(dayStr);

	if (
		0 < month && month <= 12 || \
		0 < day && day <= 31
	)
		return (false);

	return (true);
}

bool	isValidLine(string line)
{
	std::stringstream	stream(line);
	string	date;
	string	value;

	std::getline(stream, date, '|');
	std::getline(stream, value, '|');

	// Remove whitespace
	date.erase(--date.end());
	if (!isValidDate(date))
		return (false);

	value.erase(value.begin());
	if (!isValidValue(value))
		return (false);

	std::cout << "date: |" << date << "|" << std::endl;
	std::cout << "value: |" << value << "|" << std::endl;

	return (true);
}
