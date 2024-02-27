/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:24:13 by lnicoter          #+#    #+#             */
/*   Updated: 2024/02/27 16:26:49 by lnicoter         ###   ########.fr       */
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

Bureaucrat::Bureaucrat(const std::string name, int grade):name(name), grade(grade)
{

	if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 1)
		throw GradeTooHighException();
	std::cout<<"Burocrat assigned"<<std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout<<"Burocrat Espelled"<<std::endl;
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
	std::cout<<"A copy of the burocrat has been done"<<std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& obj)
{
	this->grade = obj.getGrade();
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj)
{
	os <<obj.getName()<<" Burocrat grade "<<obj.getGrade()<<std::endl;
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
	if (obj.getSign() == true)
		std::cout<<*this<<" signed "<<obj<<std::endl;
	else
		std::cout<<*this<<" couldn't sign "<<obj<<" because is not ready"<<std::endl;
}

void	Bureaucrat::executeForm(const AForm& form)
{
	std::cout<<"Let me see if i can execute this form"<<std::endl;
	if (this->getGrade() <= form.getGradetoExecute())
	{
		std::cout<<*this<<" executed "<<form<<std::endl;
	}
	else
		std::cout<<*this<<" couldn't execute "<<form<<std::endl;
}
