/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:21:39 by lnicoter          #+#    #+#             */
/*   Updated: 2024/01/10 19:59:34 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain* dogMind;
	public:
		Dog();
		virtual ~Dog();
		Dog(Dog& obj);
		Dog& operator=(const Dog& obj);
		void makeSound() const;
		void setMind();
		void printBrain();
};

#endif