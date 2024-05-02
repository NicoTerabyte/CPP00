/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 19:45:39 by lnicoter          #+#    #+#             */
/*   Updated: 2024/05/02 19:16:29 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/*
cose da fare per migliorare il codice:
migliorare l'algoritmo shortestspan e longest
che deve essere in grado di utilizzare metodi della libreria
algorithm per semplificare e passare il check
*/
int	main(void)
{
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	Span testIt(10000);

	testIt.allInOne();
	std::cout<< testIt.shortestSpan()<<std::endl;

	testIt.printCont();
	return (0);
}
