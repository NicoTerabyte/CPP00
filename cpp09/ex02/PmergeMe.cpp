/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 17:01:50 by lnicoter          #+#    #+#             */
/*   Updated: 2024/07/31 20:00:45 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
/*----costrucotrs, orthodoxical part----*/

PmergeMe::PmergeMe(std::deque<int>dequeAlgorithm, std::vector<int>vectorAlgorithm) :
	dequeAlgorithm(dequeAlgorithm), vectorAlgorithm(vectorAlgorithm)
{}

PmergeMe::~PmergeMe()
{}

PmergeMe::PmergeMe(const PmergeMe& obj) :
		dequeAlgorithm(obj.dequeAlgorithm) , vectorAlgorithm(obj.vectorAlgorithm)
{}

PmergeMe& PmergeMe::operator=(const PmergeMe& obj)
{
	this->vectorAlgorithm = obj.vectorAlgorithm;
	this->dequeAlgorithm = obj.dequeAlgorithm;

	return *this;
}

/*----costructor orthodoxical part end----*/

/*----Optional functions just for me part----*/
void	PmergeMe::printCont()
{
	std::deque<int>::iterator	it;
	std::vector<int>::iterator	itVec;

	for (it = dequeAlgorithm.begin(); it != dequeAlgorithm.end(); it++)
		std::cout<<"deque value "<<*it<<std::endl;
	for (itVec = vectorAlgorithm.begin(); itVec != vectorAlgorithm.end(); itVec++)
		std::cout<<"vector value "<<*itVec<<std::endl;
}

void	PmergeMe::printPairsVec(std::vector<std::pair<int, int> >& vectorPairs)
{
	std::vector<std::pair<int, int> >::iterator	it;

	for (it = vectorPairs.begin(); it != vectorPairs.end(); it++)
	{
		std::cout<<"("<<it->first<<", "<<it->second<<")"<<std::endl;
	}
}

void	PmergeMe::printPairsDeq(std::deque<std::pair<int, int> >& dequePairs)
{
	std::deque<std::pair<int, int> >::iterator	it;

	for (it = dequePairs.begin(); it != dequePairs.end(); it++)
	{
		std::cout<<"("<<it->first<<", "<<it->second<<")"<<std::endl;
	}
}
/*----Optional functions just for me PART END----*/

/*----Vector Algorithm part----*/
void	PmergeMe::sortPairVectorVer(std::vector<std::pair<int, int> >& vectorPairs)
{
	std::vector<std::pair<int, int> >::iterator	it;
	int											tmp = 0;

	for (it = vectorPairs.begin(); it != vectorPairs.end(); it++)
	{
		if (it->first > it->second)
		{
			tmp = it->first;
			it->first = it->second;
			it->second = tmp;
		}
	}
}


//questo alla fine prima ordinare uno dei due vettori
// void	binarySearchSortVec(std::vector<int>& biggest)

void	PmergeMe::binarySearchSortVec(std::vector<int>& biggest, std::vector<int>& lowest)
{
	std::vector<int>::iterator	it;

	for (size_t i = 0; i < lowest.size(); i++)
	{
		biggest.insert(std::lower_bound(biggest.begin(), biggest.end(), lowest[i]), lowest[i]);
	}
	this->vectorAlgorithm = biggest;
}

void	PmergeMe::dividePair(std::vector<std::pair<int, int> >& vectorPairs, int rejected, bool odd)
{
	std::vector<int>	lowest;
	std::vector<int>	biggest;
	std::vector<std::pair<int, int> >::iterator	it;

	for (it = vectorPairs.begin(); it != vectorPairs.end(); it++)
	{
		if (biggest.empty())
		{
			biggest.push_back(it->second);
		}
		else
		{
			bool	inserted = false;

			for (size_t i = 0; i < biggest.size(); i++)
			{
				if (it->second < biggest[i])
				{
					biggest.insert(biggest.begin() + i, it->second);
					inserted = true;
					break;
				}
			}
			if (!inserted)
				biggest.push_back(it->second);
		}
		lowest.push_back(it->first);
	}
	if (odd)
		lowest.push_back(rejected);
	binarySearchSortVec(biggest, lowest);
}

//if the vector is odd i save the last value
//and i pop it out of the vector

//2.1 funzione utilizzata per ordinare il vettore
double	PmergeMe::vectorMergeInsert()
{
	clock_t	start, end;
	int		rejected;
	bool	odd = false;
	std::vector<int>::iterator	it;
	std::vector<std::pair<int, int> >	pairs;

	start = clock();
	//fase uno determinare la grandezza del container
	//Una grandezza dispari determina la necessità di salvare il valore
	//l'ultimo a parte e toglierlo dal container
	//quindi fase 1 ok
	if (vectorAlgorithm.size() % 2 != 0)
	{
		odd = true;
		rejected = vectorAlgorithm.back();
		vectorAlgorithm.pop_back();
	}
	for (it = this->vectorAlgorithm.begin(); it != (this->vectorAlgorithm.end() - 1)
	&& it != this->vectorAlgorithm.end()	; it+=2)
	{
		std::pair<int, int>	tmpPair(*it, *(it + 1));
		pairs.push_back(tmpPair);
	}
	dividePair(pairs, rejected, odd);
	end = clock();
	double elapsed_time = (double)(end - start) / CLOCKS_PER_SEC * 1000000;
	(void) rejected;
	(void) odd;
	return (elapsed_time);
}
/*----Vector Algorithm part----*/

/*----deque merge insertion sort algorithm section----*/

void	sortPairDequeVer(std::deque<std::pair<int, int> >& dequePairs)
{
	std::deque<std::pair<int, int> >::iterator	it;
	int											tmp = 0;

	for (it = dequePairs.begin(); it != dequePairs.end(); it++)
	{
		if (it->first > it->second)
		{
			tmp = it->first;
			it->first = it->second;
			it->second = tmp;
		}
	}
};

void	PmergeMe::binarySearchSortDeq(std::deque<int>& biggest, std::deque<int>& lowest)
{
	std::deque<int>::iterator	it;

	for (size_t i = 0; i < lowest.size(); i++)
	{
		biggest.insert(std::lower_bound(biggest.begin(), biggest.end(), lowest[i]), lowest[i]);
	}
	this->dequeAlgorithm = biggest;
}

void	PmergeMe::phase2Deque(std::deque<std::pair<int, int> >& dequePairs, int rejected, bool odd)
{
	std::deque<int>	lowest;
	std::deque<int>	biggest;
	std::deque<std::pair<int, int> >::iterator	it;

	for (it = dequePairs.begin(); it != dequePairs.end(); it++)
	{
		if (biggest.empty())
		{
			biggest.push_back(it->second);
		}
		else
		{
			bool	inserted = false;

			for (size_t i = 0; i < biggest.size(); i++)
			{
				if (it->second < biggest[i])
				{
					biggest.insert(biggest.begin() + i, it->second);
					inserted = true;
					break;
				}
			}
			if (!inserted)
				biggest.push_back(it->second);
		}
		lowest.push_back(it->first);
	}
	if (odd)
		lowest.push_back(rejected);
	binarySearchSortDeq(biggest, lowest);
}

//if the deque is odd i save the last value
//and i pop it out of the deque;

double	PmergeMe::dequeMergeInsert()
{
	clock_t start, end;
	int		rejected;
	bool	odd = false;
	std::deque<int>::iterator	it;
	std::deque<std::pair<int, int> >pairs;

	start = clock();
	if (dequeAlgorithm.size() % 2 != 0)
	{
		odd = true;
		rejected = dequeAlgorithm.back();
		dequeAlgorithm.pop_back();
	}
	for (it = this->dequeAlgorithm.begin(); it != (this->dequeAlgorithm.end() - 1)
	&& it != this->dequeAlgorithm.end()	; it+=2)
	{
		std::pair<int, int>	tmpPair(*it, *(it + 1));
		pairs.push_back(tmpPair);
	}
	phase2Deque(pairs, rejected, odd);
	end = clock();

	double	elapsed_time = (double)(end - start) / CLOCKS_PER_SEC * 1000000;
	return (elapsed_time);
}
/*----deque merge insertion sort algorithm section end----*/



//aggiornameto del 31/07/2024
//l'algoritmo funziona per la deque ma non è stata fatta
//la versione per il container vector
void	PmergeMe::mergeInsertionSort(char** argv, int ac)
{
	double	vecDiff, deqDiff;

	std::cout<<"Before:  ";
	for (size_t i = 1; argv[i]; i++)
		std::cout<<argv[i]<<" ";
	std::cout<<""<<std::endl;
	std::cout<<"After:  ";
	vecDiff = vectorMergeInsert();
	deqDiff = dequeMergeInsert();
	for (size_t i = 0; i < vectorAlgorithm.size(); i++)
		std::cout<<vectorAlgorithm[i]<<" ";
	std::cout<<""<<std::endl;
	for (size_t i = 0; i < dequeAlgorithm.size(); i++)
		std::cout<<dequeAlgorithm[i]<<" ";
	std::cout<<""<<std::endl;
	std::cout<<"Time to process a range of "<<ac<<" elements with std::vector : "<<std::fixed << std::showpoint << std::setprecision(5)<<vecDiff / 100<<" us"<<std::endl;
	std::cout<<"Time to process a range of"<<ac<<" elements with std::deque : "<<std::fixed << std::showpoint << std::setprecision(5)<<deqDiff / 100<<" us"<<std::endl;
}
/*----Output requested section part end----*/
