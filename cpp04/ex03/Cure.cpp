/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 19:04:26 by lnicoter          #+#    #+#             */
/*   Updated: 2024/01/19 16:18:18 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria()
{
	this->type = "cure";
}

Cure::~Cure()
{
}

Cure::Cure(const Cure& obj) : AMateria(obj)
{
	*this = obj;
}

Cure& Cure::operator=(const Cure& obj)
{
	this->type = obj.type;
	return *this;
}


AMateria* Cure::clone() const
{
	AMateria* cureCopy = new Cure(*this);
	return cureCopy;
}

void Cure::use(ICharacter& target)
{
	std::cout<<"* heals "<<target.getName()<<"'s wounds *"<<std::endl;
}
