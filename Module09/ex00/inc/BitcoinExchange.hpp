#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include "color.hpp"

# include <fstream>
# include <iostream>
# include <string>

# include <sstream>
# include <vector>

using std::string;

bool	is_number(const string& s);

bool	isValidValue(string value);
bool	isValidDate(string date);
bool	isValidLine(string line);

#endif
