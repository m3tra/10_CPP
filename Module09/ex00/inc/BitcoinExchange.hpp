#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include "color.hpp"

# include <fstream>
# include <iostream>
# include <string>
# include <cstring>

# include <sstream>
# include <map>

# include <stdlib.h>

using std::string;

bool	is_number(const string& s);

bool	is_valid_value(const string &value);
bool	is_valid_date(const string &date);
bool	is_valid_line(const string &line, string &date, string &value);

#endif
