#include "RPN.hpp"

RPN::RPN(const string &expression)
{
	try {
		if (expression.empty())
			throw RPN::BadInputError("Empty input");

		solve(expression);
	} catch (std::exception &e) {
		std::cout << RED << "Error: " << WHITE;
		std::cout << e.what() << std::endl;
	}
}

RPN::RPN(const RPN &other) : _stacc(other._stacc) {}

RPN& RPN::operator=(const RPN &other)
{
	this->_stacc = other._stacc;
	return *this;
}

RPN::~RPN() {}



inline bool	RPN::is_operator(const char c) const
{
	return (c == '+' \
			|| c == '-' \
			|| c == '*' \
			|| c == '/');
}

void	RPN::solve(const string &expression) throw(std::runtime_error)
{
	for (string::const_iterator it = expression.begin(); it != expression.end(); it++) {
		const char	c = *it;

		if (isdigit(c))
			this->_stacc.push(c - '0');
		else if (c == ' ')
			continue;
		else if (is_operator(c)) {
			if (c == '-' && it != --expression.end() && isdigit(*(it + 1))) {
				this->_stacc.push(-(*++it - '0'));
				continue;
			}
			if (this->_stacc.size() < 2)
				throw RPN::BadInputError("Missing digit before operator " + string(1, c));

			int	b = this->_stacc.top();
			this->_stacc.pop();
			int	a = this->_stacc.top();
			this->_stacc.pop();

			if (c == '+')
				this->_stacc.push(a + b);
			else if (c == '-')
				this->_stacc.push(a - b);
			else if (c == '*')
				this->_stacc.push(a * b);
			else if (c == '/')
				this->_stacc.push(a / b);
		}
		else
			throw RPN::BadInputError("Expression must be composed of digits, +, -, *, / or spaces");
	}

	if (this->_stacc.size() != 1)
		throw RPN::BadInputError("Missing operator at end of expression");

	std::cout << this->_stacc.top() << std::endl;
}

RPN::BadInputError::BadInputError(const string &err) : std::runtime_error(err) {}
