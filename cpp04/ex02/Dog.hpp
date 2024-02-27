/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:21:39 by lnicoter          #+#    #+#             */
/*   Updated: 2024/02/27 19:57:11 by lnicoter         ###   ########.fr       */
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
		Dog(const Dog& obj);
		Dog& operator=(const Dog& obj);
		virtual void makeSound() const;
		void setMind();
		void printBrain();
};

#endif
