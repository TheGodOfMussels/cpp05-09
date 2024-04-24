/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimolin2 <dimolin2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:05:36 by dimolin2          #+#    #+#             */
/*   Updated: 2024/02/13 16:05:37 by dimolin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prog.hpp"

int main(void)
{
	Base *base = generate();

	std::cout << "Pointer: ";
	identify(base);
	std::cout << "Reference: ";
	identify(*base);

	delete base;

	return (0);
}