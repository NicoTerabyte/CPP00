/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:34:50 by lnicoter          #+#    #+#             */
/*   Updated: 2024/01/23 17:04:43 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"


Dog::Dog() : Animal()
{
	std::cout<<"Dog constuctor called"<<std::endl;
	this->type = "Dog";
	this->dogMind = new Brain();
}

Dog::~Dog()
{
	std::cout<<"Dog destructor called"<<std::endl;
	delete this->dogMind;
}

Dog::Dog(const Dog &obj) : Animal(obj)
{
	this->type = obj.type;
	this->dogMind = new Brain(*obj.dogMind);
}

Dog& Dog::operator=(const Dog& obj)
{
	this->type = obj.type;
	this->dogMind = new Brain(*obj.dogMind);

	return *this;
}

void Dog::makeSound(void) const
{
	std::cout<<"Bau bau i'm dog!! 🐕🐕🐕"<<std::endl;
}

void Dog::setMind()
{
	std::string test = "prova";
	this->dogMind->setIdea(test, 1);
}

void Dog::printBrain()
{
	this->dogMind->printBrain();
	std::cout<<"finished\n\n\n";
}
