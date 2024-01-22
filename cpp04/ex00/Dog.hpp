/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:21:39 by lnicoter          #+#    #+#             */
/*   Updated: 2024/01/22 19:57:24 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
	private:

	public:
		Dog();
		virtual ~Dog();
		Dog(const Dog& obj);
		Dog& operator=(const Dog& obj);
		void makeSound() const;
};

#endif
