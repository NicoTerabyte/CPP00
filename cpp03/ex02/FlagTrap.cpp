/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FlagTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 19:22:35 by lnicoter          #+#    #+#             */
/*   Updated: 2024/01/09 19:34:17 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FlagTrap.hpp"

FlagTrap::FlagTrap() : ClapTrap()
{
	std::cout<<"FlagTrap default constructor called\n";
	this->name = "FlagTrap";
	this->AttackDamage = 30;
	this->energyPoints = 100;
	this->hitPoints = 100;
}

FlagTrap::FlagTrap(std::string name) : ClapTrap(name)
{
	std::cout<<"FlagTrap constructor called\n";
	this->name = name;
	this->AttackDamage = 30;
	this->energyPoints = 100;
	this->hitPoints = 100;
}

FlagTrap::~FlagTrap()
{
	std::cout<<"FlagTrap Destructor called\n";
}

FlagTrap::FlagTrap(FlagTrap& obj) : ClapTrap(obj)
{
	std::cout<<"FlagTrap Copy constructor called\n";
	this->name = obj.name;
	this->AttackDamage = obj.AttackDamage;
	this->energyPoints = obj.energyPoints;
	this->hitPoints = obj.hitPoints;
}

FlagTrap& FlagTrap::operator=(const FlagTrap& obj)
{
	std::cout<<"FlagTrap copy operator called\n";
	this->name = obj.name;
	this->AttackDamage = obj.AttackDamage;
	this->energyPoints = obj.energyPoints;
	return *this;
}

void FlagTrap::highFiveGuys(void)
{
	int	answer;
	std::cout<<this->name<<" wants to give you an high five do you accept it?"<<std::endl;
	std::cout<<"Yes(1) No(0)"<<std::endl;
	std::cin>>answer;
	if (answer == 1)
		std::cout<<"You gave "<<this->name<<" an high five it is happy"<<std::endl;
	else
		std::cout<<"You didn't gave "<<this->name<<" an high five poor little creature"<<std::endl;
}
