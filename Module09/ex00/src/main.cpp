#include "BitcoinExchange.hpp"

void	err_exit(const char *error)
{
	std::cout << RED << "Error: ";
	std::cout << WHITE << error << std::endl;
	exit(EXIT_FAILURE);
}

void	err_exit(const string &error)
{
	std::cout << RED << "Error: ";
	std::cout << WHITE << error << std::endl;
	exit(EXIT_FAILURE);
}

void	check_csv(const char *filename)
{
	const string	name = filename;

	if (name.length() < 5 \
		|| name.find(".csv") == string::npos
	) {
		std::ostringstream stream;
		stream << "Wrong file format: " << name;
		err_exit(stream.str());
	}
}

void	open_file(std::ifstream &in_file_stream, const char *filename)
{
	in_file_stream.open(filename, std::ios::in);
	if (!in_file_stream.is_open()) {
		std::ostringstream	error;
		error << "Failed to open " << filename;
		err_exit(error.str());
	}
}

int	main(int argc, char **argv)
{
	if (argc != 2) {
		std::cout << "Usage: ./btc <second database>" << std::endl;
		return 1;
	}


	const t_db	own_db = parse_own_db(argv[1]);
	const t_db	provided_db = parse_subject_db("data.csv");

	// input file's line format must be "date | value"
	// CHECK

	// date format must be Year-Month-Day
	// CHECK


	// value must be float or a positive integer between 0 and 1000
	// CHECK


	// map as container?
	// Yuh



	/*
	program should display on stdout the result of the value multiplied
	by the exchange rate according to the date indicated in your database.

	If the date used in the input does not exist in your DB then you
	must use the closest date contained in your DB. Be careful to use the
	lower date and not the upper one.
	*/

	return EXIT_SUCCESS;
}
