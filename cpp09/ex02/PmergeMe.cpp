/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 17:01:50 by lnicoter          #+#    #+#             */
/*   Updated: 2024/04/07 19:39:27 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

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


void	PmergeMe::printCont()
{
	std::deque<int>::iterator	it;

	for (it = dequeAlgorithm.begin(); it != dequeAlgorithm.end(); it++)
		std::cout<<"deque value "<<*it<<std::endl;

}

void	PmergeMe::printPairsVec(std::vector<std::pair<int, int> >& vectorPairs)
{
	std::vector<std::pair<int, int> >::iterator	it;

	for (it = vectorPairs.begin(); it != vectorPairs.end(); it++)
	{
		std::cout<<"("<<it->first<<", "<<it->second<<")"<<std::endl;
	}
}

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

void	PmergeMe::vectorMergeInsert()
{
	int		rejected;
	std::vector<std::pair<int, int> >	pairs;
	//if the vector is odd i save the last value
	//and i pop it out of the vector
	if (vectorAlgorithm.size() % 2 != 0)
	{
		rejected = vectorAlgorithm.back();
		vectorAlgorithm.pop_back();
	}
	for (size_t i = 0; i < vectorAlgorithm.size(); i += 2)
	{
		std::pair<int, int> tmpPair(vectorAlgorithm[i], vectorAlgorithm[i + 1]);
		pairs.push_back(tmpPair);
	}
	sortPairVectorVer(pairs);
	printPairsVec(pairs);
	(void)rejected;
}

void	PmergeMe::dequeMergeInsert()
{
	int		rejected;

	//if the deque is odd i save the last value
	//and i pop it out of the deque
	if (dequeAlgorithm.size() % 2 != 0)
	{
		rejected = dequeAlgorithm.back();
		dequeAlgorithm.pop_back();
	}
	(void)rejected;
}
