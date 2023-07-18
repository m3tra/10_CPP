#include "PmergeMe.hpp"

PmergeMe::PmergeMe(const string &sequence) : _input_str(sequence)
{
	for (size_t i = 0; i < sequence.size(); i++) {
		const char	curr = sequence[i];

		_input_vec.push_back(sequence[i]);
	}

}

PmergeMe::PmergeMe(const PmergeMe &other) : _lst(other._lst), _queue(other._queue) {}

PmergeMe& PmergeMe::operator=(const PmergeMe &other)
{
	this->_lst = other._lst;
	this->_queue = other._queue;
	return *this;
}

PmergeMe::~PmergeMe() {}



void	PmergeMe::split_vec()
{
	std::vector< std::vector<size_t> >	pairs(_input_str.size() / 2);
	std::cout << pairs.size() << std::endl;
	std::cout << pairs.max_size() << std::endl;
}

// void	PmergeMe::insertion(std::vector<size_t> remaining)
// {

// }
