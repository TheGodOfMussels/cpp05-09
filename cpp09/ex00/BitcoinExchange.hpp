/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimolin2 <dimolin2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 15:43:24 by dimolin2          #+#    #+#             */
/*   Updated: 2024/03/08 15:43:25 by dimolin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>

class BitcoinExchange
{
private:
	std::string	_filename;
	std::map<int, std::pair<std::string, float> > _database;
	std::map<int, std::pair<std::string, float> > _inputfile;

	BitcoinExchange();
	BitcoinExchange(BitcoinExchange const &copy);
	BitcoinExchange &operator=(BitcoinExchange const &copy);

	int	_stoi(std::string str);
	float	_stof(std::string value);
	bool	_isLeapYear(int year);
	int	_daysInMonth(int year, int month);

	void	_fillInput(std::string const filename);
	void	_fillData(void);
	void	_readFile(std::ifstream &file, std::string type);
	void	_exchange();

	float	_valueDate(std::string date);
	bool	_isValidValue(float value, std::string type);
	bool	_isValidDate(std::string date);

public:
	BitcoinExchange(std::string const filename);
	~BitcoinExchange();

	class FileDoesNotExistException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
	class InputFileErrorException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
	class DatabaseErrorException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
};
