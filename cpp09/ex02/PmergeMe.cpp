/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 17:01:50 by lnicoter          #+#    #+#             */
/*   Updated: 2024/04/19 20:00:31 by lnicoter         ###   ########.fr       */
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

	// for (it = biggest.begin(); it != biggest.end(); it++)
	// 	std::cout<<*it<<std::endl;
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

	//i sort the biggest sequence:
	binarySearchSortVec(biggest, lowest);
}

void	PmergeMe::vectorMergeInsert()
{
	int		rejected;
	bool	odd = false;

	std::vector<std::pair<int, int> >	pairs;
	//if the vector is odd i save the last value
	//and i pop it out of the vector
	if (vectorAlgorithm.size() % 2 != 0)
	{
		odd = true;
		rejected = vectorAlgorithm.back();
		vectorAlgorithm.pop_back();
	}
	for (size_t i = 0; i < vectorAlgorithm.size(); i += 2)
	{
		std::pair<int, int> tmpPair(vectorAlgorithm[i], vectorAlgorithm[i + 1]);
		pairs.push_back(tmpPair);
	}
	sortPairVectorVer(pairs);
	dividePair(pairs, rejected, odd);
}


/*deque merge insetion sort algorithm section*/

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
	// for (it = biggest.begin(); it != biggest.end(); it++)
	// 	std::cout<<*it<<std::endl;
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

void	PmergeMe::dequeMergeInsert()
{
	int		rejected;
	bool	odd = false;
	std::deque<int>::iterator	it;
	std::deque<std::pair<int, int> >pairs;
	//if the deque is odd i save the last value
	//and i pop it out of the deque;
	std::cout<<"deque sorting beta deque size too "<<this->dequeAlgorithm.size()<<std::endl;
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
}