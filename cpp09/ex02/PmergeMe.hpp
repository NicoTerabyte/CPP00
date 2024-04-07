/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 23:10:18 by lnicoter          #+#    #+#             */
/*   Updated: 2024/04/07 19:36:55 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

/*
speculazione sull'utilizzo dei container

penso che la deque venga usata all'inizio e alla fine della procedura di ordinamento
perché esso è ESTREMAMENTE efficente nell'inserimento dei valori al suo interno
o della loro eliminazione, time complexity O(1) rispetto al vettore che sarebbe O(N).

devo usare la ricorsione a quanto pare
deque A B?
*/
#include <iostream>
#include <sstream>
#include <exception>
#include <iterator>
#include <vector>
#include <deque>
#include <sys/time.h>
#include <algorithm>
#include <utility>

class PmergeMe
{
	private:
		std::deque<int>dequeAlgorithm;
		std::vector<int>vectorAlgorithm;
	public:
		PmergeMe(std::deque<int> dequeAlgorithm, std::vector<int> vectorAlgorithm);
		~PmergeMe();
		PmergeMe(const PmergeMe& obj);
		PmergeMe& operator=(const PmergeMe& obj);

		//optional functions for me
		void	printCont();
		void	printPairsVec(std::vector<std::pair<int, int> >& vectorPairs);
		//important functions for the ex
		void	vectorMergeInsert();
		void	dequeMergeInsert();
		void	sortPairVectorVer(std::vector<std::pair<int, int> >& vectorPairs);
};

#endif
