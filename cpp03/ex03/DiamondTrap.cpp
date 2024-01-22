/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 21:29:34 by lnicoter          #+#    #+#             */
/*   Updated: 2024/01/22 14:16:38 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), ScavTrap(name), FragTrap(name)
{
	std::cout<<"The ibrid constructor has been called"<<std::endl;
	this->name = name;
	this->ClapTrap::name = name + "_clap_name";
	this->hitPoints = FragTrap::hitPoints;
	this->energyPoints = ScavTrap::energyPoints;
	this->AttackDamage = FragTrap::AttackDamage;
}

DiamondTrap::~DiamondTrap()
{
	std::cout<<"The ibrid destructor has been called"<<std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& obj) : ClapTrap(obj), ScavTrap(obj), FragTrap(obj)
{
	std::cout<<"Ibrid Copy constructor called\n";
	this->name = obj.name;
	this->ClapTrap::name = obj.ClapTrap::name;
	this->AttackDamage = obj.AttackDamage;
	this->energyPoints = obj.energyPoints;
	this->hitPoints = obj.hitPoints;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& obj)
{
	std::cout<<"Ibrid Assignement operator called\n";
	this->name = obj.name;
	this->ClapTrap::name = obj.ClapTrap::name;
	this->AttackDamage = obj.AttackDamage;
	this->energyPoints = obj.energyPoints;
	this->hitPoints = obj.hitPoints;
	return *this;
}

void DiamondTrap::whoAmI()
{
	std::cout<<"My name is "<<this->name<<" but at the same time i am "<<ClapTrap::name<<std::endl;
}

