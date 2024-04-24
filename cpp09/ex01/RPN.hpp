/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimolin2 <dimolin2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 15:44:22 by dimolin2          #+#    #+#             */
/*   Updated: 2024/03/08 15:44:23 by dimolin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stack>
#include <sstream>
#include <cstdlib>

class RPN 
{
private:
	std::stack<int> operands;

	RPN();
	RPN(const RPN &rpn);
	RPN &operator=(const RPN &rpn);

	static bool isOperator(char c);
	static int performOperation(int operand1, int operand2, char operation);
	void	parseExpression(const std::string& expression);
public:
	RPN(const std::string& expression);
	~RPN();
	void evaluateExpression();
};
