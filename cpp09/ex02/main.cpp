/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 17:06:06 by lnicoter          #+#    #+#             */
/*   Updated: 2024/07/31 17:38:00 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int ac, char **av)
{
	std::deque<int>		dequeCont;
	std::vector<int>	vectorCont;

	if (ac != 1)
	{
		try
		{
			int					convNum;
			std::stringstream	ss;
			for (int i = 1; av[i]; i++)
			{
				ss.clear();
				ss.str(av[i]);
				ss >> convNum;
				if (convNum < 0) //gestire i casi particolari c'e ne sono altri
					throw std::runtime_error("Only positive numbers please");
				dequeCont.push_back(convNum);
				vectorCont.push_back(convNum);
			}
			PmergeMe	fordJohnson(dequeCont, vectorCont);
			//from here i will start doing the fordJohnson
			fordJohnson.mergeInsertionSort(av, ac - 1);
		}
		catch (const std::exception& e)
		{
			std::cout<<e.what()<<std::endl;
		}
	}
	else
		std::cout<<"Error, put at least one argument"<<std::endl;

	return (0);
}
