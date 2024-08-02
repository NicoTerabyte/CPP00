/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 23:10:18 by lnicoter          #+#    #+#             */
/*   Updated: 2024/08/02 12:10:23 by lnicoter         ###   ########.fr       */
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

allora ho cambiato un po' la situazione qua, a quanto pare i due container
dovevano essere usati per fare due volte l'algoritmo su di essi e ordinarli rispettivamente
quindi attualmente possiediamo un vettore, e la deque da ordinare con due algoritmi distinti per essi
per ora sto seguendo una guida di cose da fare per comprendere bene step by step come approcciare il problema

fino ad ora ho riempito i due container, e ora mi sto concentrando sul vector
ho fatto la suddivisione in coppie per rispettare l'algoritmo e le ordinate per avere al
primo posto il più piccolo e al secondo il più grande della coppia ora vediamo un po' che devo
fare.

allora suddividendolo in step manca da fare:
	prendere le coppie e salvare le più piccole e le più grandi in due
	vettori separati, e poi ordinare le più piccole o le più grandi in ordine crescente
	dopo dovremo inserire i valori mancanti nel vettore ordinato


da quello che ho capito attualmente ciò che manca da implementare sarebbe
la sezione di jacobstahl, solo che ancora non mi è ben chiaro come si utilizza
e dove dovrei applicarlo nel mio codice

La jacobSthal implementation:



*/

/*
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
#include <iomanip>
#include <ctime>
#include <cstddef>

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
		//all for printing nothing to do with the logic but they are good
		//for debugging
		void	printSpecifiedCont(std::deque<int> pending);
		void	printCont();
		void	printPairsVec(std::vector<std::pair<int, int> >& vectorPairs);
		void	printPairsDeq(std::deque<std::pair<int, int> >& dequePairs);
		//important functions for the ex
		void	mergeInsertionSort(char** argv, int ac);
		int		jacobsthal(int containerLenght);
		std::vector<int> build_jacob_insertion_sequence(int array_len);
		//vector manipulation
		double	vectorMergeInsert();
		void	sortPairVectorVer(std::vector<std::pair<int, int> >& vectorPairs);
		void	binarySearchSortVec(std::vector<int>& biggest, std::vector<int>& lowest);
		void	dividePair(std::vector<std::pair<int, int> >& vectorPairs, int rejected, bool odd);
		//deque algorithm
		double	dequeMergeInsert();
		void	phase2Deque(std::deque<std::pair<int, int> >& dequePairs, int rejected, bool odd);
		void	binarySearchSortDeq(std::deque<int>& biggest, std::deque<int>& lowest);
		void	sortBiggest(std::deque<int>& biggest);
};
#endif
