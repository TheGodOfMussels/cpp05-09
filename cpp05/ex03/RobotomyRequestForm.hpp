/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimolin2 <dimolin2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:18:43 by dimolin2          #+#    #+#             */
/*   Updated: 2024/02/07 16:18:43 by dimolin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <cstdlib>
#include "Form.hpp"

class Bureaucrat;

class RobotomyRequestForm: public Form
{
	private:
		std::string	_target;
	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(std::string const &target);
		RobotomyRequestForm(RobotomyRequestForm const &copy);
		~RobotomyRequestForm(void);

		RobotomyRequestForm const	&operator=(RobotomyRequestForm const &copy);

		void	beExecuted(Bureaucrat const &bureaucrat) const;
		static Form	*makeForm(Form *form, std::string const &type, std::string const &target);

		std::string const	&getTarget(void) const;
};

std::ostream	&operator<<(std::ostream &str, RobotomyRequestForm const &form);

#endif