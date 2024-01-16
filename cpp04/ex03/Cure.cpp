/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 19:04:26 by lnicoter          #+#    #+#             */
/*   Updated: 2024/01/12 17:41:43 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure()
{
	std::cout<<"Cure constructor called"<<std::endl;
	this->type = "Cure";
}

Cure::~Cure()
{
	std::cout<<"Cure constructor called"<<std::endl;
}

Cure::Cure(Cure& obj)
{
	this->type = obj.type;
}

Cure& Cure::operator=(const Cure& obj)
{
	this->type = obj.type;
	return *this;
}


AMateria* Cure::clone() const
{
	AMateria* cureCopy = new Cure();
	return cureCopy;
}

void Cure::use(ICharacter& target)
{
	std::cout<<"*heals "<<target.getName()<<"'s wounds *"<<std::endl;
}
