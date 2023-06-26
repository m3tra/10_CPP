#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include "color.hpp"

# include <fstream>
# include <iostream>
# include <string>
# include <cstring>
# include <exception>

# include <sstream>
# include <map>

# include <cstdlib>

using std::string;

typedef struct s_date
{
	unsigned int	year;
	unsigned int	month;
	unsigned int	day;
}	t_date;

t_date	split_date(const string& date);

bool	is_leap_year(unsigned int year);

bool	is_pos_number(const string& s);

bool	is_valid_value(const string &value);
bool	is_valid_date(const string &date_str);
bool	is_valid_line(const string &line, string &date, string &value);

std::map<string, float>	intake_db(const string& filename);

#endif
