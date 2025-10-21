#include "ScalarConverter.hpp"

bool ScalarConverter::checkPseudoLiterals(const std::string &literal){
	return (literal == "nan" || literal == "nanf" ||
			literal == "inf" || literal == "inff" ||
			literal == "+inf" || literal == "+inff" ||
			literal == "-inf" || literal == "-inff");
}

bool ScalarConverter::isChar(const std::string &str){
	if (str.length() != 3)
		return false;
	if (str[0] != '\'' || str[2] != '\'')
		return false;
	if (!std::isprint(str[1]))
		return false;
	return true;
}

bool ScalarConverter::isInt(const std::string &str){
	bool findSign = false;
	for (int i = 0; str[i]; i++){
		if ((str[i] == '+' || str[i] == '-') && !findSign){
			i++;
			findSign = true;
		}
		if (!std::isdigit(str[i]))
			return false;
	}
	return true;
}

bool ScalarConverter::isFloat(const std::string &str){
	bool findPoint = false;
	bool findSign = false;

	for (size_t i = 0; str[i]; i++){
		if ((str[i] == '+' || str[i] == '-') && !findSign){
			i++;
			findSign = true;
		}
		if (str[i] == '.' && !findPoint){
			i++;
			findPoint = true;
		}
		if ( str[i] == '.' && !std::isdigit(str[i + 1]))
			return false;
		if (!std::isdigit(str[i]) && i != (str.length() - 1))
			return false;
	}
	if (str[str.length() - 1] != 'f' || !findPoint)
		return false;
	return true;
}

bool ScalarConverter::isDouble(const std::string &str){
	bool findPoint = false;
	bool findSign = false;

	for (int i = 0; str[i]; i++){
		if ((str[i] == '+' || str[i] == '-') && !findSign){
			i++;
			findSign = true;
		}
		if (str[i] == '.' && !findPoint){
			i++;
			findPoint = true;
		}
		if ( str[i] == '.' && !std::isdigit(str[i + 1]))
			return false;
		if (!std::isdigit(str[i]))
			return false;
	}
	if (!findPoint)
		return false;
	return true;
}

void ScalarConverter::convertFromChar(char c){
	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << std::setprecision(7) << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: " << std::setprecision(16) << static_cast<double>(c) << std::endl;
}

void ScalarConverter::convertFromInt(int n ){
	if (n < CHAR_MIN|| n > CHAR_MAX)
    	std::cout << "char: impossible" << std::endl;
	else if (std::isprint(static_cast<char>(n)))
		std::cout << "char: '" << static_cast<char>(n) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: "<< n << std::endl;
	std::cout << "float: " << std::setprecision(7) << static_cast<float>(n) << "f" << std::endl;
	std::cout << "double: " << std::setprecision(16) << static_cast<double>(n) << std::endl;

}


void ScalarConverter::convertFromFloat(float f){
	if (f < static_cast<float>(CHAR_MIN)|| f > static_cast<float>(CHAR_MAX))
    	std::cout << "char: impossible" << std::endl;
	else if (std::isprint(static_cast<char>(f)))
		std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	if (f < static_cast<float>(INT_MIN)|| f > static_cast<float>(INT_MAX))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: "<< static_cast<int>(f) << std::endl;
	std::cout << "float: " << std::setprecision(7) << f << "f" << std::endl;
	std::cout << "double: " << std::setprecision(16) << static_cast<double>(f) << std::endl;
}

void ScalarConverter::convertFromDouble(double d){
	if (d < static_cast<double>(CHAR_MIN)|| d > static_cast<double>(CHAR_MAX))
    	std::cout << "char: impossible" << std::endl;
	else if (std::isprint(static_cast<char>(d)))
		std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	if (d < static_cast<double> (INT_MIN)|| d > static_cast<double>(INT_MAX))
    	std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: "<< static_cast<int>(d) << std::endl;
	if (d <  static_cast<double>(-FLT_MAX) || d > static_cast<double> (FLT_MAX))
    	std::cout << "float:  impossible" << std::endl;
	else
		std::cout << "float: " << std::setprecision(7) << static_cast<float>(d) << "f" << std::endl;
	std::cout << "double: " << std::setprecision(16) << d << std::endl;

}

void convertPseudoLiterals(const std::string &literal){
	double d = 0.0;
	if (literal == "nan" || literal == "nanf")
		d = std::numeric_limits<double>::quiet_NaN();
	else if (literal == "inf" || literal == "+inf" ||
			 literal == "inff" || literal == "+inff")
		d = std::numeric_limits<double>::infinity();
	else if (literal == "-inf" || literal == "-inff")
		d = -std::numeric_limits<double>::infinity();
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (literal.find('f') != std::string::npos)
		std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
	else
		std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}

void ScalarConverter::convert(const std::string &literal){

	if (checkPseudoLiterals(literal))
		convertPseudoLiterals(literal);
	if (isChar(literal))
		convertFromChar(literal[1]);
	else if (isInt(literal))
		convertFromInt(atoi(literal.c_str()));
	else if (isFloat(literal))
		convertFromFloat(strtof(literal.c_str(), NULL));
	else if (isDouble(literal)){
		convertFromDouble(atof(literal.c_str()));
	}}
