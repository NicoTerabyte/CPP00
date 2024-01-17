/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:09:29 by lnicoter          #+#    #+#             */
/*   Updated: 2024/01/17 19:24:40 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	first;
	// bool		exit_flag;
	std::string action;

	// exit_flag = true;
	while (action.compare("EXIT"))
	{
		std::cout << "Choose an action to do\nADD\nSEARCH\nEXIT\n" <<std::endl;
		if (!std::getline(std::cin, action))
			break ;
		if (action == "ADD")
			first.add();
		if (action == "SEARCH")
			first.search();
	}
}
