/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 17:06:06 by lnicoter          #+#    #+#             */
/*   Updated: 2024/08/22 14:52:41 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void	checkDup(std::vector<int> vectorMerge)
{
	for (int i = 1; (size_t)i < vectorMerge.size(); i++)
	{
		int j = 0;
		while (j != i)
		{

			if (vectorMerge[j] == vectorMerge[i])
				throw std::runtime_error("\033[1;31mFound a duplicate in the container !!\033[0m\n");
			j++;
		}
	}
}

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
				if (convNum < 0)
					throw std::runtime_error("Only positive numbers please");
				if (ss.fail())
					throw std::runtime_error("That was a letter you maggot 🦅🦅🦅");
				dequeCont.push_back(convNum);
				vectorCont.push_back(convNum);
			}
			checkDup(vectorCont);
			PmergeMe	fordJohnson(dequeCont, vectorCont);
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
