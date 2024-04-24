/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimolin2 <dimolin2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:17:08 by dimolin2          #+#    #+#             */
/*   Updated: 2024/02/07 16:17:09 by dimolin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>

class Bureaucrat;

class Form
{
private:
	std::string const	_name;
	bool	_isSigned;
	int const	_signGrade;
	int const	_execGrade;
public:
	Form(void);
	Form(std::string const &name, int const &signGrade, int const &execGrade);
	Form(Form const &copy);
	~Form(void);

	Form const	&operator=(Form const &copy);

	std::string const	&getName(void) const;
	bool const	&getIsSigned(void) const;
	int const	&getSignGrade(void) const;
	int const	&getExecGrade(void) const;

	void	beSigned(Bureaucrat &bureaucrat);

	class GradeTooHighException: public std::exception
		{
			public:
				virtual char const	*what(void) const throw();
		};
	class GradeTooLowException: public std::exception
		{
			public:
				virtual char const	*what(void) const throw();
		};
};

std::ostream	&operator<<(std::ostream &str, Form const &form);

#endif