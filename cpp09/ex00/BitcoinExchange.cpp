/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimolin2 <dimolin2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 15:43:20 by dimolin2          #+#    #+#             */
/*   Updated: 2024/03/08 15:43:21 by dimolin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void): _filename("")
{}

BitcoinExchange::BitcoinExchange(std::string const filename): _filename(filename)
{
	_fillInput(filename);
	if (_inputfile.size() == 0)
		throw InputFileErrorException();
	_fillData();
	if (_database.size() == 0)
		throw DatabaseErrorException();
	_exchange();
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &copy): _filename(copy._filename), _database(copy._database), _inputfile(copy._inputfile)
{}

BitcoinExchange::~BitcoinExchange(void)
{}

BitcoinExchange	&BitcoinExchange::operator=(BitcoinExchange const &copy)
{
	if (this != &copy)
	{
		_filename = copy._filename;
		_inputfile = copy._inputfile;
		_database = copy._database;
	}
	return *this;
}

int BitcoinExchange::_stoi(std::string str)
{
	int i = 0;
	int sign = 1;
	int num = 0;

	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	if (str[i] == '+')
		i++;
	while (str[i] != '\0')
	{
		if (!std::isdigit(str[i]) || str[i] == '+' || str[i] == '-')
			throw std::invalid_argument("stoi");
		num = num * 10 + str[i] - '0';
		i++;
	}
	return (num * sign);
}

float BitcoinExchange::_stof(std::string value)
{
	int i = 0;
	float num = 0;
	float div = 1;
	int sign = 1;

	if (value[i] == '-' || value[i] == '+')
	{
		if (value[i] == '-')
			sign = -1;
		i++;
	}
	while (value[i] != '\0')
	{
		if (value[i] == '.')
		{
			i++;
			while (value[i] != 0)
			{
				if (!std::isdigit(value[i]))
					throw std::invalid_argument("stof");
				div *= 10;
				num = num * 10 + value[i] - '0';
				i++;
			}
			break;
		}

		if (!std::isdigit(value[i]))
			throw std::invalid_argument("stof");
		num = num * 10 + value[i] - '0';
		i++;
	}
	return (num / div * sign);
}

void	BitcoinExchange::_fillInput(std::string const filename)
{
	std::ifstream file;

	file.open(filename.c_str());
	if (!file.is_open())
		throw FileDoesNotExistException();

	_readFile(file, "input");

	file.close();
}

void	BitcoinExchange::_fillData(void)
{
	std::ifstream file;

	file.open("data.csv");
	if (!file.is_open())
		throw DatabaseErrorException();

	_readFile(file, "database");

	file.close();
}

int BitcoinExchange::_daysInMonth(int year, int month)
{
    if (month < 1 || month > 12) {
        return 0;
    }

    static const int daysPerMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int days = daysPerMonth[month - 1];

    if (month == 2 && _isLeapYear(year)) {
        days = 29;
    }

    return days;
}

bool BitcoinExchange::_isLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool BitcoinExchange::_isValidDate(std::string date)
{
    if (date.size() != 10 || date[4] != '-' || date[7] != '-') {
        return false;
    }

    int year = atoi(date.substr(0, 4).c_str());
    int month = atoi(date.substr(5, 2).c_str());
    int day = atoi(date.substr(8, 2).c_str());

    if (year < 1000 || year > 9999) {
        return false;
    }

    if (month < 1 || month > 12) {
        return false;
    }

    if (day < 1 || day > _daysInMonth(year, month)) {
        return false;
    }

    time_t currentTime = time(NULL);
    struct tm *localTime = localtime(&currentTime);
    int currentYear = localTime->tm_year + 1900;
    int currentMonth = localTime->tm_mon + 1;
    int currentDay = localTime->tm_mday;
    if (year > currentYear || (year == currentYear && month > currentMonth) || (year == currentYear && month == currentMonth && day > currentDay)) {
        return false;
    }

    return true;
}

bool BitcoinExchange::_isValidValue(float value, std::string type)
{
	if (type == "input" && (value < 0 || value > 1000))
		return false;
	else if (type == "database" && value <= 0)
		return false;
	return true;
}

float BitcoinExchange::_valueDate(std::string date)
{
	float value = -1;
	std::map<int, std::pair<std::string, float> >::iterator it;

	for (it = _database.begin(); it != _database.end(); it++)
	{
		if (it->second.first == date)
			return (it->second.second);
		else if (it->second.first > date)
			return (value);

		value = it->second.second;
	}
	return value;
}

void BitcoinExchange::_readFile(std::ifstream &file, std::string type)
{
	int i = 0;
	std::string line;
	std::string date;
	std::string value;

	std::getline(file, line);
	if (type == "database" && line != "date,exchange_rate")
		throw DatabaseErrorException();
	else if (type == "input" && line != "date | value")
		throw InputFileErrorException();

	while (std::getline(file, line))
	{
		std::stringstream ss(line);
		if (type == "database")
			std::getline(ss, date, ',');
		else
			std::getline(ss, date, '|');
		std::getline(ss, value);

		if (date.length() != 10 && type == "database")
			throw DatabaseErrorException();
		else if (date.length() != 11 && type == "input")
			throw InputFileErrorException();
		if (isspace(date[0]) && type == "database")
			throw DatabaseErrorException();
		else if (isspace(date[0]) && type == "input")
			throw InputFileErrorException();
		if (date.find_first_not_of("0123456789-") != std::string::npos && type == "database")
			throw DatabaseErrorException();
		else if (date.find_first_not_of("0123456789- ") != std::string::npos && type == "input")
			throw InputFileErrorException();

		date.erase(date.find_last_not_of(" \t\n\r") + 1);
		if (date.length() != 10)
			date = "0000-00-00";
		value.erase(0, value.find_first_not_of("\t\n\r "));
		value.erase(value.find_last_not_of("\t\n\r ") + 1);

		if (isspace(date[date.length() - 1]) && type == "database")
			throw DatabaseErrorException();
		else if (isspace(date[date.length() - 1]) && type == "input")
			throw InputFileErrorException();
		else if (value == "" || value == "-")
			throw InputFileErrorException();

		if (type == "database")
			_database.insert(std::make_pair(i, std::make_pair(date, _stof(value))));
		else
			_inputfile.insert(std::make_pair(i, std::make_pair(date, _stof(value))));
		i++;
	}
}

void BitcoinExchange::_exchange()
{
	std::string date;
	float value;
	std::map< int, std::pair< std::string, float > >::iterator it;

	for (it = _inputfile.begin(); it != _inputfile.end(); it++)
	{
		date = it->second.first;
		value = it->second.second;

		if (!_isValidDate(date))
			std::cout << "Error: invalid date." << std::endl;
		else if (!_isValidValue(value, "input"))
			std::cout << "Error: invalid value." << std::endl;
		else
			std::cout << date << " | " << value << " => " << value * _valueDate(date) << std::endl;
	}
}

const char *BitcoinExchange::FileDoesNotExistException::what() const throw()
{
	return "File does not exist.";
}

const char *BitcoinExchange::InputFileErrorException::what() const throw()
{
	return "Error reading input file.";
}

const char *BitcoinExchange::DatabaseErrorException::what() const throw()
{
	return "Error reading database file.";
}