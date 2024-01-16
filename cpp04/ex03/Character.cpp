/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 21:21:14 by lnicoter          #+#    #+#             */
/*   Updated: 2024/01/12 17:47:05 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"


Character::Character()
{
	std::cout<<"Character constructor called"<<std::endl;
	this->cName = "Lorenzo";
	for (int i = 0; i < 4; i++)
		this->inventory[i] = nullptr;
}

Character::Character(std::string name)
{
	std::cout<<"Character constructor called"<<std::endl;
	this->cName = name;
	for (int i = 0; i < 4; i++)
		this->inventory[i] = nullptr;
}

Character::~Character()
{
	std::cout<<"Character destructor called"<<std::endl;
}

Character::Character(Character& obj)
{
	std::cout<<"Character copy constructor called"<<std::endl;
	for (int i = 0; i < 4; i++)
		this->inventory[i] = obj.inventory[i];
}

Character& Character::operator=(const Character& obj)
{
	std::cout<<"Character copy operator called"<<std::endl;
	for (int i = 0; i < 4; i++)
		this->inventory[i] = obj.inventory[i];
	return *this;
}

std::string const & Character::getName()
{
	return this->cName;
}

void Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i] == nullptr)
			this->inventory[i] = m;
	}
}

void Character::unequip(int idx)
{
	static AMateria* floor[100];
	static int floorIdx = 0;

	if (idx < 4 && this->inventory[idx])
	{
		floor[floorIdx] = this->inventory[idx];
		this->inventory[idx] = nullptr;
		floorIdx++;
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 4 && this->inventory[idx] != nullptr)
	{
		this->inventory[idx]->use(target);
	}
}
