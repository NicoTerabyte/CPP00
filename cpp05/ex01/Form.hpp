/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 22:37:59 by lnicoter          #+#    #+#             */
/*   Updated: 2024/02/29 16:25:48 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "median.hpp"

class Bureaucrat;

class Form
{

	private:
		const std::string	name;
		bool				sign;
		const int			gradeToSign;
		const int			gradeToExecute;

	public:
		Form(const std::string name = "default", const int gradeToSign = 25, const int gradeToExecute = 10);
		// Form(const std::string name, const int gradeToSign, const int gradeToExecute);
		~Form();
		Form(Form& obj);
		Form& operator=(const Form &obj);

		const std::string	getName(void) const;
		bool				getSign(void) const;
		int					getGradeToSign(void) const;
		int					getGradetoExecute(void) const;
		void				beSigned(Bureaucrat& theBur);
		//exception
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
};

std::ostream& operator<<(std::ostream& os, const Form& obj);

#endif

