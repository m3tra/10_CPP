#include "BitcoinExchange.hpp"

bool	is_pos_number(const string& s)
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

bool	is_valid_date(const string &date_str)
{
	if (date_str.empty() || \
		date_str.find('-') == string::npos || \
		date_str[0] == '-'
	)
		return (false);

	size_t	first_separator_i = date_str.find_first_of('-');
	size_t	second_separator_i = date_str.find_last_of('-');
	if (first_separator_i == second_separator_i)
		return (false);

	string	year_str = date_str.substr(0, first_separator_i);
	string	month_str = date_str.substr(first_separator_i + 1, 2);
	string	day_str = date_str.substr(second_separator_i + 1, 2);
	if (!is_pos_number(year_str) || \
		!is_pos_number(month_str) || \
		!is_pos_number(day_str)
	)
		return (false);

	int		year = atoi(year_str.c_str());
	int		month = atoi(month_str.c_str());
	int		day = atoi(day_str.c_str());

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

// Takes in line, splits it into date_str and value and checks if they're valid
bool	is_valid_line(const string &line, string &date_str, string &value)
{
	// std::cout << "Curr line: |" << line << "|" << std::endl;

	if (line.find('|') != string::npos) {
		std::istringstream	stream(line);

		std::getline(stream, date_str, '|');
		// Remove following whitespace
		if (*(--date_str.end()) == ' ')
			date_str.erase(--date_str.end());


		std::getline(stream, value, '|');
		// Remove trailing whitespace
		if (*(value.begin()) == ' ')
			value.erase(value.begin());
	}
	else {
		date_str = line;

		// std::cout << "line len: " << line.length() << std::endl;
		// for (size_t i = 0; i < line.length(); i++)
		// 	std::cout << "line" << i << ": " << static_cast<int>(line[i]) << std::endl;
	}

	if (!is_valid_date(date_str) ||
		(!value.empty() && !is_valid_value(value))
	)
		return (false);

	return (true);
}

std::map<string, float>	intake_db(const string& filename)
{
	std::ifstream			in_file_stream;
	// string					filename = "data.csv";
	std::map<string, float>	database;

	in_file_stream.open(filename.c_str(), std::ios::in);
	if (!in_file_stream.is_open()) {
		std::cout << RED << "Error: ";
		std::cout << WHITE << "Failed to open " << filename;
		std::cout << std::endl;
	}

	string	line;
	bool	first_line = true;
	while (std::getline(in_file_stream, line) && !line.empty())
	{
		// Properly terminate string (remove terminating CR)
		line.erase(--line.end());

		if (first_line) {
			if (line.compare("date,exchange_rate"))
				throw "Database is missing first line header";
			first_line = false;
			continue;
		}

		// Add extra error checking

		std::istringstream	stream(line);
		string				date;
		string				value;

		std::getline(stream, date, ',');
		std::getline(stream, value, ',');

		// std::cout << "date: " << date << std::endl;
		// std::cout << "value: " << value << std::endl;

		database[date] = atof(value.c_str());
	}

	in_file_stream.close();

	return (database);
}

string	find_nearest_date(const string& date, const std::map<string, float>& database)
{

}

t_date	split_date(const string& date_str)
{
	t_date	date = {0, 0, 0};

	if (date_str.empty() || \
		date_str.find('-') == string::npos || \
		date_str[0] == '-'
	)
		return (date);

	size_t	first_separator_i = date_str.find_first_of('-');
	size_t	second_separator_i = date_str.find_last_of('-');
	if (first_separator_i == second_separator_i)
		return (date);

	string	year_str = date_str.substr(0, first_separator_i);
	string	month_str = date_str.substr(first_separator_i + 1, 2);
	string	day_str = date_str.substr(second_separator_i + 1, 2);
	if (!is_pos_number(year_str) || \
		!is_pos_number(month_str) || \
		!is_pos_number(day_str)
	)
		return (date);

	date.year = atoi(year_str.c_str());
	date.month = atoi(month_str.c_str());
	date.day = atoi(day_str.c_str());

	return (date);
}

bool	is_leap_year(const unsigned int year)
{
	if (year % 4 == 0) {
		if (year % 100 != 0 || \
			(year % 100 == 0 && year % 400 == 0)
		)
		return (true);
	}
	return (false);
}

void	output_results(const std::map<string, float>& database, const std::map<string, float>& input)
{
	std::map<string, float>::const_iterator	it;
	for (it = input.begin(); it != input.end(); it++) {
		const string& date = (*it).first;
		if (database.find(date) == database.end()) {
			string nearest = find_nearest_date(date, database);
		}
	}
}
