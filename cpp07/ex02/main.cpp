/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimolin2 <dimolin2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:49:34 by dimolin2          #+#    #+#             */
/*   Updated: 2024/02/20 15:49:34 by dimolin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main(void)
{
	Array<int> intArray((unsigned int)5);

	try
	{
		for (unsigned int i = 0; i < intArray.length(); i++)
			intArray[i] = (int)i;
		std::cout << "intArray : " << intArray << std::endl;

		std::cout << "intArray[42] = " << intArray[42] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	Array<int> intArray2;
	intArray2 = intArray;
	std::cout << "intArray2: " << intArray2 << std::endl;

	Array<int> intArray3(intArray);
	std::cout << "intArray3: " << intArray3 << std::endl;

	Array<std::string> stringArray((unsigned int)5);
	try
	{
		for (unsigned int i = 0; i < stringArray.length(); i++)
			stringArray[i] = "Hello";
		std::cout << "stringArray : " << stringArray << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	Array<std::string> stringArray2;
	stringArray2 = stringArray;
	std::cout << "stringArray2: " << stringArray2 << std::endl;

	Array<std::string> stringArray3(stringArray);
	std::cout << "stringArray3: " << stringArray3 << std::endl;

	return (0);
}