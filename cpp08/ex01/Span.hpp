/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimolin2 <dimolin2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:44:42 by dimolin2          #+#    #+#             */
/*   Updated: 2024/02/28 15:44:43 by dimolin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cstdlib>
#include <list>
#include <climits>

class Span
{
	private:
		unsigned int _length;
		unsigned int _added;
		std::list<int> _numbers;
	public:
		Span();
		Span(unsigned int len);
		Span(Span const &copy);
		Span &operator=(Span const &copy);
		~Span();

		void addNumber(int n);
		
		std::list<int> getNumbersList(void) const;
		unsigned int length(void) const;
		void sort(void);
		unsigned int shortestSpan(void) const;
		unsigned int longestSpan(void) const;

		class FullSpanException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class NoSpanException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, Span const &span);