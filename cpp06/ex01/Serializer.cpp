/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimolin2 <dimolin2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:04:56 by dimolin2          #+#    #+#             */
/*   Updated: 2024/02/13 16:04:57 by dimolin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() 
{

}

Serializer::Serializer(Serializer const &src)
{
	*this = src;
}

Serializer& Serializer::operator=(Serializer const &src)
{
	if (this != &src)
		*this = src;
	return (*this);
}

Serializer::~Serializer() 
{

}

uintptr_t Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}