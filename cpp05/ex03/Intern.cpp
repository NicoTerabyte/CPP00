/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:55:36 by lnicoter          #+#    #+#             */
/*   Updated: 2024/04/26 21:57:21 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShruberryCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidetialPardonForm.hpp"

Intern::Intern()
{
	std::cout<<"This constructor is as useful as concrete parachute. " <<std::endl;
}

Intern::~Intern()
{
	std::cout<<"Destructor called"<<std::endl;
}

Intern::Intern(const Intern& obj)
{
	std::cout<<"This copy constructor is as useful as Pedals on a wheelchair "<<std::endl;
	(void)obj;
}

Intern& Intern::operator=(const Intern& obj)
{
	std::cout<<"This operator overloading is as useful as a case sensitive search engine"<<std::endl;
	(void)obj;
	return *this;
}

AForm*	Intern::makeForm(std::string formType, std::string formName)
{
	AForm	*test = 0;

	if (formType != "shruberry creation" && formType != "robotomy request" && formType != "presidential pardon form" )
	{
		throw std::runtime_error("This kind of form doesn't exist\n");
	}
	switch (formType[0])
	{
		case 's':
		{
			test = new ShruberryCreationForm(formName);
			break ;
		}
		case 'r':
		{
			test = new RobotomyRequestForm(formName);
			break ;
		}
		case 'p':
		{
			test = new PresidentialPardonForm(formName);
		}
	}
	return test;
}
