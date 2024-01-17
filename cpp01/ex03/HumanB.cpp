/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 22:27:33 by lnicoter          #+#    #+#             */
/*   Updated: 2024/01/17 23:34:38 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

// HumanA(std::string name, Weapon theWeapon);
// 		~HumanA();
// 		void attack();

HumanB::HumanB(std::string name)
{
	this->name = name;
	this->bWeapon = NULL;
}

// HumanB::HumanB(std::string name, Weapon* bWeapon)
// {
// 	this->name = name;
// 	this->bWeapon = bWeapon;
// }

HumanB::~HumanB()
{
	std::cout << this->name << " left the battle" <<std::endl;
}

void HumanB::setWeapon(Weapon &newWeapon)
{
	this->bWeapon = &newWeapon;
}

void HumanB::attack()
{
	std::cout << this->name << "attacks with "<<this->bWeapon->getType()<<std::endl;

}
