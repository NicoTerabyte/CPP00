/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 21:21:14 by lnicoter          #+#    #+#             */
/*   Updated: 2024/01/23 17:31:27 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"


Character::Character()
{
	this->cName = "Lorenzo";
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
	for (int i = 0; i < 100; i++)
		this->floor[i] = NULL;
}

Character::Character(std::string name)
{
	this->cName = name;
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
	for (int i = 0; i < 100; i++)
		this->floor[i] = NULL;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i])
			delete this->inventory[i];
	}
	for (int i = 0; i < 100; i++)
	{
		if (this->floor[i])
			delete this->floor[i];
	}
}

Character::Character(const Character& obj)
{
	for (int i = 0; i < 4; i++)
		this->inventory[i] = obj.inventory[i];
	for (int i = 4; i < 100; i++)
		this->floor[i] = obj.floor[i];
}

Character& Character::operator=(const Character& obj)
{
	for (int i = 0; i < 4; i++)
		this->inventory[i] = obj.inventory[i];
	for (int i = 4; i < 100; i++)
		this->floor[i] = obj.floor[i];
	return *this;
}

std::string const & Character::getName() const
{
	return this->cName;
}

void Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i] == NULL)
		{
			this->inventory[i] = m;
			return ;
		}
	}
}

void Character::unequip(int idx)
{
	static int theFloor = 0;

	if (idx < 4 && idx >= 0 && this->inventory[idx] != NULL)
	{
		std::cout<<"Materia "<<this->inventory[idx]->getType()<<" unequipped"<<std::endl;
		this->floor[theFloor] = this->inventory[idx];
		theFloor++;
		this->inventory[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 4 && this->inventory[idx] != NULL)
	{
		this->inventory[idx]->use(target);
	}
}
