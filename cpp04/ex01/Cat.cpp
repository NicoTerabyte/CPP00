/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:36:36 by lnicoter          #+#    #+#             */
/*   Updated: 2024/01/10 19:32:54 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout<<"Cat constuctor called"<<std::endl;
	this->catMind = new Brain();
	this->type = "Cat";
}

Cat::~Cat()
{
	std::cout<<"Cat destructor called"<<std::endl;
	delete this->catMind;
}

Cat::Cat(Cat &obj) : Animal(obj)
{
	this->type = obj.type;
	this->catMind = new Brain(*obj.catMind);
}

Cat& Cat::operator=(const Cat& obj)
{
	this->type = obj.type;
	this->catMind = new Brain(*obj.catMind);
	return *this;
}

void Cat::makeSound(void) const
{
	std::cout<<"Bro (cat's don't bark) 🤨🤨🤨🤨🤨🤨"<<std::endl;
}
