/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 19:02:14 by lnicoter          #+#    #+#             */
/*   Updated: 2024/02/27 20:38:19 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm(), target(target), sign(72), exec(45)
{
	std::cout<<"The shruberry has been created"<<std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout<<"The shruberry got destroyed"<<std::endl;
}

std::string RobotomyRequestForm::getTarget(void) const
{
	return this->target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& obj) : AForm(obj), target(obj.getTarget()), sign(obj.getGradeToSign()), exec(obj.getGradetoExecute())
{
	std::cout<<"The copy constructor of shruberry has been called"<<std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& obj)
{
	this->target = obj.target;
	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	srand(static_cast<unsigned int>(time(NULL)));

	std::cout<<"You want to get modified huh? let's what can you do"<<std::endl;
	if (this->getSign() == true)
	{
		if (executor.getGrade() <= 45)
		{
			if (rand() % 2)
				std::cout<<"The robotomy was failure you're now a cow 🐄"<<std::endl;
			else
				std::cout<<"The robotomy was a success you're ready to go"<<std::endl;
		}
		else
			throw GradeTooLowException();
	}
}
