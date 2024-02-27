/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:08:06 by lnicoter          #+#    #+#             */
/*   Updated: 2024/02/27 20:46:27 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidetialPardonForm.hpp"


PresidentialPardonForm::PresidentialPardonForm(std::string target) : target(target), sign(25), exec(5)
{
	std::cout<<"The presidential form has been created"<<std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout<<"The presidential form has been scrapped"<<std::endl;
}

std::string PresidentialPardonForm::getTarget(void) const
{
	return this->target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& obj) : AForm(obj), target(obj.getTarget()), sign(obj.getGradeToSign()), exec(obj.getGradetoExecute())
{
	std::cout<<"The presidential form copy constructor has been called"<<std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& obj)
{
	std::cout<<"The presidential form overloading operator has been called"<<std::endl;
	this->target = obj.getTarget();
	return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	std::cout<<"You want to have the permission for the president huh?"<<std::endl;
	std::cout<<"Let me check if the form is signed before the permission"<<std::endl;
	if (this->getSign() == true)
	{
		std::cout<<"ok let's see if you can have the permission of the president"<<std::endl;
		if (executor.getGrade() <= 5)
			std::cout<<"mr "<<this->getTarget()<<" has been pardoned by Zaphod Beeblebrox"<<std::endl;
	}
	else
		throw GradeTooLowException();
}

