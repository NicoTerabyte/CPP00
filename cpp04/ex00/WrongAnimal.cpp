/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:52:42 by lnicoter          #+#    #+#             */
/*   Updated: 2024/01/22 18:00:46 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

/*
		WrongAnimal();
		~WrongAnimal();
		WrongAnimal(WrongAnimal& obj);
		WrongAnimal& operator=(const WrongAnimal& obj);
		void makeSound(void) const;
		std::string getType(void) const;
*/

WrongAnimal::WrongAnimal()
{
	std::cout<<"WrongAnimal default constructor called"<<std::endl;
	this->type = "Unkown";
}

WrongAnimal::~WrongAnimal()
{
	std::cout<<"WrongAnimal default destructor called"<<std::endl;
}


WrongAnimal::WrongAnimal(WrongAnimal& obj)
{}
