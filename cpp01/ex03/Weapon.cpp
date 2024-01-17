/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 22:12:28 by lnicoter          #+#    #+#             */
/*   Updated: 2024/01/17 23:33:38 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon()
{}

Weapon::Weapon(std::string type)
{
	this->type = type;
}

Weapon::~Weapon()
{}

//dev'essere diverso? chiedi a manu
std::string Weapon::getType(void)
{
	return this->type;
}

void Weapon::setType(std::string type)
{
	this->type = type;
}
