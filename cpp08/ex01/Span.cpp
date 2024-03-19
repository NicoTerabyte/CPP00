/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 18:33:20 by lnicoter          #+#    #+#             */
/*   Updated: 2024/03/19 16:59:48 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

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
	int	shortest;
	int	tmpShortest;
	// int	actualNumber;

	if (this->array.size() <= 1)
		throw std::runtime_error("There are not enough elements (min 2) to calculate the shortest span");
	for (int i = 0; i < static_cast<int>(this->array.size()); i++)
	{
		for (int j = i + 1; j < static_cast<int>(this->array.size()); j++)
		{
			if (this->array[i] >= this->array[j])
				tmpShortest = this->array[i] - this->array[j];
			else
				tmpShortest = this->array[j] - this->array[i];
			if (i == 0)
				shortest = tmpShortest;
			else if (shortest > tmpShortest)
				shortest = tmpShortest;
		}
	}
	return (shortest);
}

int	Span::longestSpan()
{
	int	longest;
	int	tmpLongest;
	// int	actualNumber;

	if (this->array.size() <= 1)
		throw std::runtime_error("There are not enough elements (min 2) to calculate the shortest span");
	for (int i = 0; i < static_cast<int>(this->array.size()); i++)
	{
		for (int j = i + 1; j < static_cast<int>(this->array.size()); j++)
		{
			if (this->array[i] > this->array[j])
				tmpLongest = this->array[i] - this->array[j];
			else
				tmpLongest = this->array[j] - this->array[i];
			if (i == 0)
				longest = tmpLongest;
			else if (longest < tmpLongest)
				longest = tmpLongest;
		}
	}
	return (longest);
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
