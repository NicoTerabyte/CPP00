/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:19:07 by lnicoter          #+#    #+#             */
/*   Updated: 2024/01/09 17:38:14 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	std::string	name;
	int			action = 1;

	std::cout<<"Give the claptrap a name ";
	std::cin>>name;

	ScavTrap bot(name);
	// ClapTrap beta("Gianni");
	while (action)
	{
		std::cout<<"What wille the bot do?\n Attack(1)\n Heal(2)\n"
				<<"Put the bot in gate Keeper mode(3)\n"
				<<"press(0) if the bot died or if you're an idiot\n"
				<<"please insert a number\n";
		std::cin>>action;
		if (action == 1)
			bot.attack("Atucci");
		else if (action == 2)
			bot.beRepaired(5);
		else if (action == 3)
			bot.guardGate();
		bot.takeDamage(50);
	}
	// action = 1;
	// while (action)
	// {
	// 	std::cout<<"second bot go\n";
	// 	std::cout<<"What wille the bot do?\n Attack(1)\n Heal(2)\n"
	// 			<<"press(0) if the bot died or if you're an idiot\n"
	// 			<<"please insert a number\n";
	// 	std::cin>>action;
	// 	if (action == 1)
	// 		beta.attack("Atucci");
	// 	else if (action == 2)
	// 		beta.beRepaired(5);
	// 	beta.takeDamage(3);
	// }
}
