#include "BitcoinExchange.hpp"

void	run_tests(void)
{
	std::cout << YELLOW << "Testing:" << WHITE << std::endl;
	{
		std::cout << BLUE << "format.txt" << WHITE << std::endl;
		BitcoinExchange exchange("tests/format.txt");
	}
	{
		std::cout << BLUE << "year.txt" << WHITE << std::endl;
		BitcoinExchange exchange("tests/year.txt");
	}
	{
		std::cout << BLUE << "month.txt" << WHITE << std::endl;
		BitcoinExchange exchange("tests/month.txt");
	}
	{
		std::cout << BLUE << "day.txt" << WHITE << std::endl;
		BitcoinExchange exchange("tests/day.txt");
	}
	{
		std::cout << BLUE << "value.txt" << WHITE << std::endl;
		BitcoinExchange exchange("tests/value.txt");
	}
}

// Green arrow	-> Direct date match
// Red arrow	-> Lower date match
int	main(int argc, char **argv)
{
	if (argc != 2) {
		std::cerr << "Usage: ./btc <second database>" << std::endl;
		return EXIT_FAILURE;
	}

	BitcoinExchange exchange(argv[1]);

	run_tests();

	return EXIT_SUCCESS;
}
