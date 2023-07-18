#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# define WHITE "\033[0m"
# define YELLOW "\033[33m"
# define RED "\033[38;5;1m"
# define ORANGE "\033[38;5;208m"
# define GREEN "\033[38;5;47m"
# define BLUE "\033[38;5;14m"
# define PURPLE "\033[38;5;13m"

# include <fstream>
# include <iostream>
# include <string>
# include <sstream>
# include <cstdlib>

# include <map>

using std::string;

# define SUBJECT_DB "data.csv"

typedef std::map<string, float> t_db;

struct s_date {
	u_int16_t	year;
	u_int8_t	month;
	u_int8_t	day;
};

class BitcoinExchange
{
private:
	t_db	_subject_db;
	string	_lowest_date;

public:
	BitcoinExchange(const string &filename);
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange& operator=(const BitcoinExchange &other);
	~BitcoinExchange();

	void				err_exit(const string &error) const;

	const string		int_to_str(const long n) const;
	const string		left_pad(const size_t n, size_t final_length) const;
	uint				n_occurences(const char c, const string &str) const;

	const string		find_nearest_date(const t_db &db, const string date) const;
	const struct s_date	split_date(const string &date) const;
	const string		join_date(const struct s_date&) const;
	bool				has_31_days(const u_int8_t month) const;
	const string		decrement_date(const string &date) const;
	bool				is_leap_year(const u_int16_t year) const;

	bool				split_line(const string &line, string &date_str, string &value) const;
	void				validate_value(const string &value) const;
	bool				is_valid_date(const string &date_str) const;
	void				validate_line(const string &line, string &date, string &value) const;

	void				open_file(std::ifstream &in_file_stream, const string &filename) const;
	inline void			terminate_string(string &str) const;

	void				parse_own_db(const string &filename) const;
	const t_db			parse_subject_db(const string &filename);
	void				search_subject_db(string own_date, const float own_value) const;
};

#endif
