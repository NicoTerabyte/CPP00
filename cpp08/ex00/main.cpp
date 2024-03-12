/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:03:23 by lnicoter          #+#    #+#             */
/*   Updated: 2024/03/12 19:15:34 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.h"

int	main(void)
{
	try
	{
		std::vector<int> easyV;

		easyV.push_back(1);
		easyV.push_back(2);
		easyV.push_back(4);
		easyV.push_back(5);
		easyV.push_back(7);

		easyfind<int>(easyV, 43);
	}
	catch(const std::exception& e)
	{
		std::cout<<e.what()<<std::endl;
	}
	return (0);
}
