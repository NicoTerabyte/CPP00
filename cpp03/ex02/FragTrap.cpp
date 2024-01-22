/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 19:22:35 by lnicoter          #+#    #+#             */
/*   Updated: 2024/01/22 14:54:48 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout<<"FragTrap default constructor called\n";
	this->name = "FragTrap";
	this->AttackDamage = 30;
	this->energyPoints = 100;
	this->hitPoints = 100;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout<<"FragTrap constructor called\n";
	this->name = name;
	this->AttackDamage = 30;
	this->energyPoints = 100;
	this->hitPoints = 100;
}

FragTrap::~FragTrap()
{
	std::cout<<"FragTrap Destructor called\n";
}

FragTrap::FragTrap(const FragTrap& obj) : ClapTrap(obj)
{
	std::cout<<"FragTrap Copy constructor called\n";
	this->name = obj.name;
	this->AttackDamage = obj.AttackDamage;
	this->energyPoints = obj.energyPoints;
	this->hitPoints = obj.hitPoints;
}

FragTrap& FragTrap::operator=(const FragTrap& obj)
{
	std::cout<<"FragTrap copy operator called\n";
	this->name = obj.name;
	this->AttackDamage = obj.AttackDamage;
	this->energyPoints = obj.energyPoints;
	return *this;
}

void FragTrap::highFiveGuys(void)
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
