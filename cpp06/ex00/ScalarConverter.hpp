/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimolin2 <dimolin2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:04:42 by dimolin2          #+#    #+#             */
/*   Updated: 2024/02/13 16:04:42 by dimolin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <iomanip>

class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(ScalarConverter const &cpy);

	ScalarConverter	&operator=(ScalarConverter const &cpy);

	static bool	_isChar(const std::string num);
	static bool	_isInt(const std::string num);
	static bool	_isFloat(const std::string num);
	static bool	_isDouble(const std::string num);

	static int _stoi(std::string str);
	static std::string _itos(int num);
	static float _stof(std::string str);
	static double _stod(std::string str);

	static void _printChar(std::string num, char c);
	static void _printInt(std::string num, int i);
	static void _printFloat(std::string num, float f);
	static void _printDouble(std::string num, double d);
	static void _print(std::string num, char c, int i, float f, double d);
public:
	virtual	~ScalarConverter();

	static void	convert(std::string num);
};

#endif