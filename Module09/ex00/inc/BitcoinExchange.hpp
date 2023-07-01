#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include "color.hpp"

# include <fstream>
# include <iostream>
# include <string>
# include <sstream>
// # include <cstring>
# include <exception>

# include <map>

# include <cstdlib>

using std::string;

typedef std::map<string, float> t_db;

struct s_date {
	u_int16_t	year;
	u_int8_t	month;
	u_int8_t	day;
};

void	err_exit(const char *error);
void	err_exit(const string &error);

const string&		find_nearest_date(const t_db &db, const string &date);
const struct s_date	split_date(const string &date);
const string		join_date(const struct s_date&);

bool	is_leap_year(const u_int16_t year);
// bool	is_pos_number(const string &s);
bool	is_valid_value(const string &value);
bool	is_valid_date(const string &date_str);
bool	is_valid_line(const string &line, string &date, string &value);


void		open_file(std::ifstream &in_file_stream, const char *filename);
void		terminate_string(string &str);
const t_db	parse_own_db(const char *filename);
const t_db	parse_subject_db(const char *filename);


#endif
