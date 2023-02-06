#include "Span.hpp"

// void	tests() {
// 	srand(time(NULL));
// }

int	main() {
	Span sp = Span(5);
	try {
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
	} catch (Span::AddException &e) {
		std::cerr << RED << e.what() << WHITE << std::endl;
	}

	try {
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	} catch (Span::SpanException &e) {
		std::cerr << RED << e.what() << WHITE << std::endl;
	}

	std::vector<int> vec = { 5, 9, 13, 6, 93, 7};

	sp.

	return 0;
}
