/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimolin2 <dimolin2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:44:38 by dimolin2          #+#    #+#             */
/*   Updated: 2024/02/28 15:44:39 by dimolin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _length(0), _added(0) { }

Span::Span(unsigned int len) : _length(len), _added(len) { }

Span::Span(Span const &copy) : _length(copy._length), _added(copy._added) {
	_numbers = copy._numbers;
}

Span &Span::operator=(Span const &copy)
{
	if (this != &copy)
		*this = copy;
	return *this;
}

Span::~Span() { }

void Span::addNumber(int n)
{
	if (_added == 0)
		throw Span::FullSpanException();
	_added--;
	_numbers.push_back(n);
}

std::list<int> Span::getNumbersList(void) const {
	return _numbers;
}

unsigned int Span::length(void) const {
	return _length;
}

void Span::sort(void) {
	_numbers.sort();
}

unsigned int Span::shortestSpan(void) const
{
	if (_length < 2)
		throw Span::NoSpanException();

	std::list<int>::const_iterator it = _numbers.begin();

	unsigned int tmp = 0;
	unsigned int diff = UINT_MAX;

	while (it != _numbers.end())
	{
		tmp = *it;
		it++;
		if (it != _numbers.end() && (unsigned)*it - tmp < diff)
			diff = *it - tmp;
	}
	return diff;
}

unsigned int Span::longestSpan(void) const
{
	if (_length < 2)
		throw Span::NoSpanException();

	std::list<int>::const_iterator it = _numbers.begin();

	unsigned int smallest = UINT_MAX;
	unsigned int biggest = 0;

	while (it != _numbers.end())
	{
		if ((unsigned)*it < smallest)
			smallest = *it;
		if ((unsigned)*it > biggest)
			biggest = *it;
		it++;
	}
	return (biggest - smallest);
}

const char *Span::FullSpanException::what() const throw()
{
	return "Span is full";
}

const char *Span::NoSpanException::what() const throw()
{
	return "No span to find";
}

std::ostream &operator<<(std::ostream &out, Span const &span)
{
	std::list<int> l = span.getNumbersList();
	std::list<int>::iterator it = l.begin();
	while (it != l.end())
	{
		out << *it;
		if (++it != l.end())
			out << ", ";
	}
	return out;
}