/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 04:09:53 by fporto            #+#    #+#             */
/*   Updated: 2022/11/22 09:47:47 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.hpp"

bool	isChar = false;
bool	isInt = false;
bool	isFloat = false;
bool	isDouble = false;

bool	isPseudo = false;
bool	isInf = false;
bool	isNan = false;

bool	isNeg = false;

bool	impI = false;
bool	impF = false;
bool	impD = false;
bool	nonC = false;

static bool	ischarliteral(const char* str) {
	if (strlen(str) == 1 && isprint(str[0]) && !isdigit(str[0]))
		return true;
	return false;
}

static bool	isintliteral(const char* str) {
	for (size_t i = 0; str[i]; i++) {
		if (i == 0 && (str[i] == '-' || (isdigit(str[i]) && str[i] != '0')))
			continue;
		if (!isdigit(str[i]))
			return false;
	}
	return true;
}

static bool	isfloatliteral(const char* str) {
	bool	neg = false;
	bool	point = false;

	for (size_t i = 0; str[i]; i++) {
		if (i == 0 && str[i] == '-') {
			neg = true;
			continue;
		}
		if (str[i] == '.') {
			if (point)
				return false;
			point = true;
			continue;
		}
		if (!isdigit(str[i]) && i == strlen(str) - 1 && str[i] == 'f') {
			isNeg = neg;
			return true;
		}
		if (!isdigit(str[i]))
			return false;
	}
	isNeg = neg;
	isDouble = true;
	return false;
}

static bool	ispseudoliteral(const char* str) {
	bool	neg = false;

	for (size_t i = 0; str[i]; i++) {
		if (i == 0) {
			if (str[i] == 'n' && str[i + 1] == 'a' && str[i + 2] == 'n' && \
					(!str[i + 3] || (str[i + 3] == 'f' && !str[i + 4]))) {
				isNan = true;
				isNeg = neg;
				return true;
			}
			if (str[i] == '-') {
				neg = true;
				continue;
			}
		}
		if (str[i] == 'i' && str[i + 1] == 'n' && str[i + 2] == 'f' && \
				(!str[i + 3] || (str[i + 3] == 'f' && !str[i + 4]))) {
			isInf = true;
			isNeg = neg;
			return true;
		}
	}
	return false;
}

static void	checkOverflows(long double tmp) {
	if (tmp < std::numeric_limits<int>::min() || tmp > std::numeric_limits<int>::max())
		impI = true;
	if (tmp < std::numeric_limits<float>::min() || tmp > std::numeric_limits<float>::max())
		impF = true;
	if (tmp < std::numeric_limits<double>::min() || tmp > std::numeric_limits<double>::max())
		impD = true;
}

static void	printPseudo(bool isF) {
	if (isInf) {
		if (isNeg)
			std::cout << '-';
		else
			std::cout << '+';
		std::cout << "inf";
	}
	else
		std::cout << "nan";
	if (isF)
		std::cout << "f";
}

int			main(int argc, char **argv) {
	if (argc > 2) {
		std::cout << "Too many arguments" << std::endl;
		return 1;
	} else if (!argv[1]) {
		std::cout << "No argument given" << std::endl;
		return 2;
	}

	if (!strcmp(argv[1], "")) {
		std::cout << "Empty argument" << std::endl;
		return 3;
	}

	// std::cout << "arg: " << argv[1] << std::endl;

	const char	*str = argv[1];
	char		c;
	int			i;
	float		f;
	double		d;
	double		tmp;

	if (ischarliteral(str)) {
		isChar = true;
		c = str[0];
		i = static_cast<int>(c);
		f = static_cast<float>(i);
		d = static_cast<double>(f);
	} else if (ispseudoliteral(str)) {
		isPseudo = true;
	} else {
		tmp = strtod(str, NULL);
		checkOverflows(tmp);

		// std::cout << "impI: " << impI << std::endl;
		// std::cout << "impF: " << impF << std::endl;
		// std::cout << "impD: " << impD << std::endl;
		// std::cout << "isPseudo: " << isPseudo << std::endl;

		if (isintliteral(str)) {
			isInt = true;
			if (!impI)
				i = static_cast<int>(tmp);
			if (!impF || i == 0)
				f = static_cast<float>(i);
			if (!impD || i == 0)
				d = static_cast<double>(i);
		} else if (isfloatliteral(str)) {
			isFloat = true;
			if (!impF)
				f = static_cast<float>(tmp);
			if (!impI)
				i = static_cast<int>(f);
			d = tmp;
		} else if (isDouble) {
			d = tmp;
			if (!impI)
				i = static_cast<int>(d);
			if (!impF)
				f = static_cast<float>(d);
		} else {
			std::cout << "Argument is not a literal" << std::endl;
			return 4;
		}
	}

	// std::cout << "isChar: " << isChar << std::endl;
	// std::cout << "isInt: " << isInt << std::endl;
	// std::cout << "isFloat: " << isFloat << std::endl;
	// std::cout << "isDouble: " << isDouble << std::endl;
	// std::cout << "isPseudo: " << isPseudo << std::endl;
	// std::cout << "isInf: " << isInf << std::endl;
	// std::cout << "isNan: " << isNan << std::endl;
	// std::cout << "isNeg: " << isNeg << std::endl;
	// std::cout << std::endl;

	std::cout << "char: ";
	if (isPseudo || isNeg)
		std::cout << IMPOSSIBLE;
	else if (impI || i < 33 || i > 126)
		std::cout << NOT_DISP;
	else if (i >= 33 && i <= 126)
		std::cout << '\'' << static_cast<char>(i) << '\'';
	else
		std::cout << '\'' << c << '\'';
	std::cout << std::endl;


	std::cout << "int: ";
	if (impI)
		std::cout << "overflow";
	else if (isPseudo)
		std::cout << IMPOSSIBLE;
	else
		std::cout << i;
	std::cout << std::endl;


	std::cout << "float: ";
	if (impF && i != 0)
		std::cout << "overflow";
	else if (isPseudo) {
		printPseudo(true);
	} else {
		std::cout << f;
		if (f - i == 0)
			std::cout << ".0";
		std::cout << "f";
	}
	std::cout << std::endl;


	std::cout << "double: ";
	if (impD && i != 0)
		std::cout << "overflow";
	else if (isPseudo) {
		printPseudo(false);
	} else {
		std::cout << tmp;
		if (d - i == 0)
			std::cout << ".0";
	}
	std::cout << std::endl;

	return 0;
}
