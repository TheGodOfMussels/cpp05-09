/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimolin2 <dimolin2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:18:06 by dimolin2          #+#    #+#             */
/*   Updated: 2024/02/07 16:18:07 by dimolin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	BUREAUCRAT_HPP
# define	BUREAUCRAT_HPP

# include <iostream>

class	Form;

class Bureaucrat
{
private:
	std::string	_name;
	int	_grade;
public:
	Bureaucrat(void);
	~Bureaucrat(void);
	Bureaucrat(std::string const &name, int grade);
	Bureaucrat(Bureaucrat const &copy);

	Bureaucrat	&operator=(Bureaucrat const &copy);

	std::string const	&getName(void) const;
	int const	&getGrade(void) const;

	void	gradeUp(void);
	void	gradeDown(void);
	void	signForm(Form &form);
	void	executeForm(Form const &form);

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

std::ostream	&operator<<(std::ostream &str, Bureaucrat const &bureaucrat);

#endif