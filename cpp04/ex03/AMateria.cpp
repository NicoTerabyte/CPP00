/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:23:24 by lnicoter          #+#    #+#             */
/*   Updated: 2024/01/12 17:32:34 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
	std::cout<<"Default Constructor called"<<std::endl;
	this->type = nullptr;
}

AMateria::AMateria(std::string const & type) //what? è per ottimizzare il passaggio della stringa
{
	std::cout<<"Constructor called"<<std::endl;
	this->type = type;
}

AMateria::~AMateria()
{
	std::cout<<"Destructor called"<<std::endl;
}

AMateria::AMateria(AMateria& obj)
{
	std::cout<<"Copy constructor called"<<std::endl;
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

