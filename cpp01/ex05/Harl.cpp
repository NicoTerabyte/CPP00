/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:36:13 by lnicoter          #+#    #+#             */
/*   Updated: 2024/01/04 16:49:16 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

/*		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
*/

void Harl::debug(void)
{
	std::cout << " love having extra bacon for my"
	<< "7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n";
}

void Harl::info(void)
{
	std::cout << " cannot believe adding extra bacon costs more money. You didn’t put"
		<< "enough bacon in my burger! If you did, I wouldn’t be asking for more!\n";
}


void Harl::warning(void)
{
	std::cout << " think I deserve to have some extra bacon for free. I’ve been coming for"
			<< "years whereas you started working here since last month.\n";
}

void Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now.\n";
}

void Harl::complain(std::string level)
{
	//nota personale:
	/*
	non serve creare una variabile classe per usare
	il puntatore ad una funzione membro della classe
	se stai già usando un metodo della classe
	puoi usare this
	*/
	void (Harl::*functionPointerArray[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string action[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
	{
		if (!action[i].compare(level))
			(this->*functionPointerArray[i])();
	}
}
