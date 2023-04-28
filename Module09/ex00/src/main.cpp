#include "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	std::fstream	inFile;

	inFile.open(argv[1], std::ios::in);
	if (!inFile.is_open()) {
		std::cout << RED << "Error: ";
		std::cout << WHITE << "Failed to open " << argv[1];
		std::cout << std::endl;
		return (1);
	}

	// lines must format must be "date | value"


	// date format must be Year-Month-Day



	// value must be float or a positive integer between 0 and 1000



	// map as container?



	/*
	program should display on stdout the result of the value multiplied
	by the exchange rate according to the date indicated in your database.

	If the date used in the input does not exist in your DB then you
	must use the closest date contained in your DB. Be careful to use the
	lower date and not the upper one.
	*/

}
