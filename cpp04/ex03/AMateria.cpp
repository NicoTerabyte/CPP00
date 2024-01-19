/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:23:24 by lnicoter          #+#    #+#             */
/*   Updated: 2024/01/19 16:32:55 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
	this->type = "";
}

AMateria::AMateria(std::string const & type) //what? è per ottimizzare il passaggio della stringa
{
	this->type = type;
}

AMateria::~AMateria()
{
}

AMateria::AMateria(const AMateria& obj)
{
	this->type = obj.type;
}

AMateria& AMateria::operator=(const AMateria& obj)
{
	this->type = obj.type;
	return *this;
}

std::string const & AMateria::getType () const
{
	return this->type;
}

void AMateria::use(ICharacter& target)
{
	std::cout<<"Sorry there was nothing her other than"<<target.getName()<<std::endl;
}

// void AMateria::clone() const
// {
// 	return (AMateria*)this;
// }
