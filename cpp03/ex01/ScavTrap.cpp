/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:43:16 by lnicoter          #+#    #+#             */
/*   Updated: 2024/01/09 19:23:52 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap()
{
	std::cout<<"Constructor called\n";
	this->AttackDamage = 20;
	this->hitPoints = 100;
	this->energyPoints = 50;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout<<"ScavTrap Constructor called\n";
	this->name = name;
	this->AttackDamage = 20;
	this->hitPoints = 100;
	this->energyPoints = 50;
}

ScavTrap::~ScavTrap()
{
	std::cout<<" ScavTrap Destructor called\n";
}


ScavTrap::ScavTrap(ScavTrap& obj) : ClapTrap(obj)
{
	std::cout<<"Copy constructor called\n";
	this->name = obj.name;
	this->AttackDamage = obj.AttackDamage;
	this->energyPoints = obj.energyPoints;
	this->hitPoints = obj.hitPoints;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& obj)
{
	std::cout<<"Copy operator called\n";
	this->name = obj.name;
	this->AttackDamage = obj.AttackDamage;
	this->energyPoints = obj.energyPoints;
	this->hitPoints = obj.hitPoints;
	return *this;
}

void ScavTrap::guardGate()
{
	static int guarding = 0;

	if (guarding == 0)
	{
		std::cout<<this->name<<" is now in in Gate keeper mode\n";
		guarding = 1;
	}
	else
	{
		std::cout<<this->name<<" is not in Gate keeper mode anymore\n";
		guarding = 0;
	}
}
