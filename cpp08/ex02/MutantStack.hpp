/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimolin2 <dimolin2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:44:53 by dimolin2          #+#    #+#             */
/*   Updated: 2024/02/28 15:44:53 by dimolin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	private:
	public:
		MutantStack();
		MutantStack(MutantStack const &copy);
		MutantStack &operator=(MutantStack const &copy);
		~MutantStack();

		typedef typename std::stack<T>::container_type container_type;
		typedef typename container_type::iterator iterator;

		inline iterator begin();
		inline iterator end();
};

#include "MutantStack.tpp"