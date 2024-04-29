/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:47:45 by lnicoter          #+#    #+#             */
/*   Updated: 2024/04/29 18:45:04 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"


int	main(void)
{
	try
	{
		Array<int> prova(30);
		Array<int> wrong;
		wrong[5] = 7;
		prova[2] = 8;
		std::cout<<"prova stampa: "<<prova[2]<<" daje"<<std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout<<e.what()<<std::endl;
	}
}
