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
# include <sstream>
# include <stdexcept>
# include <sys/time.h>
# include <bits/stdc++.h>

# include <vector>
# include <deque>

using std::string;

class PmergeMe {
private:
	std::vector<size_t>	_vec;
	std::deque<size_t>	_deq;

	struct timeval		_vec_start;
	struct timeval		_vec_end;
	struct timeval		_deq_start;
	struct timeval		_deq_end;

public:
	PmergeMe();
	PmergeMe(const PmergeMe &other);
	PmergeMe& operator=(const PmergeMe &other);
	~PmergeMe();

	void	sort_vec(const size_t start, const size_t end);
	void	insert_vec(const size_t start, const size_t end);
	void	merge_vec(const size_t start, const size_t end);

	void	sort_deq(const size_t start, const size_t end);
	void	insert_deq(const size_t start, const size_t end);
	void	merge_deq(const size_t start, const size_t end);

	void	add_element(const size_t elem);
	void	print_vec() const;
	void	print_deq() const;
	void	print_time() const;
	void	sort();

};

#endif
