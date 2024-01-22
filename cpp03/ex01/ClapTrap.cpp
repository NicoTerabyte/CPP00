/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:52:53 by lnicoter          #+#    #+#             */
/*   Updated: 2024/01/22 14:23:23 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	AttackDamage = 0;
	energyPoints = 10;
	hitPoints = 10;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "ClapTrap Constructor called\n";
	this->name = name;
	AttackDamage = 0;
	energyPoints = 10;
	hitPoints = 10;
}

ClapTrap::~ClapTrap()
{
	std::cout<<"ClapTrap Destructor called\n";
}

ClapTrap::ClapTrap(const ClapTrap& obj)
{
	std::cout<<"Copy constructor called\n";
	this->name = obj.name;
	this->AttackDamage = obj.AttackDamage;
	this->energyPoints = obj.energyPoints;
	this->hitPoints = obj.hitPoints;
}

ClapTrap ClapTrap::operator=(const ClapTrap& obj)
{
	std::cout<<"Copy operator called\n";
	this->name = obj.name;
	this->AttackDamage = obj.AttackDamage;
	this->energyPoints = obj.energyPoints;
	this->hitPoints = obj.hitPoints;
	return *this;
}

		// void	attack(const std::string &target);
		// void	takeDamage(unsigned int amount);
		// void	beRepaired(unsigned int amount);

void ClapTrap::attack(const std::string& target)
{
	if (this->energyPoints > 0 && this->hitPoints > 0)
	{
		std::cout<<"Claptrap "<<this->name<<" attacks "
		<<target<<", causing "<<this->AttackDamage<<" points of damage!\n";
		this->energyPoints--;
	}
	else
		std::cout<<"No energy or hit points left, "<<this->name<<" can't act anymore\n";
	std::cout<<"Energy left to act "<<this->energyPoints;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->energyPoints >= 0 && this->hitPoints >= 0)
	{
		this->hitPoints-=amount;
		if (this->hitPoints <= 0)
		{
			std::cout<<this->name<<" has been defeated no hitpoints left\n";
			this->hitPoints = 0;
		}
		else
			std::cout<<this->name<<" got hit "<<this->hitPoints<<" left\n";
	}
	else
		std::cout<<this->name<<" is defeated or has finished his energy\n";
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energyPoints > 0 && this->hitPoints > 0)
	{
		this->hitPoints += amount;
		this->energyPoints--;
		std::cout<<this->name<<" restored "<<amount<<" hitpoints, now he has "
				<<this->hitPoints<<" in total\n";
	}
	else
		std::cout<<"No energy or hit points left, "<<this->name<<" can't act anymore\n";
	std::cout<<"Energy left to act "<<this->energyPoints;
}
