#include "ScalarConverter.hpp"
#include <string>
#include <iostream>

int	ScalarConverter::detectLiteralType(const std::string& str)
{
	if (isLiteralFloat(str))
		return (LITERAL_FLOAT);
	if (isLiteralDouble(str))
		return (LITERAL_DOUBLE);
	if (isLiteralInt(str))
		return (LITERAL_INT);
	if (isLiteralChar(str))
		return (LITERAL_CHAR);
	return (LITERAL_NONE);
}

void	ScalarConverter::convertNone(void)
{
	std::cout << "char: impossible\n";
	std::cout << "int: impossible\n";
	std::cout << "float: impossible\n";
	std::cout << "double: impossible\n";
}

void	ScalarConverter::convert(const std::string& str)
{
	switch (detectLiteralType(str))
	{
	case LITERAL_NONE:
		convertNone();
		break;
	case LITERAL_CHAR:
		CONVERT_CHAR_TO_ALL_TYPES(char, str);
		break;
	case LITERAL_INT:
		CONVERT_INT_DOUBLE_TO_ALL_TYPES(int, str);
		break;
	case LITERAL_FLOAT:
		CONVERT_FLOAT_TO_ALL_TYPES(float, str);
		break;
	case LITERAL_DOUBLE:
		CONVERT_INT_DOUBLE_TO_ALL_TYPES(double, str);
		break;
	default:
		break;
	}
}

ScalarConverter::ScalarConverter(void)
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &orig)
{
	(void)orig;
}

ScalarConverter::~ScalarConverter(void)
{
}

ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &orig)
{
	(void)orig;
	return (*this);
}
