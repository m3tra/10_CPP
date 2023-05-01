#include "BitcoinExchange.hpp"

std::ifstream	openFile(char *filename)
{
	std::ifstream	inFile;

	inFile.open(filename, std::ios::in);
	if (!inFile.is_open()) {
		std::cout << RED << "Error: ";
		std::cout << WHITE << "Failed to open " << filename;
		std::cout << std::endl;
	}
	return (inFile);
}

int	main(int argc, char **argv)
{
	std::ifstream	inFile;

	if (argc != 2) {
		std::cout << "Usage: ./btc <database>" << std::endl;
		return (1);
	}

	inFile = openFile(argv[1]);
	if (!inFile.is_open())
		return (1);

	string	line;
	while (std::getline(inFile, line)) {
		if (!isValidLine(line)) {
			std::cout << RED << "Error: ";
			std::cout << WHITE << "Bad format: ";
			std::cout << line << std::endl;
			return (1);
		}
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

	return (0);
}
