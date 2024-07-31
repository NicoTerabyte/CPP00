/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 17:01:50 by lnicoter          #+#    #+#             */
/*   Updated: 2024/07/30 14:40:33 by lnicoter         ###   ########.fr       */
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
//algoritmo che teoricamente ordina le coppie mettendo il più grande tra i due
//al secondo posto
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

	//questo dovrebbe essere il merge sort?
	//però lacca la ricorsione da qualche parte
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
		lowest.push_back(rejected); //questo va bene
	binarySearchSortVec(biggest, lowest);
}

/*
Novità
Questa linea di codice in C++ sta aggiungendo un nuovo elemento
alla fine dell'array splittedArray. L'elemento aggiunto è un array,
che contiene un solo elemento preso dall'array vectorAlgorithm all'indice i.
Le graffe {} in questo contesto sono usate per inizializzare un nuovo array.
Poiché vectorAlgorithm[i] è un elemento singolo,
le graffe sono usate per creare un array che contiene solo quell'elemento.
Questo è necessario perché splittedArray è un array di array,
quindi ogni elemento in splittedArray deve essere un array,
anche se contiene solo un elemento.
	*/

std::vector<int>	PmergeMe::createPairs()
{
	std::vector<std::vector<int> >	splittedArray;
	std::vector<int>				tmpArray;

	for (size_t i = 0; i < vectorAlgorithm.size(); ++i)
	{
		int	tmpLength = tmpArray.size();
		if (tmpLength == 1)
		{
			tmpArray.push_back(vectorAlgorithm[i]);
			splittedArray.push_back(tmpArray);
		}
		else if ((splittedArray.size() * 2) == (vectorAlgorithm.size() - 1))
			splittedArray.push_back({vectorAlgorithm[i]});
		else if (tmpLength == 0)
			tmpArray.push_back(vectorAlgorithm[i]);
	}
}
//if the vector is odd i save the last value
//and i pop it out of the vector

double	PmergeMe::vectorMergeInsert()
{
	clock_t	start, end;
	int		rejected;
	bool	odd = false;
	std::vector<std::pair<int, int> >	pairs;

	start = clock();
	//salvataggio del valore che rende l'array dispari
	if (vectorAlgorithm.size() % 2 != 0)
	{
		odd = true;
		rejected = vectorAlgorithm.back();
		vectorAlgorithm.pop_back();
	}
	//creazione delle coppie
	for (size_t i = 0; i < vectorAlgorithm.size(); i += 2)
	{
		std::pair<int, int> tmpPair(vectorAlgorithm[i], vectorAlgorithm[i + 1]);
		pairs.push_back(tmpPair);
	}
	//funzione che teoricamente dovrebbe ordinare le coppie
	sortPairVectorVer(pairs);
	dividePair(pairs, rejected, odd);
	end = clock();
	double elapsed_time = (double)(end - start) / CLOCKS_PER_SEC * 1000000;
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

/*----Output requested section part----*/

/*this part could be put away becasue it doesn't seem good enough*/
// void	printOut(PmergeMe containers, std::string argv)
// {
// 	struct timeval	start, end;
// 	std::cout<<"Before";
// 	for (int i = 1; i < argv.size(); i++)
// 		std::cout<<argv[i];
// 	std::cout<<""<<std::endl;
// 	std::cout<<"After";
// }


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
	std::cout<<"Time to process a range of "<<ac<<" elements with std::vector : "<<std::fixed << std::showpoint << std::setprecision(5)<<vecDiff / 100<<" us"<<std::endl;
	std::cout<<"Time to process a range of"<<ac<<" elements with std::deque : "<<std::fixed << std::showpoint << std::setprecision(5)<<deqDiff / 100<<" us"<<std::endl;
}
/*----Output requested section part end----*/
