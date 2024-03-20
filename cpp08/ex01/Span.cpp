/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 18:33:20 by lnicoter          #+#    #+#             */
/*   Updated: 2024/03/20 18:39:40 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <climits>

Span::Span(unsigned int n) : N(n)//, array(n)
{
	std::cout<<"Constructor called"<<std::endl;
}

Span::~Span()
{
	std::cout<<"span destructor called"<<std::endl;
}

Span::Span(const Span& obj) : N(obj.N), array(obj.array)
{
	std::cout<<"Copy constructor called"<<std::endl;
}

Span&	Span::operator=(const Span& obj)
{
	if (this != &obj)
	{
		this->array = obj.array;
	}
	return *this;
}


void	Span::addNumber(int	number)
{
	// srand(static_cast<unsigned int>(time(0)));

	if (this->array.size() == this->N)
		throw std::runtime_error("You're trying surpass the max numbers limit");
	// this->array.push_back((rand() % 10000 + 1));
	this->array.push_back(number);
}

int	Span::shortestSpan()
{
	int	shortest = 2147483647;

	if (this->array.size() < 2)
		throw std::runtime_error("There are not enough elements (min 2) to calculate the shortest span");
	for (std::vector<int>::iterator it = array.begin(); it != array.end(); ++it)
	{
		for (std::vector<int>::iterator jt = array.begin(); jt != array.end(); ++jt)
		{
			if (it != jt)
			{
				int currentDist = std::abs(*it - *jt);
				if (currentDist < shortest)
					shortest = currentDist;
			}
		}
	}
	return (shortest);
}

int	Span::longestSpan()
{


	if (this->array.size() < 2)
		throw std::runtime_error("There are not enough elements (min 2) to calculate the shortest span");

	std::vector<int>::iterator max = std::max_element(this->array.begin(), this->array.end());
	std::vector<int>::iterator min = std::min_element(this->array.begin(), this->array.end());
	return (*max - *min);
}

void	Span::allInOne()
{
	srand(static_cast<int>(time(0)));
	std::vector<int>	copyClone(this->N);
	std::vector<int>::iterator	begin = copyClone.begin();
	std::vector<int>::iterator	end = copyClone.end();
	for (std::vector<int>::iterator ptr = begin; ptr != end; ++ptr)
	{
		addNumber(rand() % 100);
		// std::cout<<"daje "<<std::endl;
	}
	this->array = copyClone;
}
