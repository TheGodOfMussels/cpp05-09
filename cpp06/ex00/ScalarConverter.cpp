/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimolin2 <dimolin2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:04:38 by dimolin2          #+#    #+#             */
/*   Updated: 2024/02/13 16:04:39 by dimolin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"


ScalarConverter::ScalarConverter() 
{ 

}

ScalarConverter::ScalarConverter(ScalarConverter const &src)
{
	*this = src;
}

ScalarConverter& ScalarConverter::operator=(ScalarConverter const &src)
{
	if (this != &src)
		*this = src;
	return (*this);
}

ScalarConverter::~ScalarConverter() 
{ 

}

bool ScalarConverter::_isChar(const std::string num)
{
	if (num == "nan" || num == "nanf" || num == "-inf" || num == "inf"
		|| num == "+inf" || num == "-inff" || num == "inff" || num == "+inff")
		return true;
	return num.length() == 1 && std::isalpha(num[0]);
}

bool ScalarConverter::_isInt(const std::string num)
{
	if (num == "nan" || num == "nanf" || num == "-inf" || num == "inf"
		|| num == "+inf" || num == "-inff" || num == "inff" || num == "+inff")
		return true;
	try {
		_stoi(num);
	} catch(...) {
		return false;
	}
	return true;
}

bool ScalarConverter::_isFloat (const std::string num)
{
	if (num[num.length() - 1] != 'f')
		return false;
	if (num == "nan" || num == "nanf" || num == "-inf" || num == "inf"
		|| num == "+inf" || num == "-inff" || num == "inff" || num == "+inff")
		return true;
	try{
		_stof(num);
	} catch(...) {
		return false;
	}
	return true;
}

bool ScalarConverter::_isDouble(const std::string str)
{
	if (str == "nan" || str == "nanf" || str == "-inf" || str == "inf"
		|| str == "+inf" || str == "-inff" || str == "inff" || str == "+inff")
		return true;
	try {
		_stod(str);
	} catch(...) {
		return false;
	}
	return true;
}


int ScalarConverter::_stoi(std::string str)
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

std::string ScalarConverter::_itos(int num)
{
	std::string out;
	int i = 0;
	int sign = 1;

	if (num < 0)
	{
		sign = -1;
		num *= -1;
	}
	while (num > 0)
	{
		out[i] = num % 10 + '0';
		num /= 10;
		i++;
	}
	if (sign == -1)
		out[i] = '-';
	return (out);
}

float ScalarConverter::_stof(std::string str)
{
	int i = 0;
	int sign = 1;
	float num = 0;
	float div = 1;

	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] != '\0')
	{
		if (str[i] == '.')
		{
			i++;
			if (!std::isdigit(str[i]))
				throw std::invalid_argument("stof");
			div *= 10;
			num = num * 10 + str[i] - '0';
			break;
		}
		if (!std::isdigit(str[i]))
			throw std::invalid_argument("stof");
		num = num * 10 + str[i] - '0';
		i++;
	}
	return (num * sign / div);
}

double ScalarConverter::_stod(std::string str)
{
	int i = 0;
	int sign = 1;
	double num = 0;
	double div = 1;

	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] != '\0')
	{
		if (str[i] == '.')
		{
			i++;
			if (!std::isdigit(str[i]))
				throw std::invalid_argument("stod");
			div *= 10;
			num = num * 10 + str[i] - '0';
			i++;
			break;
		}
		if (!std::isdigit(str[i]))
			throw std::invalid_argument("stod");
		num = num * 10 + str[i] - '0';
		i++;
	}
	return (num * sign / div);
}

void ScalarConverter::_printChar(std::string num, char c)
{
	std::string out;

	if (num == "nan" || num == "nanf" || num == "-inf" || num == "inf"
		|| num == "+inf" || num == "-inff" || num == "inff" || num == "+inff")
		std::cout << "impossible";
	else if (std::isprint(c))
		std::cout << "'" << c << "'";
	else
		std::cout << "Non displayable";
}

void ScalarConverter::_printInt(std::string num, int i)
{

	if (num == "nan" || num == "nanf" || num == "-inf" || num == "inf"
		|| num == "+inf" || num == "-inff" || num == "inff" || num == "+inff")
		std::cout << "impossible";
	else
		std::cout << i;
}

void ScalarConverter::_printFloat(std::string num, float f)
{
	std::cout << std::fixed << std::setprecision(1);

	if (num == "nan" || num == "-inf" || num == "+inf" )
		std::cout << num << "f";
	else if (num == "nanf" || num == "-inff" || num == "+inff")
		std::cout << num;
	else if (num == "inf")
		std::cout << "+inf";
	else if (num == "inff")
		std::cout << "+inff";
	else
		std::cout << f << "f";
}

void ScalarConverter::_printDouble(std::string num, double d)
{
	std::cout << std::fixed << std::setprecision(1);

	if (num == "nan" || num == "-inf" || num == "+inf")
		std::cout << num;
	else if (num == "nanf" || num == "-inff" || num == "+inff")
		std::cout << num.substr(0, num.length() - 1);
	else if (num == "inf")
		std::cout << "+inf";
	else if (num == "inff")
		std::cout << "+inff";
	else
		std::cout << d;
}

void ScalarConverter::_print(std::string num, char c, int i, float f, double d)
{
	std::cout	<< "char: ";
	_printChar(num, c);
	std::cout	<< std::endl << "int: ";
	_printInt(num, i);
	std::cout	<< std::endl << "float: ";
	_printFloat(num, f);
	std::cout	<< std::endl << "double: ";
	_printDouble(num, d);
	std::cout	<< std::endl;
}

void ScalarConverter::convert(std::string num)
{
	char c;
	int i;
	float f;
	double d;

	if (_isChar(num))
	{
		c = num[0];
		i = static_cast<int>(c);
		f = static_cast<float>(c);
		d = static_cast<double>(c);
	}
	else if (_isInt(num))
	{
		i = _stoi(num);
		c = static_cast<char>(i);
		f = static_cast<float>(i);
		d = static_cast<double>(i);
	}
	else if (_isFloat(num))
	{
		f = _stof(num);
		c = static_cast<char>(f);
		i = static_cast<int>(f);
		d = static_cast<double>(f);
	}
	else if (_isDouble(num))
	{
		d = _stod(num);
		c = static_cast<char>(d);
		i = static_cast<int>(d);
		f = static_cast<float>(d);
	}
	else
	{
		std::cout << "error: invalid argument" << std::endl;
		return ;
	}
	_print(num, c, i, f, d);
}