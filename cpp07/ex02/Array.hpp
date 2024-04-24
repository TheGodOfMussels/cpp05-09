/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimolin2 <dimolin2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:49:26 by dimolin2          #+#    #+#             */
/*   Updated: 2024/02/20 15:49:27 by dimolin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
	private:
		T	*_array;
		unsigned int _length;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array &copy);
		Array &operator=(const Array &copy);
		T &operator[](int index);
		~Array();

		unsigned int length() const;

		class OutOfRangeException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

template <typename T>
std::ostream& operator<<(std::ostream&os, Array<T>& f);

#include "Array.tpp"

#endif