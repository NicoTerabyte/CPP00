/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 22:17:46 by lnicoter          #+#    #+#             */
/*   Updated: 2023/12/30 21:53:05 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
	private:
		std::string name;
		Weapon* bWeapon;

	public:
		HumanB(std::string name);
		//HumanB(std::string name, Weapon* bWeapon);
		~HumanB();
		void setWeapon(Weapon &newWeapon);
		void attack();
};

#endif
