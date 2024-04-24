/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimolin2 <dimolin2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 15:47:07 by dimolin2          #+#    #+#             */
/*   Updated: 2024/03/08 15:49:18 by dimolin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(): _deq(0), _vec(0)
{}

PmergeMe::PmergeMe(const PmergeMe &copy): _deq(copy._deq), _vec(copy._vec)
{}

PmergeMe::PmergeMe(char **av)
{
	int	i = 1;

	while(av[i])
	{
		if (std::atoi(av[i]) < 0)
			throw negativeNumException();
		if (isInvalidChar(av[i]))
			throw invalidCharException();
		if (isDupNum(std::atoi(av[i])))
			throw presentNumException();
		_deq.push_back(std::atoi(av[i]));
		_vec.push_back(std::atoi(av[i]));
		i++;
	}
}

PmergeMe &PmergeMe::operator=(const PmergeMe &copy)
{
	if (this != &copy)
	{
		_vec = copy._vec;
		_deq = copy._deq;
	}
	return *this;
}

PmergeMe::~PmergeMe()
{}

bool	PmergeMe::isDupNum(int n)
{
	std::vector<int>::iterator it = _vec.begin();

	for (; it != _vec.end(); it++)
	{
		if (n == *it)
			return true;
	}
	return false;
}

bool	PmergeMe::isInvalidChar(char *str)
{
	std::string	allowed = "0123456789 ";
	int	k = 0;

	for (int i = 0; str[i]; i++)
	{
		k = 0;
		while (allowed[k])
		{
			if (str[i] == allowed[k])
				break;
			k++;
		}
		if (!allowed[k])
			return true;
	}
	return false;
}

void PmergeMe::sortAll()
{
	printUnsorted();
	sortVector();
	sortDeque();
}

void	PmergeMe::printUnsorted()
{
	std::vector<int>::iterator it = _vec.begin();

	std::cout << "Usorted:";
	for(; it != _vec.end(); it++)
		std::cout << " " << *it;
	std::cout << std::endl;
	std::cout << std::endl;
}

void PmergeMe::printVector()
{
	std::vector<int>::iterator it = _vec.begin();

	for (; it != _vec.end(); it++)
		std::cout << " " << *it;
	std::cout << std::endl;
}

void PmergeMe::sortVector()
{
	std::clock_t start;
	double time;

	start = std::clock();
	vecMergeInsertSort(_vec, 0, _vec.size() - 1);
	time = elapsed(start, std::clock());

	std::cout << "Sorted: ";
	printVector();
	std::cout	<< "Time to process a range of " << _vec.size()
				<< " elements with std::vector: " << time << " us" << std::endl;
}

void PmergeMe::vecMergeInsertSort(std::vector<int> &v, int begin, int end)
{
	int mid;

	if (begin < end)
	{
		mid = (begin + end) / 2;
		vecMergeInsertSort(v, begin, mid);
		vecMergeInsertSort(v, mid + 1, end);
		vecMerge(v, begin, mid, end);
	}
}

void PmergeMe::vecMerge(std::vector<int> &v, int begin, int middle, int end)
{
	int i = begin;
	int j = middle + 1;
	int k = 0;
	int tmp[end - begin + 1];

	while (i <= middle && j <= end)
	{
		if (v[i] < v[j])
			tmp[k++] = v[i++];
		else
			tmp[k++] = v[j++];
	}
	while (i <= middle)
		tmp[k++] = v[i++];
	while (j <= end)
		tmp[k++] = v[j++];
	for (i = begin; i <= end; i++)
		v[i] = tmp[i - begin];
}

void PmergeMe::sortDeque()
{
	std::clock_t start;
	double time;

	start = std::clock();
	deqMergeInsertSort(_deq, 0, _deq.size() - 1);
	time = elapsed(start, std::clock());

	std::cout	<< "Time to process a range of " << _deq.size()
				<< " elements with std::deque: " << time << " us" << std::endl;
}

void PmergeMe::deqMergeInsertSort(std::deque<int> &d, int begin, int end)
{
	int mid;

	if (begin < end)
	{
		mid = (begin + end) / 2;
		deqMergeInsertSort(d, begin, mid);
		deqMergeInsertSort(d, mid + 1, end);
		deqMerge(d, begin, mid, end);
	}
}

void PmergeMe::deqMerge(std::deque<int> &d, int begin, int middle, int end)
{
	int i = begin;
	int j = middle + 1;
	int k = 0;
	int tmp[end - begin + 1];

	while (i <= middle && j <= end)
	{
		if (d[i] < d[j])
			tmp[k++] = d[i++];
		else
			tmp[k++] = d[j++];
	}
	while (i <= middle)
		tmp[k++] = d[i++];
	while (j <= end)
		tmp[k++] = d[j++];
	for (i = begin; i <= end; i++)
		d[i] = tmp[i - begin];
}

double PmergeMe::elapsed(std::clock_t start, std::clock_t end)
{
	return static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
}

const char	*PmergeMe::negativeNumException::what() const throw()
{
	return "Negative numbers are not allowed!";
}

const char	*PmergeMe::presentNumException::what() const throw()
{
	return "Number duplication are not allowed!";
}

const char	*PmergeMe::invalidCharException::what() const throw()
{
	return "Only numeric characters are allowed!";
}