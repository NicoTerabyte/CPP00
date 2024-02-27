/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 10:13:13 by lnicoter          #+#    #+#             */
/*   Updated: 2024/02/27 20:34:23 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

const char* AForm::GradeTooHighException::what() const throw()
{
	return "Error grade is too high\n";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Error grade is too Low\n";
}

AForm::AForm(const std::string name, const int gradeToSign, const int gradeToExecute) :
name(name), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	sign = false;
	(void)sign;
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToSign > 150)
		throw GradeTooLowException();
	std::cout<<"The Aform was printed"<<std::endl;
}

AForm::~AForm()
{
	std::cout<<"The Aform was scraped"<<std::endl;
}

int AForm::getGradetoExecute(void) const
{
	return this->gradeToExecute;
}

int AForm::getGradeToSign(void) const
{
	return this->gradeToSign;
}

const std::string AForm::getName(void) const
{
	return this->name;
}

bool AForm::getSign(void) const
{
	return this->sign;
}

AForm::AForm(const AForm& obj) : name(obj.getName()), sign(obj.getSign()), gradeToSign(obj.getGradeToSign()),
gradeToExecute(obj.getGradetoExecute())
{
	std::cout<<"The copy construttor of the Aform has been called"<<std::endl;
}

AForm& AForm::operator=(const AForm& obj)
{
	this->sign = obj.getSign();
	return *this;
}

std::ostream& operator<<(std::ostream& os, const AForm& obj)
{
	os<<obj.getName()<<" Is AForm name "<<obj.getGradeToSign()<<" grade required to sign it "
	<<obj.getGradetoExecute()<<" grade required to execute it "<<obj.getSign()<<" it is signed?"<<std::endl;
	return os;
}

void AForm::beSigned(Bureaucrat& theBur)
{
	if (theBur.getGrade() <= this->gradeToSign)
	{
		std::cout<<"the Aform got signed"<<std::endl;
		this->sign = true;
	}
	else
		throw GradeTooLowException();
}

