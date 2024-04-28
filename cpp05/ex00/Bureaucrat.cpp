/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:24:13 by lnicoter          #+#    #+#             */
/*   Updated: 2024/04/28 17:47:41 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"


const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Error, the grade is too high.";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Error, the grade is too low.";
}

Bureaucrat::Bureaucrat(const std::string& name, int grade): name(name), grade(grade)
{

	if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 1)
		throw GradeTooHighException();
	std::cout<<"bureaucrat assigned"<<std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout<<"bureaucrat Espelled"<<std::endl;
}

int Bureaucrat::getGrade(void) const
{
	return this->grade;
}

const std::string Bureaucrat::getName(void) const
{
	return this->name;
}

Bureaucrat::Bureaucrat(const Bureaucrat& obj):name(obj.getName()), grade(obj.getGrade())
{
	std::cout<<"A copy of the bureaucrat has been done"<<std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& obj)
{
	if (this != &obj)
		this->grade = obj.getGrade();
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj)
{
	os <<obj.getName()<<" bureaucrat grade "<<obj.getGrade()<<std::endl;
	return os;
}

void Bureaucrat::setGrade(int grade)
{
	this->grade = grade;
}

void Bureaucrat::incrementGrade()
{
	std::cout<<"your grade got incremented yay"<<std::endl;
	this->grade -= 1;
	if (this->grade < 1)
		throw GradeTooHighException();
}

void Bureaucrat::decrementGrade()
{

	std::cout<<"your grade got decremented noooo"<<std::endl;
	this->grade += 1;
	if (this->grade > 150)
		throw GradeTooLowException();
}

void	Bureaucrat::signForm(AForm& obj)
{
	try
	{
		obj.beSigned(*this);
		std::cout<<*this<<"signed "<<obj.getName()<<std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout<<*this<<" couldn't sign "<<obj<<" because "<<e.what()<<std::endl;
	}
}

void	Bureaucrat::executeForm(const AForm& form)
{
	std::cout<<"Let me see if i can execute this form"<<std::endl;
	try
	{
		form.execute(*this);
		std::cout<<*this<<"executed "<<form<<std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout <<*this<< " couldn't execute "<<form<<std::endl;
		std::cout<<"because "<<e.what()<<std::endl;
	}

}
