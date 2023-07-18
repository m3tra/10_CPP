#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const string &filename)
{
	this->_subject_db = parse_subject_db(SUBJECT_DB);
	parse_own_db(filename);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _subject_db(other._subject_db) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &other)
{
	this->_subject_db = other._subject_db;
	this->_lowest_date = other._lowest_date;

	return *this;
}

BitcoinExchange::~BitcoinExchange() {}



void			BitcoinExchange::err_exit(const string &error) const
{
	std::cerr << RED << "Error: ";
	std::cerr << WHITE << error << std::endl;
	exit(EXIT_FAILURE);
}

// Tries to open given filename to in_file_stream
void			BitcoinExchange::open_file(std::ifstream &in_file_stream, const string &filename) const
{
	in_file_stream.open(filename.c_str(), std::ios::in);
	if (!in_file_stream.is_open())
		err_exit("Failed to open " + filename);
}

bool			BitcoinExchange::is_leap_year(const u_int16_t year) const
{
	return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

uint			BitcoinExchange::n_occurences(const char c, const string &str) const
{
	uint	n = 0;
	size_t	i = -1;

	while (true) {
		i = str.find(c, i + 1);
		if (i == string::npos)
			break;
		n++;
	}
	return n;
}

bool				BitcoinExchange::is_valid_date(const string &date) const
{
	if (date.empty() \
		|| n_occurences('-', date) != 2)
		return false;

	for (size_t i = 0; i < date.length(); i++)
		if (!isdigit(date[i]) \
			&& date[i] != '-')
			return false;

	const size_t	first_sep_i = date.find_first_of('-');
	const size_t	second_sep_i = date.find_last_of('-');
	const size_t	sep_offset = second_sep_i - first_sep_i;
	if (first_sep_i == 0 \
		|| sep_offset != 3)
		return false;

	const string	month_str = date.substr(first_sep_i + 1, sep_offset - 1);
	const string	day_str = date.substr(second_sep_i + 1);
	if (month_str.length() != 2 \
		|| day_str.length() != 2)
		return false;

	const uint		year = atoi(date.substr(0, first_sep_i).c_str());
	const uint		month = atoi(month_str.c_str());
	const uint		day = atoi(day_str.c_str());

	if (year < 1)
		return false;

	if (!(1 <= month && month <= 12 \
		&& 1 <= day && day <= 31))
		return false;

	if ((month == 2 && is_leap_year(year) && day > 29) \
		|| (month == 2 && !is_leap_year(year) && day > 28) \
		|| (!has_31_days(month) && day == 31))
		return false;

	return true;
}

// Splits date string into a struct of u_ints
const struct s_date	BitcoinExchange::split_date(const string &date) const
{
	struct s_date	ret;

	const size_t	first_sep_i = date.find_first_of('-');
	const size_t	second_sep_i = date.find_last_of('-');
	const size_t	sep_offset = second_sep_i - first_sep_i;

	ret.year = atoi(date.substr(0, first_sep_i).c_str());
	ret.month = atoi(date.substr(first_sep_i + 1, sep_offset - 1).c_str());
	ret.day = atoi(date.substr(second_sep_i + 1).c_str());

	return ret;
}

const string		BitcoinExchange::int_to_str(const long n) const
{
	std::ostringstream	stream;
	stream << n;
	return stream.str();
}

const string		BitcoinExchange::left_pad(const size_t n, size_t final_length) const
{
	size_t	digits = 1;
	size_t	tmp = n;

	while (tmp >= 10) {
		tmp /= 10;
		++digits;
	}

	if (digits > final_length)
		return "";
	else if (digits == final_length)
		return int_to_str(n);

	string	padding;
	do {
		padding.insert(padding.begin(), '0');
	} while (--final_length - digits);

	return padding + int_to_str(n);
}

const string		BitcoinExchange::join_date(const struct s_date &date) const
{
	std::ostringstream	stream;
	stream << date.year << '-' << left_pad(date.month, 2) << '-' << left_pad(date.day, 2);
	return stream.str();
}

bool				BitcoinExchange::has_31_days(const u_int8_t month) const
{
	return (month == 1 \
			|| month == 3 \
			|| month == 5 \
			|| month == 7 \
			|| month == 8 \
			|| month == 10 \
			|| month == 12);
}

// Returns an empty string date is the lowest found
const string		BitcoinExchange::decrement_date(const string &date) const
{
	if (date == this->_lowest_date)
		return "";

	struct s_date	split = split_date(date);

	if (split.day > 1) {
		--split.day;
		return join_date(split);
	}

	if (split.month > 1) {
		--split.month;
		if (split.month == 2)
			split.day = is_leap_year(split.year) ? 29 : 28;
		else if (has_31_days(split.month))
			split.day = 31;
		else
			split.day = 30;

		return join_date(split);
	}

	split.day = 31;
	split.month = 12;
	--split.year;

	return join_date(split);
}

// Returns an empty string if no nearest date is found
const string		BitcoinExchange::find_nearest_date(const t_db &db, string date) const
{
	while (db.find(date) == db.end()) {
		date = decrement_date(date);
		if (date.empty())
			return "";
	}
	return date;
}

void				BitcoinExchange::validate_value(const string &value) const
{
	for (size_t i = 0; i < value.length(); i++)
		if (!isdigit(value[i]) \
			&& value[i] != '-' \
			&& value[i] != '.')
			throw("bad value: " + value);

	double	n;
	if (value.find('.') == string::npos)
		n = static_cast<double>(atoi(value.c_str()));
	else
		n = static_cast<double>(atof(value.c_str()));

	if (!(0 <= n && n <= 1000))
		throw(value + " is not a value in range [0, 1000]");
}

// Splits input db's line into a date and value(optional)
bool				BitcoinExchange::split_line(const string &line, string &date, string &value) const
{
	if (line.find('|') == string::npos \
		|| n_occurences(' ', line) != 2)
		return false;

	std::istringstream	stream(line);

	std::getline(stream, date, '|');
	date.erase(--date.end()); // Remove following whitespace

	std::getline(stream, value, '|');
	value.erase(value.begin()); // Remove trailing whitespace

	if (date.empty() || value.empty())
		return false;

	return true;
}

// Takes in line, splits it into date_str and value and checks if they're valid
void				BitcoinExchange::validate_line(const string &line, string &date, string &value) const
{
	if (!split_line(line, date, value))
		throw("bad input => " + line);

	if (!is_valid_date(date))
		throw("bad date => " + date);

	struct s_date	lowest_split = split_date(this->_lowest_date);
	struct s_date	split = split_date(date);

	if (split.year < lowest_split.year \
		|| \
		(split.year == lowest_split.year \
		&& (split.month < lowest_split.month \
		|| \
		(split.month == lowest_split.month \
		&& split.day < lowest_split.day))))
		throw(date + " is prior to lowest date in csv");

	validate_value(value);
}

// Remove terminating CR if it exists
inline void			BitcoinExchange::terminate_string(string &str) const
{
	if (!str.empty() \
		&& *(--str.end()) == 13)
		str.erase(--str.end());
}

const t_db			BitcoinExchange::parse_subject_db(const string &filename)
{
	std::ifstream	in_file_stream;
	open_file(in_file_stream, filename);

	string	line;
	t_db	db;
	bool	first_line = true;
	bool	second_line = false;
	while (std::getline(in_file_stream, line) && !line.empty()) {
		terminate_string(line);

		if (first_line) {
			if (line.compare("date,exchange_rate")) {
				in_file_stream.close();
				err_exit("Subject's database is missing first line header");
			}
			first_line = false;
			second_line = true;
			continue;
		}

		std::istringstream	stream(line);
		string				date;
		string				value;

		std::getline(stream, date, ',');
		std::getline(stream, value, ',');

		if (second_line) {
			this->_lowest_date = date;
			second_line = false;
		}

		db[date] = atof(value.c_str());
	}
	in_file_stream.close();
	return db;
}

void				BitcoinExchange::search_subject_db(string own_date, const float own_value) const
{
	std::cout << own_date;

	if (this->_subject_db.find(own_date) == this->_subject_db.end()) {
		own_date = find_nearest_date(this->_subject_db, own_date);
		if (own_date.empty())
			std::cout << RED << " no nearest date" << WHITE << std::endl;
		std::cout << RED << " => " << WHITE;
	}
	else
		std::cout << GREEN << " => " << WHITE;

	const float subject_value = this->_subject_db.at(own_date);
	std::cout << own_value << " => " << own_value * subject_value << std::endl;
}

// Parses input db line by line, validates it, checks for a match in subject's db
// and displays result or error
void				BitcoinExchange::parse_own_db(const string &filename) const
{
	std::ifstream	in_file_stream;
	open_file(in_file_stream, filename);

	string	line;
	bool	first_line = true;
	while (std::getline(in_file_stream, line)) {
		if (line.empty())
			continue;

		terminate_string(line);

		if (first_line) {
			if (line.compare("date | value")) {
				in_file_stream.close();
				err_exit("Input database is missing first line \"date | value\" header");
			}
			first_line = false;
			continue;
		}

		string	date;
		string	value_str;
		try {
			validate_line(line, date, value_str);

			const float value = atof(value_str.c_str());

			search_subject_db(date, value);
		} catch (string &e) {
			std::cout << RED << "Error: " << WHITE << e << std::endl;
		}
	}
	in_file_stream.close();
}
