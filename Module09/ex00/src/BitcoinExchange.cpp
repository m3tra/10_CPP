#include "BitcoinExchange.hpp"

bool	is_number(const string& s)
{
	string::const_iterator it = s.begin();
	while (it != s.end() && std::isdigit(*it))
		++it;
	return (!s.empty() && it == s.end());
}

bool	is_valid_value(const string &value)
{
	if (value.empty() || \
		value.find(' ') != string::npos
	)
		return (false);

	if (value.find('.') == string::npos) {
		// if (!(0 <= std::stoi(value) <= 1000)) {
		int	iValue = atoi(value.c_str());
		if (!(0 <= iValue && iValue <= 1000)) {
			std::cout << RED << "Error: ";
			std::cout << WHITE << "Value not in range [0, 1000]" << std::endl;
			return (false);
		}
	}
	else {
		if (value.find('.') != string::npos) {
			std::cout << RED << "Error: ";
			std::cout << WHITE << "Bad value format";
			return (false);
		}
		// if (!(0 <= std::stof(value) <= 1000)) {
		int	fValue = atof(value.c_str());
		if (!(0 <= fValue && fValue <= 1000)) {
			std::cout << RED << "Error: ";
			std::cout << WHITE << "Value not in range [0, 1000]" << std::endl;
			return (false);
		}
	}

	return (true);
}

bool	is_valid_date(const string &date)
{
	if (date.empty() || \
		date.find('-') == string::npos
	)
		return (false);

	size_t	firstSeparatorIndex = date.find_first_of('-');
	size_t	secondSeparatorIndex = date.find_last_of('-');
	if (firstSeparatorIndex == secondSeparatorIndex)
		return (false);

	string	yearStr = date.substr(0, firstSeparatorIndex);
	string	monthStr = date.substr(firstSeparatorIndex + 1, 2);
	string	dayStr = date.substr(secondSeparatorIndex + 1, 2);
	if (!is_number(yearStr) || \
		!is_number(monthStr) || \
		!is_number(dayStr)
	)
		return (false);

	int		year = atoi(yearStr.c_str());
	int		month = atoi(monthStr.c_str());
	int		day = atoi(dayStr.c_str());

	// std::cout << "year: " << year << std::endl;
	// std::cout << "month: " << month << std::endl;
	// std::cout << "day: " << day << std::endl;

	// Add leap year check

	if (!(year > 0 && \
		1 <= month && month <= 12 && \
		1 <= day && day <= 31
	))
		return (false);

	return (true);
}

// Takes in line, splits it into date and value and checks if they're valid
bool	is_valid_line(const string &line, string &date, string &value)
{
	// std::cout << "Curr line: |" << line << "|" << std::endl;

	if (line.find('|') != string::npos) {
		std::istringstream	stream(line);

		std::getline(stream, date, '|');
		// Remove following whitespace
		if (*(--date.end()) == ' ')
			date.erase(--date.end());


		std::getline(stream, value, '|');
		// Remove trailing whitespace
		if (*(value.begin()) == ' ')
			value.erase(value.begin());
	}
	else {
		date = line;

		// std::cout << "line len: " << line.length() << std::endl;
		// for (size_t i = 0; i < line.length(); i++)
		// 	std::cout << "line" << i << ": " << static_cast<int>(line[i]) << std::endl;
	}

	if (!is_valid_date(date) ||
		(!value.empty() && !is_valid_value(value))
	)
		return (false);

	return (true);
}

void	intake_db()
{
	std::ifstream			inFile;
	char					*filename = "../data.csv";
	std::map<string, float>	database;

	inFile.open(filename, std::ios::in);
	if (!inFile.is_open()) {
		std::cout << RED << "Error: ";
		std::cout << WHITE << "Failed to open " << filename;
		std::cout << std::endl;
	}



	inFile.close();
}
