/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 20:16:18 by lnicoter          #+#    #+#             */
/*   Updated: 2024/01/23 17:13:31 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

		// WrongCat();
		// ~WrongCat();
		// WrongCat(const WrongCat& obj);
		// WrongCat& operator=(const WrongCat& obj);
		// void makeSound(void) const;
		// std::string getType(void) const;

WrongCat::WrongCat() : WrongAnimal()
{
	std::cout<<"WrongCat constructor called"<<std::endl;
	this->type = "WrongCat";
}

WrongCat::~WrongCat()
{
	std::cout<<"WrongCat default destructor called"<<std::endl;
}


WrongCat::WrongCat(const WrongCat& obj) : WrongAnimal(obj)
{
	std::cout<<"Copy constructor called"<<std::endl;
	this->type = obj.type;
}

WrongCat& WrongCat::operator=(const WrongCat& obj)
{
	std::cout<<"Copy assignement operator called"<<std::endl;
	this->type = obj.type;
	return *this;
}

void WrongCat::makeSound() const
{
	std::cout<<"WrongCat sound"<<std::endl;
}

std::string WrongCat::getType(void) const
{
	return this->type;
}
