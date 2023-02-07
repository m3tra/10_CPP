#include "Span.hpp"

// void	tests() {
// 	srand(time(NULL));
// }

int	main() {
	std::cout << ORANGE "Given code" WHITE << std::endl;
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
	std::cout << std::endl;


	std::cout << ORANGE "Before insert" WHITE << std::endl;
	sp.printArray();

	int	arr[] = { 5, 9, 13, 6, 93, 7};
	std::vector<int> vec(arr, arr + sizeof(arr) / sizeof(arr[0]));

	// Set first part of inserting segment to middle position
	std::vector<int>::iterator it = vec.begin();
	for (size_t i = 0; i < vec.size() / 2; i++) {
		it++;
	}
	std::vector<int>::iterator it2 = vec.end();
	sp.addRange(it, it2);

	std::cout << ORANGE "After insert" WHITE << std::endl;
	sp.printArray();

	std::cout << PURPLE "*" WHITE;
	std::cout << "inserted from middle element onward at end of Span (hardcoded but changeable)";
	std::cout << PURPLE "*" WHITE << std::endl;

	return 0;
}
