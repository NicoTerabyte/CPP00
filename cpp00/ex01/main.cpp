/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:09:29 by lnicoter          #+#    #+#             */
/*   Updated: 2023/12/22 16:59:15 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	first;
	bool		exit_flag;
	std::string action;

	exit_flag = true;
	while(exit_flag)
	{
		std::cout << "Choose an action to do\nADD\nSEARCH\nEXIT\n" <<std::endl;
		if (!getline(std::cin, action))
		{
			std::cout << "you pressed ctrl + D didn't you?\n";
			exit_flag = false;
			break ;
		}
		if (action == "ADD")
			first.add();
		if (action == "SEARCH")
			first.search();
		if (action == "EXIT")
			exit_flag = false;
	}
}
