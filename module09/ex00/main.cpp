#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

const std::string	firstColumn = "date";
const std::string	secondColumn = "value";

void	printPriceAt(const BitcoinExchange &bx, const std::string &date, const std::string &amount)
{
	time_t	dateVal;
	float	amountVal;
	float	price;
	float	totalPrice;

	dateVal = bx.parseDate(date);
	amountVal = bx.parseNumber(amount);
	if (amountVal < 0)
	{
		std::stringstream	buf;

		buf << "value " << amountVal << " is negative.";
		throw (std::runtime_error(buf.str()));
	}
	price = bx.getPrice(dateVal);
	totalPrice = amountVal * price;
	std::cout << date << " => " << amount << " = " << " " << totalPrice << "\n";
}

void	processLine(const BitcoinExchange &bx, std::ifstream &file)
{
	std::string			line;
	std::stringstream	buf;
	std::string			first;
	std::string			delim;
	std::string			second;

	std::getline(file, line);
	buf.str(line);
	buf >> first;
	buf >> delim;
	buf >> second;
	if (delim != "|" || first.length() == 0 || second.length() == 0)
		throw (std::runtime_error(std::string("Invalid line ") + line));
	if (first == firstColumn && second == secondColumn)
		return ;
	printPriceAt(bx, first, second);
}

void	process(const BitcoinExchange &bx, const std::string &filepath)
{
	std::ifstream	file;

	file.open(filepath, std::ios_base::in);
	if (!file.is_open())
		throw (std::ifstream::failure(std::string("Failed to open ") + filepath));
	while (!file.eof())
	{
		try
		{
			processLine(bx, file);
		}
		catch (const std::runtime_error &e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}
}

int	main(int argc, char **argv)
{
	BitcoinExchange	bx;

	if (argc != 2)
		return (1);
	try
	{
		process(bx, argv[1]);
	}
	catch (const std::ifstream::failure &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return (0);
}
