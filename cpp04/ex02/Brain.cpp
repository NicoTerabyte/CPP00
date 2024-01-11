/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:06:33 by lnicoter          #+#    #+#             */
/*   Updated: 2024/01/10 19:52:30 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout<<"Brain constructor called"<<std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = "This an idea";
}

Brain::~Brain()
{
	std::cout<<"Brain destructor called"<<std::endl;
}

Brain::Brain(Brain& obj)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = obj.ideas[i];
}

Brain& Brain::operator=(const Brain& obj)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = obj.ideas[i];
	return *this;
}

void Brain::setIdea(std::string newIdea, int pos)
{
	this->ideas[pos] = newIdea;
}

void Brain::printBrain()
{
	for (int i = 0; i < 100; i++)
		std::cout<<this->ideas[i]<<std::endl;
}
