/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:28:57 by lnicoter          #+#    #+#             */
/*   Updated: 2024/01/22 19:56:45 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	std::cout<<"Animal constuctor called"<<std::endl;
	this->type = "not specified";
}

Animal::~Animal()
{
	std::cout<<"Animal destructor called"<<std::endl;
}

Animal::Animal(const Animal &obj)
{
	this->type = obj.type;
}

Animal& Animal::operator=(const Animal& obj)
{
	this->type = obj.type;
	return *this;
}

void Animal::makeSound(void) const
{
	std::cout<<"Unrecognized sound"<<std::endl;
}

std::string Animal::getType(void) const
{
	return this->type;
}
