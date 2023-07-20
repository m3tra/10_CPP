#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) : _vec(other._vec), _deq(other._deq) {}

PmergeMe::~PmergeMe() {}

PmergeMe& PmergeMe::operator=(const PmergeMe &other)
{
	this->_vec = other._vec;
	this->_deq = other._deq;
	return *this;
}



void	PmergeMe::sort_vec(const size_t start, const size_t end)
{
	if (end - start + 1 <= 2)
		this->insert_vec(start, end);
	else if (end - start > 1) {
		this->sort_vec(start, start + ((end - start) / 2));
		this->sort_vec(start + ((end - start) / 2) + 1, end);
		this->merge_vec(start, end);
	}
}

void	PmergeMe::insert_vec(const size_t start, const size_t end)
{
	size_t	tmp;

	for (size_t i = start + 1; i <= end; i++) {
		for (size_t j = i; j > start; j--) {
			if (this->_vec[j - 1] <= this->_vec[j])
				break;
			else {
				tmp = this->_vec[j];
				this->_vec[j] = this->_vec[j - 1];
				this->_vec[j - 1] = tmp;
			}
		}
	}
}

void	PmergeMe::merge_vec(const size_t start, const size_t end)
{
	std::vector<size_t>	tmp;
	size_t				small = start;
	size_t				split = start + ((end - start) / 2) + 1;
	size_t				big = split;

	while (small < split && big <= end) {
		if (this->_vec[small] < this->_vec[big])
			tmp.push_back(this->_vec[small++]);
		else
			tmp.push_back(this->_vec[big++]);
	}

	while (small < split)
		tmp.push_back(this->_vec[small++]);

	while (big <= end)
		tmp.push_back(this->_vec[big++]);

	for (size_t i = 0; i < end - start + 1; i++)
		this->_vec[start + i] = tmp[i];
}

void	PmergeMe::sort_deq(const size_t start, const size_t end)
{
	if (end - start + 1 <= 2)
		this->insert_deq(start, end);
	else if (end - start > 1) {
		this->sort_deq(start, start + ((end - start) / 2));
		this->sort_deq(start + ((end - start) / 2) + 1, end);
		this->merge_deq(start, end);
	}
}

void	PmergeMe::insert_deq(const size_t start, const size_t end)
{
	size_t	tmp;

	for (size_t i = start + 1; i <= end; i++) {
		for (size_t j = i; j > start; j--) {
			if (this->_deq[j - 1] <= this->_deq[j])
				break;
			else {
				tmp = this->_deq[j];
				this->_deq[j] = this->_deq[j - 1];
				this->_deq[j - 1] = tmp;
			}
		}
	}
}

void	PmergeMe::merge_deq(const size_t start, const size_t end)
{
	std::deque<size_t>	tmp;
	size_t				small = start;
	size_t				split = start + ((end - start) / 2) + 1;
	size_t				big = split;

	while (small < split && big <= end) {
		if (this->_deq[small] < this->_deq[big])
			tmp.push_back(this->_deq[small++]);
		else
			tmp.push_back(this->_deq[big++]);
	}

	while (small < split)
		tmp.push_back(this->_deq[small++]);

	while (big <= end)
		tmp.push_back(this->_deq[big++]);

	for (size_t i = 0; i < end - start + 1; i++)
		this->_deq[start + i] = tmp[i];
}

void	PmergeMe::add_element(const size_t elem)
{
	this->_vec.push_back(elem);
	this->_deq.push_back(elem);
}

void	PmergeMe::print_vec() const
{
	std::vector<size_t>::const_iterator	it;
	for (it = this->_vec.begin(); it != this->_vec.end(); it++)
		std::cout << *it << " ";
}

void	PmergeMe::print_deq() const
{
	std::deque<size_t>::const_iterator	it;
	for (it = this->_deq.begin(); it != this->_deq.end(); it++)
		std::cout << *it << " ";
}

void	PmergeMe::print_time() const
{
	double	time_taken = (_vec_end.tv_sec - _vec_start.tv_sec) * 1e6;
	time_taken = (time_taken + (_vec_end.tv_usec - _vec_start.tv_usec)) * 1e-6;
	std::cout << "Time to process a range of " << this->_vec.size() << " elements with ";
	std::cout << GREEN << "std::vector: " << WHITE << time_taken << std::setprecision(6);
	std::cout << "s" << std::endl;

	time_taken = (_deq_end.tv_sec - _deq_start.tv_sec) * 1e6;
	time_taken = (time_taken + (_deq_end.tv_usec - _deq_start.tv_usec)) * 1e-6;
	std::cout << "Time to process a range of " << this->_deq.size() << " elements with ";
	std::cout << GREEN << "std::deque: " << WHITE << time_taken << std::setprecision(6);
	std::cout << "s" << std::endl;
}

void	PmergeMe::sort()
{
	gettimeofday(&(this->_vec_start), NULL);
	if (this->_vec.size() > 1)
		this->sort_vec(0, this->_vec.size() - 1);
	gettimeofday(&(this->_vec_end), NULL);

	gettimeofday(&this->_deq_start, NULL);
	if (this->_deq.size() > 1)
		this->sort_deq(0, this->_deq.size() - 1);
	gettimeofday(&this->_deq_end, NULL);
}
