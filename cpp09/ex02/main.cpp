/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 17:06:06 by lnicoter          #+#    #+#             */
/*   Updated: 2024/08/02 11:49:59 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"



/*
TASK COMPLETATE:
	//altro controllo da inserire e tenere conto della quantità dei valori adesso faccio il dovuto check
	//	-> Da quanto visto nel subject il massimo numero di valori stampabili è 5
	//	-> appena supero quella quantità devo stamparne 4 mettendo [...] subito dopo
	//	-> 1 2 3 4 [...]
*/
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
	// Quindi dovrebbe essere ok, nel dubbio metto il controllo pare che non serva farlo
	//	todo: visto che con i check richiesti nel subject pare che il programma
	//	todo: ordini in maniera smooth
	TODO: Check che sia un numero e non una lettera
*/

//! This check is futile 🦅
void	checkDup(std::deque<int> dequeMerge)
{
	for (int i = 0; (size_t)i < dequeMerge.size(); i++)
	{
		int j = i;
		while (j != 0)
		{
			if (dequeMerge[j] == dequeMerge[i])
				throw std::runtime_error("\033[1;31mFound a duplicate in the container !!\033[0m\n");
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
				if (convNum < 0) //gestire i casi particolari c'e ne sono altri
					throw std::runtime_error("Only positive numbers please");
				dequeCont.push_back(convNum);
				vectorCont.push_back(convNum);
			}
			// checkDup(dequeCont);
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
