/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimolin2 <dimolin2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:17:04 by dimolin2          #+#    #+#             */
/*   Updated: 2024/02/07 16:17:05 by dimolin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(void): _name("undefined"), _isSigned(0), _signGrade(150), _execGrade(150)
{}

Form::Form(std::string const &name, int const &signGrade, int const &execGrade): _name(name), _isSigned(0), _signGrade(signGrade), _execGrade(execGrade)
{
	if (this->_signGrade < 1)
		throw (Form::GradeTooHighException());
	else if (this->_signGrade > 150)
		throw (Form::GradeTooLowException());
	if (this->_execGrade < 1)
		throw (Form::GradeTooHighException());
	else if (this->_execGrade > 150)
		throw (Form::GradeTooLowException());
}

Form::Form(Form const &copy): _name(copy._name), _isSigned(copy._isSigned), _signGrade(copy._signGrade), _execGrade(copy._execGrade)
{
	*this = copy;
}

Form::~Form(void)
{}

std::string const	&Form::getName(void) const
{
	return (this->_name);
}

int const	&Form::getSignGrade(void) const
{
	return (this->_signGrade);
}

int const	&Form::getExecGrade(void) const
{
	return (this->_execGrade);
}

bool const	&Form::getIsSigned(void) const
{
	return (this->_isSigned);
}

void	Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_signGrade)
		throw (Form::GradeTooLowException());
	else
	{
		this->_isSigned = 1;
		std::cout << bureaucrat.getName() << " succesfully signed " << this->getName() << std::endl;
	}
}

char const	*Form::GradeTooHighException::what(void) const throw()
{
	return ("Grade is too high");
}

char const	*Form::GradeTooLowException::what(void) const throw()
{
	return ("Grade is too low");
}


Form const	&Form::operator=(const Form &copy)
{
	this->_isSigned = copy._isSigned;
	return (*this);
}

std::ostream	&operator<<(std::ostream &str, Form const &form)
{
	return (str << form.getName() << " form, signed: " << form.getIsSigned() << ", sign grade: " << form.getSignGrade() << ", exec grade: " << form.getExecGrade());
}