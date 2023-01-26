/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 20:41:50 by fporto            #+#    #+#             */
/*   Updated: 2023/01/26 12:34:42 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include "Color.hpp"

using std::string;

int	main(int argc, char** argv) {
	if (argc != 4) {
		std::cout << RED << "Wrong number of args" << WHITE << std::endl;
		std::cout << "Usage: ./Winner <filename> <str1> <str2>" << std::endl;
		std::cout << "<str1>: string to replace" << std::endl;
		std::cout << "<str2>: replacement" << std::endl;
		return (1);
	}

	std::fstream	inFile;
	std::fstream	outFile;

	string	outFileName = argv[1];
	outFileName.append(".replace");

	inFile.open(argv[1], std::ios::in);
	if (!inFile.is_open()) {
		std::cout << RED << "Failed to open " WHITE;
		std::cout << argv[1];
		std::cout << std::endl;
		return (1);
	}

	outFile.open(outFileName.c_str(), std::ios::out);
	if (!outFile.is_open()) {
		std::cout << RED << "Failed to create " << WHITE;
		std::cout << outFileName;
		std::cout << std::endl;
		inFile.close();
		return (1);
	}

	string	line;
	string	str1 = argv[2];
	string	str2 = argv[3];

	while (getline(inFile, line)) {
		size_t	pos = 0;

		line.append("\n");
		do {
			pos = line.find(str1);
			if (pos == string::npos) // No matches were found
				break;

			line.erase(pos, str1.length()); // Erase part of the string
			if (!str2.empty())
				line.insert(pos, str2); // Insert inplace new part of string

		} while (pos != string::npos);
		outFile << line; // Append processed content (line) to outFile
	}

	inFile.close();
	outFile.close();

	return (0);
}
