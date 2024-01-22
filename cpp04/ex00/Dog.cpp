/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:34:50 by lnicoter          #+#    #+#             */
/*   Updated: 2024/01/22 19:57:19 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"


Dog::Dog() : Animal()
{
	std::cout<<"Dog constuctor called"<<std::endl;
	this->type = "Dog";
}

Dog::~Dog()
{
	std::cout<<"Dog destructor called"<<std::endl;
}

Dog::Dog(const Dog &obj) : Animal(obj)
{
	this->type = obj.type;
}

Dog& Dog::operator=(const Dog& obj)
{
	this->type = obj.type;
	return *this;
}

void Dog::makeSound(void) const
{
	std::cout<<"Bau bau i'm dog!! 🐕🐕🐕"<<std::endl;
}
