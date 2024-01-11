/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:38:19 by lnicoter          #+#    #+#             */
/*   Updated: 2024/01/11 16:49:24 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	Dog bestie;
	Dog copyBestie(bestie);

	//esempio per vedere se è deepcopy
	copyBestie.setMind();
	bestie.printBrain();
	copyBestie.printBrain();
	// const Animal* cJ = j;

	delete j;//should not create a leak
	delete i;
	// delete cJ;
	return 0;
}
