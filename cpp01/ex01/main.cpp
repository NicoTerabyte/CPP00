/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 18:56:35 by lnicoter          #+#    #+#             */
/*   Updated: 2023/12/28 19:03:06 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie* horde = zombieHorde(5, "carlo");

	for (int i = 0; i < 5; i++)
		horde[i].announce();
	delete[] horde; //modo per deallocare un array di oggetti in una riga
}
