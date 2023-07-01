#include "BitcoinExchange.hpp"

// bool	is_pos_number(const string &s)
// {
// 	string::const_iterator it = s.begin();
// 	while (it != s.end() && std::isdigit(*it))
// 		++it;
// 	return (!s.empty() && it == s.end());
// }

bool	is_valid_value(const string &value)
{
	if (value.find(' ') != string::npos)
		return false;

	// ? Should it always have a '.'?

	if (value.find('.') == string::npos) { // Is int
		int	iValue = atoi(value.c_str());
		if (0 <= iValue && iValue <= 1000)
			return true;
	}
	else { // Is float
		float	fValue = atof(value.c_str());
		if (0 <= fValue && fValue <= 1000)
			return true;
	}
	std::ostringstream	error;
	error << value << "not in range [0, 1000]";
	err_exit(error.str());
	return false;
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

	if (!is_valid_date(date_str) \
		|| (!value.empty() && !is_valid_value(value))
	)
		return false;

	return true;
}

// Properly terminate string (remove terminating CR if it exists)
void	terminate_string(string &str)
{
	if (*(--str.end()) == 13)
		str.erase(--str.end());
}

const t_db	parse_own_db(const char *filename)
{
	std::ifstream	in_file_stream;
	open_file(in_file_stream, filename);

	string	line;
	t_db	db;
	while (std::getline(in_file_stream, line) && !line.empty()) {
		terminate_string(line);

		// if (line[line.length()] == '\0')
		// 	std::cout << "line is NULL terminated" << std::endl;

		string	date;
		string	value;
		if (!is_valid_line(line, date, value)) {
			std::ostringstream	error;
			error << "Bad format: " << line;
			// std::cout << "date: |" << date << "|" << std::endl;
			// std::cout << std::endl;
			// std::cout << "value: |" << value << "|" << std::endl;
			in_file_stream.close();
			err_exit(error.str());
		}

		db[date] = atof(value.c_str());
		// std::cout << "date: |" << date << "|" << std::endl;
		// std::cout << "value: |" << value << "|" << std::endl;
		// std::cout << std::endl << std::endl;
	}
	in_file_stream.close();
	return db;
}

const t_db	parse_subject_db(const char *filename)
{
	std::ifstream	in_file_stream;
	open_file(in_file_stream, filename);

	string	line;
	t_db	db;
	bool	first_line = true;
	while (std::getline(in_file_stream, line) && !line.empty()) {
		terminate_string(line);

		if (first_line) {
			if (line.compare("date,exchange_rate")) {
				in_file_stream.close();
				err_exit("Subject's database is missing first line header");
			}
			first_line = false;
			continue;
		}

		// TODO: Add extra error checking

		std::istringstream	stream(line);
		string				date;
		string				value;

		std::getline(stream, date, ',');
		std::getline(stream, value, ',');

		// std::cout << "date: " << date << std::endl;
		// std::cout << "value: " << value << std::endl;

		db[date] = atof(value.c_str());
	}
	in_file_stream.close();
	return db;
}

/*
	for each value in input.txt
		multiply it by it's date correspondent exchange rate from .csv IF exists
		ELSE do it with nearest lower date's correspondent
*/

void	output_results(const t_db &subject_db, const t_db &own_db)
{
	t_db::const_iterator	it;
	for (it = own_db.begin(); it != own_db.end(); it++) {
		const string curr_date = (*it).first;

		if (subject_db.find(curr_date) == subject_db.end()) {
			string nearest = find_nearest_date(subject_db, curr_date);
			// TODO: Finish func
		}
	}
}
