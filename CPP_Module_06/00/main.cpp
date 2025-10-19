#include "ScalarConverter.hpp"



int main(){

	ScalarConverter::convert("+inf");
	ScalarConverter::convert("'c'");
	ScalarConverter::convert("700");
	ScalarConverter::convert("67.00349666666666666f");
	ScalarConverter::convert("nanf");
	ScalarConverter::convert("123.123123");
	return 0;

}
