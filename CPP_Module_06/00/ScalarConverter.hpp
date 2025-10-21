#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <cctype>
#include <climits>
#include <cfloat>
#include <cstdlib>
#include <limits>
#include <iomanip>

class ScalarConverter{
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &other);
	ScalarConverter &operator=(const ScalarConverter &other);
	~ScalarConverter();

	static bool checkPseudoLiterals(const std::string &literal);
	static bool isChar(const std::string &str);
	static bool isInt(const std::string &str);
	static bool isFloat(const std::string &str);
	static bool isDouble(const std::string &str);

	static void convertFromChar(char c);
	static void convertFromInt(int n);
	static void convertFromFloat(float f);
	static void convertFromDouble(double d);

public:
	static void convert(const std::string &literal);
};

#endif
