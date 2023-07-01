#include "BitcoinExchange.hpp"

bool	is_leap_year(const u_int16_t year)
{
	if (year % 4 == 0) {
		return (year % 100 != 0 \
				|| (year % 100 == 0 && year % 400 == 0));
	}
	return false;
}

uint	n_of_hyphens(const string &date)
{
	uint	n = 0;
	size_t	i = 0;

	while (true) {
		i = date.find('-', i);
		if (i == string::npos)
			break;
		n++;
	}
	return n;
}

bool	is_valid_date(const string &date)
{
	if (date.empty() \
		|| n_of_hyphens(date) != 2
	)
		return false;

	const size_t	first_sep_i = date.find_first_of('-');
	const size_t	second_sep_i = date.find_last_of('-');
	if (first_sep_i == 0 \
		|| second_sep_i - first_sep_i != 2
	)
		return false;

	const uint		year = atoi(date.substr(0, first_sep_i).c_str());
	const uint		month = atoi(date.substr(first_sep_i + 1, 2).c_str());
	const uint		day = atoi(date.substr(second_sep_i + 1).c_str());

	// std::cout << "year: " << year << std::endl;
	// std::cout << "month: " << month << std::endl;
	// std::cout << "day: " << day << std::endl;

	if ((is_leap_year(year) \
		&& month == 2 \
		&& day > 29) \
		|| (!(is_leap_year(year) \
		&& month == 2 \
		&& day > 28))
	)
		return false;

	if (!(1 <= month && month <= 12 \
		&& 1 <= day && day <= 31) \
	)
		return false;

	return true;
}

const struct s_date	split_date(const string &date)
{
	struct s_date	ret = {0, 0, 0};

	if (!is_valid_date(date))
		return ret;

	const size_t	first_sep_i = date.find_first_of('-');
	const size_t	second_sep_i = date.find_last_of('-');

	ret.year = atoi(date.substr(0, first_sep_i).c_str());
	ret.month = atoi(date.substr(first_sep_i + 1, 2).c_str());
	ret.day = atoi(date.substr(second_sep_i + 1).c_str());

	return ret;
}

const string	join_date(const struct s_date &date)
{
	std::ostringstream	stream;
	stream << date.year << '-' << date.month << '-' << date.day;
	return stream.str();
}

const string	&find_nearest_date(const t_db &db, const string &date)
{
	(void)db;
	(void)date;
	return NULL;
}

bool			has_31_days(const u_int8_t month)
{
	return (month == 1 \
			|| month == 3 \
			|| month == 5 \
			|| month == 7 \
			|| month == 8 \
			|| month == 10 \
			|| month == 12);
}

const string	&decrement_date(const string &date)
{
	struct s_date	split = split_date(date);

	if (split.day != 1) {
		split.day--;
		return join_date(split);
	}

	if (split.month != 1) {
		split.month--;
		return join_date(split);
	}


	if (has_31_days(split.month))
		split.day =
	else if (split.month == 2) {
		if (is_leap_year(split.year))
			split.day = 29;
		else
			split.day = 28;
	}
	split.day = 31;
	split.month = 12;
	split.year--;
}
