/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimolin2 <dimolin2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 15:47:10 by dimolin2          #+#    #+#             */
/*   Updated: 2024/03/08 15:47:11 by dimolin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma	once

#include <iostream>
#include <list>
#include <vector>
#include <deque>
#include <cstdlib>
#include <ctime>

class PmergeMe
{
	private:
		std::deque<int>	_deq;
		std::vector<int> _vec;

		PmergeMe();
		PmergeMe(const PmergeMe &copy);
		PmergeMe &operator=(const PmergeMe &copy);

		bool	isDupNum(int n);
		bool	isInvalidChar(char *str);
		void	printUnsorted();
		void	printVector();
		double	elapsed(std::clock_t start, std::clock_t end);

		void	sortVector();
		void	vecMerge(std::vector<int> &v, int begin, int middle, int end);
		void	vecMergeInsertSort(std::vector<int> &v, int begin, int end);

		void	sortDeque();
		void	deqMerge(std::deque<int> &d, int begin, int middle, int end);
		void	deqMergeInsertSort(std::deque<int> &d, int begin, int end);

	public:
		PmergeMe(char **av);
		~PmergeMe();

		void	sortAll();

		class	negativeNumException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class	presentNumException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class	invalidCharException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};
