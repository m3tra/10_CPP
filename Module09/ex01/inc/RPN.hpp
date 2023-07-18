#ifndef RPN_HPP
# define RPN_HPP

# define WHITE "\033[0m"
# define YELLOW "\033[33m"
# define RED "\033[38;5;1m"
# define ORANGE "\033[38;5;208m"
# define GREEN "\033[38;5;47m"
# define BLUE "\033[38;5;14m"
# define PURPLE "\033[38;5;13m"

# include <iostream>
# include <string>
# include <cstdlib>
# include <iterator>
# include <stdexcept>

# include <stack>

using std::string;

class RPN {
private:
	std::stack<int>	_stacc;

public:
	RPN(const string &expression);
	RPN(const RPN &other);
	RPN& operator=(const RPN &other);
	~RPN();

	inline bool	is_operator(const char c) const;

	void		solve(const string &expression) throw(std::runtime_error);

	class BadInputError : public std::runtime_error {
	public:
		BadInputError(const string &err);
	};
};

#endif
