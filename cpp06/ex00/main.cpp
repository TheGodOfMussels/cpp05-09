/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimolin2 <dimolin2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:04:32 by dimolin2          #+#    #+#             */
/*   Updated: 2024/02/13 16:04:34 by dimolin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "error: invalid argumets" << std::endl;
		return 1;
	}
	std::string n;
	n = av[1];
	ScalarConverter::convert(n);
	return 0;
}