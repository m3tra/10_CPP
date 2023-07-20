#include "PmergeMe.hpp"

void	parse_input(PmergeMe &pmergeme, const int argc, char **argv) throw(std::runtime_error)
{
	for (int i = 1; i < argc; i++) {
		const string	tmp(argv[i]);

		for (size_t j = 0; j < tmp.length(); j++)
			if (!isdigit(tmp[j]))
				throw std::runtime_error("Bad input: " + tmp);

		pmergeme.add_element(static_cast<size_t>(atol(tmp.c_str())));
	}
}

int	main(int argc, char **argv)
{
	if (argc < 2) {
		std::cerr << "Usage: ./PmergeMe <sequence>" << std::endl;
		return EXIT_FAILURE;
	}

	try {
		PmergeMe	pmergeme;

		parse_input(pmergeme, argc, argv);

		std::cout << BLUE << "Before: " << WHITE;
		pmergeme.print_vec();
		std::cout << std::endl << std::endl;

		pmergeme.sort();

		std::cout << BLUE <<  "After: " << WHITE;
		pmergeme.print_vec();
		std::cout << std::endl;

		pmergeme.print_time();
	} catch (std::exception &e) {
		std::cout << RED << "Error: " << WHITE << e.what() << std::endl;
	}

	// run_tests();

	return EXIT_SUCCESS;
}
