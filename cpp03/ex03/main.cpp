/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:19:07 by lnicoter          #+#    #+#             */
/*   Updated: 2024/01/22 00:06:00 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main(void)
{
	std::string	name;
	// int			action = 1;

	std::cout<<"Give the claptrap a name ";
	std::cin>>name;

	DiamondTrap theBeast(name);

	theBeast.attack("Osema");
	theBeast.beRepaired(10);
	theBeast.guardGate();
	theBeast.highFiveGuys();
	theBeast.takeDamage(10);
	theBeast.whoAmI();
}
