/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 20:41:50 by fporto            #+#    #+#             */
/*   Updated: 2022/08/03 00:24:03 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

using std::string;

int	main(int argc, char** argv) {
	if (argc != 4) {
		std::cout << "Usage: ./Winner <filename> <str1> <str2>" << std::endl;
		std::cout << "<str1>: string to replace\n<str2>: replacement" << std::endl;
		return (1);
	}

	std::fstream	inFile;
	std::fstream	outFile;

	string	outFileName = argv[1];
	outFileName.append(".replace");

	inFile.open(argv[1], std::ios::in);
	if (!inFile.is_open()) {
		std::cout << "Failed to open " << argv[1] << std::endl;
		return (1);
	}

	outFile.open(outFileName.c_str(), std::ios::out);
	if (!outFile.is_open()) {
		std::cout << "Failed to create " << outFileName << std::endl;
		return (1);
	}
	outFile.close();
	// outFile.open(outFileName.c_str(), std::ios::app);
	// if (!outFile.is_open()) {
	// 	std::cout << "Failed to open " << outFileName << std::endl;
	// 	return (1);
	// }

	string	line;
	string	str1 = argv[2];
	string	str2 = argv[3];

	while (getline(inFile, line)) {
		size_t	pos = 0;

		line.append("\n");
		do {
			pos = line.find(str1);
			if (pos == string::npos)
				break;

			line.erase(pos, str1.length());
			if (!str2.empty())
				line.insert(pos, str2);


		} while (pos != string::npos);
		outFile << line;
	}

	inFile.close();
	outFile.close();

	return (0);
}
