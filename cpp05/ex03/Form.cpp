/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimolin2 <dimolin2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:18:11 by dimolin2          #+#    #+#             */
/*   Updated: 2024/02/07 16:18:11 by dimolin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

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

void	Form::execute(Bureaucrat const &executor) const
{
	if (!this->_isSigned)
		throw (Form::FormNotSignedException());
	else if (executor.getGrade() > this->_signGrade)
		throw (Form::GradeTooLowException());
	else
	{
		std::cout << executor.getName() << " executes form: " << this->_name << std::endl;
		this->beExecuted(executor);
	}
}

Form	*Form::makeForm(const std::string &type, const std::string &target)
{
	Form	*form;

	form = NULL;
	form = ShrubberyCreationForm::makeForm(form, type, target);
	form = RobotomyRequestForm::makeForm(form, type, target);
	form = PresidentialPardonForm::makeForm(form, type, target);
	return (form);
}

char const	*Form::GradeTooHighException::what(void) const throw()
{
	return ("Grade is too high");
}

char const	*Form::GradeTooLowException::what(void) const throw()
{
	return ("Grade is too low");
}

char const	*Form::FormNotSignedException::what(void) const throw()
{
	return ("Form not signed");
}

char const	*Form::InvalidFormException::what(void) const throw()
{
	return ("Invalid Form Request");
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