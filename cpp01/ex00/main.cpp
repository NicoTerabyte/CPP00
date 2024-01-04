/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 18:56:35 by lnicoter          #+#    #+#             */
/*   Updated: 2023/12/29 15:07:37 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie firstZombie("carlo");
	Zombie *secondZombie = newZombie("piero");

	firstZombie.announce();
	secondZombie->announce();
	randomChump("genoveffo");
	
	delete secondZombie;
}
