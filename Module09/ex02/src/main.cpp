#include "PmergeMe.hpp"

// static void	test(const string &expression, const string &expected)
// {
// 	std::cout << BLUE << "\"" << expression << "\"" << WHITE << " expected ";
// 	std::cout << BLUE << expected << WHITE << std::endl;
// 	RPN	rpn(expression);
// 	std::cout << std::endl;
// }

// static void	run_tests(void)
// {
// 	std::cout << YELLOW << "Testing:" << WHITE << std::endl;

// 	test("8 9 * 9 - 9 - 9 - 4 - 1 +", "42");
// 	test("7 7 * 7 -", "42");
// 	test("1 2 * 2 / 2 * 2 4 - +", "0");
// 	test("(1 + 1)", "Error");

// 	test("1 2 * 2 / 2 * 2 -4 - +", "8");

// 	test("", "Error");
// 	test("- 7 7 * 7 -", "Error");
// 	test("- 7 7 * 7", "Error");
// 	test("7 7 * 7 - /", "Error");
// }

int	main(int argc, char **argv)
{
	if (argc < 2) {
		std::cerr << "Usage: ./PmergeMe <expression>" << std::endl;
		return EXIT_FAILURE;
	}

	// std::cout << "Before: " << argv[1] << std::endl;

	try {
		std::vector<size_t>	input;

		for (int i = 1; i < argc; i++) {
			const string	tmp(argv[i]);

			for (size_t j = 0; j < tmp.length(); j++)
				if (!isdigit(tmp[j]))
					throw std::runtime_error("Bad input: " + tmp);

			input.push_back(atol(tmp.c_str()));
		}

		for (std::vector<size_t>::iterator it = input.begin(); it != input.end(); it++)
			std::cout << *it << std::endl;


		PmergeMe	pmergeme(input);
		pmergeme.split_vec();
	// 	pmergeme.sort();

	} catch (std::exception &e) {
		std::cout << RED << "Error: " << WHITE << e.what() << std::endl;
	}


	// std::cout << "After: " << argv[1] << std::endl;


/*
	X -> input
	n -> num of elements

	1. Group X into n/2 pairs of elements, if n is odd, leave one unpaired
	2. Perform n/2 comparisons, one per pair, to determine the largest in each pair
	3. Recursively sort the n/2 larger elements from each pair, creating
		a sorted sequence S of n/2 e
	4. Insert at the start of S the element that was paired with the first and smallest element of S.
	5. Insert the remaining n/2 - 1 elements os X \ S into S, one at a time,
*/

	// run_tests();

	return EXIT_SUCCESS;
}

// void	merge_sort(size_t arr[], size_t start, size_t end)
// {
// 	if (end > start) {
// 		size_t	mid = start + (end - start) / 2;

// 		merge_sort(arr, start, mid);
// 		merge_sort(arr, mid + 1, end);
// 		merge(arr, start, mid, end);
// 	}
// }
