/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 22:27:33 by lnicoter          #+#    #+#             */
/*   Updated: 2024/01/17 23:36:06 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

// HumanA(std::string name, Weapon theWeapon);
// 		~HumanA();
// 		void attack();

HumanA::HumanA(std::string name, Weapon& aWeapon): name(name), aWeapon(aWeapon)
{}

HumanA::~HumanA()
{
	std::cout << "The Human left the battle\n";
}

void HumanA::attack()
{
	std::cout << this->name;
	std::cout <<" Attacked with: " << this->aWeapon.getType() << std::endl;
}
