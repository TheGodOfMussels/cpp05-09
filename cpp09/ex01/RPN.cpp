/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimolin2 <dimolin2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 15:44:19 by dimolin2          #+#    #+#             */
/*   Updated: 2024/03/08 15:44:20 by dimolin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() 
{}

RPN::RPN(const RPN &rpn) 
{
	this->operands = rpn.operands;
}

RPN	&RPN::operator=(const RPN &rpn) 
{
	if (this != &rpn) 
	{
		this->operands = rpn.operands;
	}
	return *this;
}

RPN::RPN(const std::string& expression) {
    parseExpression(expression);
}

RPN::~RPN() 
{}

void RPN::parseExpression(const std::string& expression) {
    std::istringstream iss(expression);
    std::string token;
    while (iss >> token) 
	{
        for (size_t i = 0; i < token.length(); ++i) 
		{
            if (isdigit(token[i])) 
			{
                operands.push(token[i] - '0');
            } 
			else if (isOperator(token[i])) 
			{
                if (operands.size() < 2) 
				{
                    std::cout << "Error: Insufficient operands for operation" << std::endl;
                    return;
                }
                int operand2 = operands.top();
                operands.pop();
                int operand1 = operands.top();
                operands.pop();
                int result = performOperation(operand1, operand2, token[i]);
                operands.push(result);
            } 
			else 
			{
                std::cout << "Error: Invalid token encountered: " << token[i] << std::endl;
                return;
            }
        }
    }
    evaluateExpression();
}

void RPN::evaluateExpression() 
{
    if (operands.size() != 1) 
    {
        std::cout << "Error: Insufficient operators for operation" << std::endl;
        return;
    }

    std::cout << "Result: " << operands.top() << std::endl;
}

bool RPN::isOperator(char c) 
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int RPN::performOperation(int operand1, int operand2, char operation) 
{
    switch (operation) 
    {
        case '+': return operand1 + operand2;
        case '-': return operand1 - operand2;
        case '*': return operand1 * operand2;
        case '/': 
        if (operand2 == 0) 
	    {
            std::cout << "Error: Division by zero" << std::endl;
            exit(1);
        }
        return operand1 / operand2;
    	default:
            std::cout << "Error: Invalid operator" << std::endl;
            exit(1);
    }
}