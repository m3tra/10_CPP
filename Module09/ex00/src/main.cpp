#include "BitcoinExchange.hpp"

bool	is_csv(const char *filename)
{
	const string	name = filename;

	if (name.length() < 5 ||
		name.find(".csv") == string::npos
	)
		return (false);
	return (true);
}

int	main(int argc, char **argv)
{
	std::ifstream	in_file_stream;

	if (argc != 2) {
		std::cout << "Usage: ./btc <database>" << std::endl;
		return (1);
	}

	in_file_stream.open(argv[1], std::ios::in);
	if (!in_file_stream.is_open()) {
		std::cout << RED << "Error: ";
		std::cout << WHITE << "Failed to open " << argv[1];
		std::cout << std::endl;
	}

	string	line;
	std::map<string, float> input;
	while (std::getline(in_file_stream, line)) {
		string	date;
		string	value;

		// Properly terminate string (remove terminating CR)
		line.erase(--line.end());

		// if (line[line.length()] == '\0')
		// 	std::cout << "line is NULL terminated" << std::endl;

		if (!is_valid_line(line, date, value)) {
			std::cout << RED << "Error: ";
			std::cout << WHITE << "Bad format: ";
			std::cout << line << std::endl;
			std::cout << std::endl;
			// std::cout << "date: |" << date << "|" << std::endl;
			// std::cout << std::endl;
			// std::cout << "value: |" << value << "|" << std::endl;
			return (1);
		}

		input[date] = atof(value.c_str());
		// std::cout << "date: |" << date << "|" << std::endl;
		// std::cout << "value: |" << value << "|" << std::endl;
		// std::cout << std::endl << std::endl;
	}

	try {
		std::map<string, float> database = intake_db("data.csv");
	}
	catch (const char *error) {
		std::cout << RED << "Error: ";
		std::cout << WHITE << error << std::endl;
	}

	// input file's line format must be "date | value"
	// CHECK

	// date format must be Year-Month-Day
	// CHECK


	// value must be float or a positive integer between 0 and 1000
	// CHECK


	// map as container?



	/*
	program should display on stdout the result of the value multiplied
	by the exchange rate according to the date indicated in your database.

	If the date used in the input does not exist in your DB then you
	must use the closest date contained in your DB. Be careful to use the
	lower date and not the upper one.
	*/

	in_file_stream.close();

	return (0);
}
