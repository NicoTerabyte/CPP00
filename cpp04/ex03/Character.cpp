/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 21:21:14 by lnicoter          #+#    #+#             */
/*   Updated: 2024/01/17 15:20:27 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"


Character::Character()
{
	this->cName = "Lorenzo";
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
}

Character::Character(std::string name)
{
	this->cName = name;
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
}

Character::~Character()
{
}

Character::Character(Character& obj)
{
	for (int i = 0; i < 4; i++)
		this->inventory[i] = obj.inventory[i];
}

Character& Character::operator=(const Character& obj)
{
	for (int i = 0; i < 4; i++)
		this->inventory[i] = obj.inventory[i];
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
	if (idx < 4 && idx >= 0 && this->inventory[idx] != NULL)
	{
		std::cout<<"Materia "<<this->inventory[idx]->getType()<<" unequipped"<<std::endl;
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
