/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimolin2 <dimolin2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 15:43:29 by dimolin2          #+#    #+#             */
/*   Updated: 2024/03/08 15:43:30 by dimolin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	int ret = 0;

	if (ac != 2)
	{
		std::cout << "Usage: ./bitcoin [filename]" << std::endl;
		return 1;
	}

	try
	{
		BitcoinExchange exchange(av[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		ret = 1;
	}

	return ret;
}