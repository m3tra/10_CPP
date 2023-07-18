#include "RPN.hpp"

static void	test(const string &expression, const string &expected)
{
	std::cout << BLUE << "\"" << expression << "\"" << WHITE << " expected ";
	std::cout << BLUE << expected << WHITE << std::endl;
	RPN	rpn(expression);
	std::cout << std::endl;
}

static void	run_tests(void)
{
	std::cout << YELLOW << "Testing:" << WHITE << std::endl;

	test("8 9 * 9 - 9 - 9 - 4 - 1 +", "42");
	test("7 7 * 7 -", "42");
	test("1 2 * 2 / 2 * 2 4 - +", "0");
	test("(1 + 1)", "Error");

	test("1 2 * 2 / 2 * 2 -4 - +", "8");

	test("", "Error");
	test("- 7 7 * 7 -", "Error");
	test("- 7 7 * 7", "Error");
	test("7 7 * 7 - /", "Error");
}

int	main(int argc, char **argv)
{
	if (argc != 2) {
		std::cerr << "Usage: ./RPN <expression>" << std::endl;
		return EXIT_FAILURE;
	}

	RPN	rpn(argv[1]);

	run_tests();

	return EXIT_SUCCESS;
}
