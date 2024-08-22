/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 17:06:06 by lnicoter          #+#    #+#             */
/*   Updated: 2024/08/22 14:41:45 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"



/*
Analisi del codice:
main
	il main e dove avviene l'inizializzazione dei container
	i quali appena inizializzati verranno passati nel costruttore
	della classe PmergeMe creando l'apposito oggetto
	Ho utilizzato la còasse stringstream per eseguire una conversione
	numerica fluida e senza intoppi
	Ho anche eseguito un piccolo controllo sul numero convertito visto che 'algoritmo
	e la consegna dicevano di accettare solo numeri positivi interi
	Il subject non parla di valori duplicati inacettati

*/

//! This check is futile 🦅
void	checkDup(std::deque<int> dequeMerge)
{
	for (int i = 1; (size_t)i < dequeMerge.size(); i++)
	{
		int j = 0;
		while (j != i)
		{

			if (dequeMerge[j] == dequeMerge[i])
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
			checkDup(dequeCont);
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
