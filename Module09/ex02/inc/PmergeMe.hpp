#ifndef PMERGEME_HPP
# define PMERGEME_HPP

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
// # include <sstream>
// # include <iterator>
# include <stdexcept>

# include <vector>
# include <list>
# include <deque>

using std::string;

class PmergeMe {
private:
	string				_input_str;
	std::vector<size_t>	_input_vec;
	size_t				_n_elements;

	double				_time1; // list?
	double				_time2; // deque?

	std::list<size_t>	_lst;
	std::deque<size_t>	_queue;

	std::vector<size_t>	_vec;

public:
	PmergeMe(const string &sequence);
	PmergeMe(const PmergeMe &other);
	PmergeMe& operator=(const PmergeMe &other);
	~PmergeMe();

	void	sort() throw(std::runtime_error);
	double	getTime1() const;
	double	getTime2() const;

	void	split_vec();
	void	insertion(std::vector<size_t> remaining);

	// void	solve(const string &sequence) throw(std::runtime_error);

	class BadInputError : public std::runtime_error {
	public:
		BadInputError(const string &err);
	};
};

#endif
