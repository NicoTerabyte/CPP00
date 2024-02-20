/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 10:44:14 by lnicoter          #+#    #+#             */
/*   Updated: 2024/02/20 15:27:37 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP


#include "median.hpp"
class Form;

class Bureaucrat
{
	public:
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

	private:
		const std::string	name;
		int					grade;

	public:
		// Bureaucrat(const std::string name, int grade);
		Bureaucrat(const std::string name = "jim", int grade = 25);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat& obj);
		Bureaucrat& operator=(const Bureaucrat& obj);

		const std::string	getName(void) const;
		int					getGrade(void) const;
		void				setGrade(int grade);
		void				incrementGrade();
		void				decrementGrade();
		void				signForm(Form& obj);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);

#endif
