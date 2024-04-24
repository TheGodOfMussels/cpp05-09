/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimolin2 <dimolin2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:04:47 by dimolin2          #+#    #+#             */
/*   Updated: 2024/02/13 16:04:47 by dimolin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"


Data::Data() : _num(0) 
{

}

Data::Data(int n) : _num(n) 
{

}

Data::Data(Data const &src) : _num(src._num)
{
	*this = src;
}

Data& Data::operator=(Data const &src)
{
	if (this != &src)
		*this = src;
	return (*this);
}

Data::~Data() 
{

}

int Data::getNum() const
{
	return (_num);
}